#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 1000

// Prompt is as follows:
// As written, getint treats a + or - not followed by a digit as a valid 
// representation of zero. Fix it to push such a character back on the input.

int getch(void);
void ungetch(int);

void main()
{
    // tests getint; prints the int wrote to the array by getint to the screen
    int n, array[SIZE], getint(int *);

    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        printf("return: %d\n", array[n]);

    system("pause");
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign, storesign;

    //skip white space
    while (isspace(c = getch())) 
        ;

    // c is not a number
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') 
    {
        ungetch(c); 
        return 0;
    }

    // record sign, then determine if it corresponds to a number
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        storesign = c;
        // sign is not part of a number; push everything back and signal error
        if (!isdigit(c = getch()))
        {
            if (c != EOF)
                ungetch(c);
            ungetch(storesign);
            return 0;
        }
    }

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}