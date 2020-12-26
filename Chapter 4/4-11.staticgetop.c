#include <stdio.h>
#include <stdlib.h>     // for atof()
#include <ctype.h>

#define MAXOP 100       // max size of operand or operator
#define NUMBER '0'      // signal that a number was found
#define MAXVAL 100      // maximum depth of val stack

// Prompt is as follows:
// Modify getop so that it doesn't need to use ungetch. Hint: use 
// an interal static variable.

int getop(char []);

// getop: get next character or numeric operand
int getop(char s[])
{
    int i;
    static int c = ' ';   // declared so we collect input first

    // clears whitespace if necessary (c's from previous collection move ahead)
    if (c == ' ' || c == '\t')
        while ((s[0] = c = getch()) == ' ' || c == '\t')
            ;
    
    s[0] = c;   // record previously collected c's
    s[1] = '\0';

    if (!isdigit(c) && c != '.')    // proceed past hyphens
    {
        int ret = c;  // refresh c to avoid looping
        c = ' ';
        return ret;   // not a number
    }
    
    i = 0;
    if (isdigit(c)) // collect integer part
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')   // collect fraction part 
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';

    return NUMBER;
}