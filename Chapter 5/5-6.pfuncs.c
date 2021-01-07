#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Prompt is as follows:
// Rewrite appropriate programs from earlier chapters and exercises with 
// pointers instead of array indexing. Good possibilities include getline 
// (Chapters 1 and 4), atoi, itoa, and their variants (Chapters 2, 3, and 4), 
// reverse (Chapter 3), and strindex and getop (Chapter 4).


// Commented copy of original getline:
// /* getline: read a line into s, return length */
// int getline(char s[],int lim)
// {
//     int c, i;
//     
//     for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
//         s[i] = c;
//     if (c == '\n') 
//     {
//         s[i] = c;
//         ++i;
//     }
//     s[i] = '\0';
//     return i;
// }

// pgetline: read a line into s, return length
int pgetline(char *s, int lim)
{
    int c, i;
    
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; i++, s++)
        *s = c;
    if (c == '\n') 
    {
        *s++ = c;
        ++i;
    }
    *s = '\0';
    return i;
}


// Commented copy of original atoi:
// /* atoi: convert s to integer; version 2 */
// int atoi(char s[])
// {
//     int i, n, sign;
//
//     for (i = 0; isspace(s[i]); i++) /* skip white space */
//         ;
//     sign = (s[i] == '-') ? -1 : 1;
//     if (s[i] == '+' || s[i] == '-') /* skip sign */
//         i++;
//     for (n = 0; isdigit(s[i]); i++)
//         n = 10 * n + (s[i] - '0');
//     return sign * n;
// }

// patoi: convert s to integer; pointer version 2
int patoi(char *s)
{
    int n, sign;

    while (isspace(*s)) /* skip white space */
        s++;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-') /* skip sign */
        s++;
    for (n = 0; isdigit(*s); s++)
        n = 10 * n + (*s - '0');
    return sign * n;
}


// Commented copy of original itoa:
// /* itoa: convert n to characters in s */
// void itoa(int n, char s[])
// {
//     int i, sign;
//     if ((sign = n) < 0)  /* record sign */
//         n = -n;          /* make n positive */
//     i = 0;
//     do {                 /* generate digits in reverse order */
//         s[i++] = n % 10 + '0';   /* get next digit */
//     } while ((n /= 10) > 0);     /* delete it */
//     if (sign < 0)
//         s[i++] = '-';
//     s[i] = '\0';
//     reverse(s);
// }

// pitoa: convert n to characters in s
void pitoa(int n, char *s)
{
    int sign;
    char *p = s;

    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    do {                 /* generate digits in reverse order */
        *s++ = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    preverse(p);
}


// Commented copy of original reverse:
// /* reverse: reverse string s in place */
// void reverse(char s[])
// {
//     int c, i, j;
//
//     for (i = 0, j = strlen(s)-1; i < j; i++, j--) 
//     {
//         c = s[i];
//         s[i] = s[j];
//         s[j] = c;
//     }
// }

// reverse: reverse string s in place 
void preverse(char *s)
{
    int c;
    char *p = s;
    s += strlen(s) - 1;

    while (s != p) 
    {
        c = *p;
        *p++ = *s;
        *s-- = c;
    }
}


// Commented copy of original strindex:
// /* strindex: return index of t in s, -1 if none */
// int strindex(char s[], char t[])
// {
//     int i, j, k;
//
//     for (i = 0; s[i] != '\0'; i++) 
//     {
//         for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
//             ;
//         if (k > 0 && t[k] == '\0')
//             return i;
//     }
//     return -1;
// }

// pstrindex: return index of t in s, -1 if none
int pstrindex(char *s, char *t)
{
    int i;
    char *p, *q;
    // save first pos of t for future reference
    q = t;

    // for each pos of s, check if all chars ahead match with t; if so, return
    // current s pos if chars have been checked (t is past its first pos)
    for (i = 0; *s != '\0'; i++, s++) 
    {
        for (p = s, t = q; *t !='\0' && *p == *t; p++, t++)
            ;
        if (q != t && *t == '\0')
            return i;
    }
    return -1;
}


// Commented copy of original getop:
// /* getop: get next character or numeric operand */
// int getop(char s[])
// {
//     int i, c;
//
//     while ((s[0] = c = getch()) == ' ' || c == '\t')
//         ;
//     s[1] = '\0';
//     if (!isdigit(c) && c != '.')
//         return c; /* not a number */
//     i = 0;
//     if (isdigit(c)) /* collect integer part */
//         while (isdigit(s[++i] = c = getch()))
//             ;
//     if (c == '.') /* collect fraction part */
//         while (isdigit(s[++i] = c = getch()))
//             ;
//     s[i] = '\0';
//     if (c != EOF)
//         ungetch(c);
//     return NUMBER;
// }

// pgetop: get next character or numeric operand
int pgetop(char *s)
{
    int i, c;

    while ((*s = c = getch()) == ' ' || c == '\t')
        ;
    *++s = '\0';
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    s--;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(*++s = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(*++s = c = getch()))
            ;
    *s = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}