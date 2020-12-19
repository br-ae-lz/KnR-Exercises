#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Prompt is as follows:
// Write a routine ungets(s) that will push back an entire string onto the input. Should ungets know 
// about buf and bufp, or should it just use ungetch?
// (I figured that ungets should use ungetch to keep things simple.)

int getch(void);
void ungetch(int);
void ungets(char []);

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

// ungets: push string back on input
void ungets(char s[])
{
    for (int i = strlen(s) - 1; i >= 0; i--)
        ungetch(s[i]);
}