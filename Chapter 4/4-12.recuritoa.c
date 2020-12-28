#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

// Prompt is as follows:
// Adapt the ideas of printd to write a recursive version of itoa; that 
// is, convert an integer into a string by calling a recursive routine.

void recuritoa(int, char[]);

void main()
{
    // tests recuritoa; if successful, prints -2209534 to the screen
    int n = -2209534;
    char s[MAXLEN];

    recuritoa(n, s);
    printf("%s\n", s);

    system("pause");
}

// recuritoa: recursively convert n to characters in s
void recuritoa(int n, char s[])
{
    static int i = 0;   // tracks s index
    
    // adds sign if necessary
    if (n < 0)
    {
        s[i++] = '-';
        n = -n;
    } 
    
    // recursively chops off the last digit of n until it is only one digit
    if (n / 10)
        recuritoa(n / 10, s);

    // records all digits of n, starting from the most significant, in s
    // (moving the end of string char as necessary)
    s[i++] = n % 10 + '0';
    s[i] = '\0';
}