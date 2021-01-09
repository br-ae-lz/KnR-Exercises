#include "stdio.h"
#include "string.h"
#include "math.h"

#define MAXLINE 1000    // max char array length

void reverse(char s[]);
void itoah(int n, char s[]);   
void itoall(int n, char s[]);   

// Prompt is as follows:
// Exercise 3-4. In a two's complement number representation, our version of itoa does not
// handle the largest negative number, that is, the value of n equal to -(2^(wordsize-1)). Explain
// why not. Modify it to print that value correctly, regardless of the machine on which it runs. 

// Original itoa function is written below, renamed to itoah.

// The reason why the original version of itoa cannot handle the largest negative number is that the
// range of signed integral variables (when represented in two's complement) is one number further
// from zero on the negative end than on the positive one. (For example, an 8-bit signed integer's
// values can range from -128 to 127; there is no +128.) This version of itoa converts negative inputs
// to positive values before progressing, yet there is no positive counterpart of such an input.

int main()
{
    // declare and initialize variables to test out original itoa and new itoall; specifically, n is
    // the largest negative number that can be held in an integer, so itoa should fail with it
    int n = -pow(2, 32-1);
    char s[MAXLINE];

    // print n, run itoa and show its result, then run itoall and show its result
    printf("n: %d\n", n);
    itoah(n, s);
    printf("itoa output: %s\n", s);
    itoall(n, s);
    printf("itoall output: %s\n", s);
    
    return 0;
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}

/* itoa: convert n to characters in s */
// (renamed to itoah to avoid conflict with the stdlib function itoa)
void itoah(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    i = 0;
    do {                 /* generate digits in reverse order */
        s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

// itoall: convert n to characters in s (+1!)
void itoall(int n, char s[])
{
    int i, sign;
    int extra = 0;

    if ((sign = n) < 0)  // record sign
        if (-n < 0)      // make n positive (extra, n is +1 for now)
            {
            extra = 1; 
            n = -++n;
            }
        else
            n = -n;      // make n positive (no extra)

    i = 0;
    do {                         // generate digits in reverse order 
        s[i++] = n % 10 + '0';   // get next digit
    } while ((n /= 10) > 0);     // delete it
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';

    if(extra)           // if there was extra, s's version of n becomes original value
        s[0] += 1;
    reverse(s);
}