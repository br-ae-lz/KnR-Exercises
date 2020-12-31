#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

// Prompt is as follows:
// Write the function strend(s, t) which returns 1 if the string t occurs 
// at the end of the string s, and zero otherwise.

int strend(char *, char *);

void main()
{
    // tests strend; if successful, prints "1" to the screen
    char *s = "all long strings must come to an end";
    char *t = "end";

    printf("%d\n", strend(s, t));

    system("pause");
}


int strend(char *s, char *t)
{
    // find end of s, then point to where t should start if true
    while(*s)
        s++;
    s -= strlen(t);

    // iterate and compare strings; true if they match until a value of zero
    while (*s++ == *t++)
        if (!*s)
            return 1;
    return 0;
}