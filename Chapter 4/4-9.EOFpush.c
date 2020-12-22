#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Prompt is as follows:
// Our getch and ungetch do not handle a pushed-back EOF correctly. Decide what their 
// properties ought to be if an EOF is pushed back, then implement your design.

// (It turns out that getch and ungetch, by default, DO handle a pushed-back EOF value on my
// machine. EOF, as defined in stdio.h, cannot fit into a char, but the way my compiler handles
// chars and type conversions truncate it to fit properly into a char. Regardless, a pushed-back 
// EOF should theoretically fit in the buffer just as any other character would, and so, the buffer 
// should be initialized as an integer array rather than a char array.)

int getch(void);
void ungetch(int);

#define BUFSIZE 100
// buf is now an integer array (and can hold EOFs)
int buf[BUFSIZE]; /* buffer for ungetch */
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