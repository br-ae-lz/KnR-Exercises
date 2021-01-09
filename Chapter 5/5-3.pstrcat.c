#include <stdio.h>

#define MAXLINE 1000

// Prompt is as follows:
// Write a pointer version of the function strcat that we showed in 
// Chapter 2: strcat(s, t) copies the string t to the end of s.

// Commented copy of original function:
// /* strcat: concatenate t to end of s; s must be big enough */
// void strcat(char s[], char t[])
// {
//     int i, j;
//     i = j = 0;
//     while (s[i] != '\0') /* find end of s */
//         i++;
//     while ((s[i++] = t[j++]) != '\0') /* copy t */
//         ;
// }

void pstrcat(char *, char *);

int main()
{
    // tests pstrcat; if successful, prints "oh my!\n" to the screen
    char as[MAXLINE] = "oh ";
    char at[MAXLINE] = "my!\n";
    char *s = as;
    char *t = at;

    pstrcat(s, t);
    printf(s);

    return 0;
}

// pstrcat: concatenate t to end of s (s must be big enough)
void pstrcat(char *s, char *t)
{
    // find end of s
    while (*s)
        s++;
    // copy t
    while (*s++ = *t++)
        ;
}