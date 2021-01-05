#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

// Prompt is as follows:
// Write versions of the library functions strncpy, strncat, and strncmp, 
// which operate on at most the first n characters of their argument strings.
// For example, strncpy(s, t, n) copies at most n characters of t to s. Full 
// descriptions are in Appendix B.

// Additional Appendix B descriptions of functions are as follows:
// strncat(s, t, n): concatenate at most n characters of string t to string s,
//                   terminate s with '\0'; return s.
// strncmp(s, t, n): compare at most n characters of string s to string t; 
//                   return <0 if s < t, 0 if s == t, or >0 if s > t.

void strncopy(char *, char *, int);
char * strncat(char *, char *, int);
int strncmp(char *, char *, int);

void main()
{
    // tests strncopy; if successful, prints "hah" to the screen
    char s1[MAXLINE] = "";
    char t1[MAXLINE] = "haha";

    strncopy(s1, t1, 3);
    printf("%s\n", s1);
    system("pause");

    // tests strncat; if successful, prints "hello" to the screen
    char s2[MAXLINE] = "hell";
    char t2[MAXLINE] = "o!";

    printf("%s\n", strncat(s2, t2, 1));
    system("pause");

    // tests strncmp; if successful, prints "0\n-10" to the screen
    char s3[MAXLINE] = "hee";
    char t3[MAXLINE] = "hoo";

    printf("%d\n", strncmp(s3, t3, 1));
    printf("%d\n", strncmp(s3, t3, 3));
    system("pause");
}

// strncopy: copy at most n characters of t to s
// (renamed from strncpy to avoid conflict with preexisting library function)
void strncopy(char *s, char *t, int n)
{
    for (; n > 0; n--)
        *s++ = *t++;
    *s = '\0';
}

// strncat: concatenate at most n characters of string t to string s, return s
char *strncat(char *s, char *t, int n)
{
    // save start of s
    char *p = s;

    // find end of s
    while (*s)
        s++;
    // concatenate n chars of t to s, then signal end of string
    for(; n > 0; n--)
        *s++ = *t++;
    *s = '\0';

    // return start of s
    return p;
}

// strncmp: compare at most n characters of string s to string t; return <0 
// if s < t, 0 if s == t, or >0 if s > t.
int strncmp(char *s, char *t, int n)
{
    // move along path towards a 0 return for as long as strings match
    for(; n > 0 && *s == *t; n--, s++, t++)
        if (*s == '\0')
            return 0;
    // if chars ever differ, return their difference
    return *s - *t;
}