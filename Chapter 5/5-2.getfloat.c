#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define SIZE 1000

// Prompt is as follows:
// Write getfloat, the floating-point analog of getint. What type does 
// getfloat return as its function value?

// (As getfloat merely deals with input characters while writing the final value where 
// it is ordered to, c may remain the return variable. As such, the type of getfloat's
// function value is int.)

int getch(void);
void ungetch(int);

int main()
{
    // tests getfloat; prints the float wrote to the array by getfloat to the screen
    int n, getfloat(float *);
    float array[SIZE];

    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
        printf("return: %.3f\n", array[n]);

    return 0;
}

/* getint: get next integer from input into *pn */
int getfloat(float *pn)
{
    int c, sign, storesign;

    // skip white space
    while (isspace(c = getch())) 
        ;

    // c is not a number
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') 
    {
        ungetch(c); 
        return 0;
    }

    // if decimal does not correspond to a number, push everything back and signal error
    if (c == '.')
    {
        if (!isdigit(c = getch()))
        {
            if (c != EOF)
                ungetch(c);
            ungetch('.');
            return 0;
        }
        // otherwise, reset buffer and c, then move on
        ungetch(c);
        c = '.';
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

    // collect integer part
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    // collect decimal part
    if (c == '.')
        for(int i = 1; isdigit(c = getch()); i++)
            *pn += (c - '0')/(pow(10, i));

    // push back final char, then return
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