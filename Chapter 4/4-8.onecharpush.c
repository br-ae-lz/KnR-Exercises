#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Prompt is as follows:
// Suppose that there will never be more than one character of pushback. Modify getch and 
// ungetch accordingly.

int getch(void);
void ungetch(int);

int buf = '\0';

// getch: get a (possibly pushed-back) character
int getch(void) 
{
    int ret;
    // if buffer has contents, return and dispel them
    if (buf != '\0')
    {
        ret = buf;
        buf = '\0'; 
    }
    // otherwise return a gotten char
    else
        ret = getchar();
    return ret;
}

// ungetch: push a single character back on input
void ungetch(int c)
{
    if (buf != '\0')
        printf("ungetch: too many characters\n");
    else
        buf = c;
}