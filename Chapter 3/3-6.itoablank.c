#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAXLINE 1000    // max char array length

// Prompt is as follows:
// Write a version of itoa that accepts three arguments instead of two. The third
// argument is a minimum field width; the converted number must be padded with
// blanks on the left if necessary to make it wide enough. 

// Commented copy of original function:
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

void reverse(char s[]);
void itoablank(int n, char s[], int w);

void main()
{
    // initialize a string and use it to print itoablank's output for a number when prompted
    // for a minimum width of 8 (output should include 5 blanks as padding to the left)
    char s[MAXLINE];
    itoablank(105, s, 8);
    printf("%s\n", s);

    system("pause");
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}

// itoablank: convert n to characters in s with a minimum field width
void itoablank(int n, char s[], int w)
{
    int i, sign;

    if ((sign = n) < 0)  // record sign 
        n = -n;          // make n positive 
    
    i = 0;
    do {                 // generate digits in reverse order 
        s[i++] = n % 10 + '0';   // get next digit 
    } while ((n /= 10) > 0);     // delete it 
    if (sign < 0)
        s[i++] = '-';

    while (i < w)          // pad output if necessary
        s[i++] = ' ';

    s[i] = '\0';
    reverse(s);
}