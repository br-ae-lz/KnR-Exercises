#include "stdio.h"
#include "string.h"

#define MAXLINE 1000

// Prompt is as follows:
// Write the function itob(n,s,b) that converts the integer n into a base b character 
// representation in the string s. In particular, itob(n,s,16) formats s as a hexadecimal 
// integer in s. 

void reverse(char s[]);
void itob(int n, char s[], int b);

int main()
{
    // initialize a string and use it to print itob's output for a hexadecimal number
    // (output should be -5D93E)
    char s[MAXLINE];
    itob(-383294, s, 16);
    printf("%s\n", s);
    
    return 0;
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}

// itob: convert an integer n into a base b character representation in the string s
// (tailored for use with ASCII character set, digits 0-9 are representative of themselves
// and capital letters are used for the 26 numbers following them; this fulfils the requirement
// of correctly formatting hex integers, though bases after 36 may utilise odd characters)
void itob(int n, char s[], int b)
{
    int i = 0;
    int result, sign;
    
    // record sign of number, turn number positive for calculation
    if ((sign = n) < 0)
        n = -n;

    // complete loop once to output a value of zero if necessary; check the modulo of the
    // number and the base and place an appropriate character to represent it into the
    // string, divide number by the base, and keep repeating until the number is zero
    do
    {
        // modulo value stored in variable so it does not need to be recalculated
        result = n % b;
        s[i++] = (result >= 0 && result <= 9) ? result + '0' : result + 'A' - 10;
        n /= b;
    } while (n != 0);

    // if negative sign need be included, do so
    if (sign < 0)
        s[i++] = '-';
    // top off string with null character, reverse output characters for accuracy
    s[i] = '\0';
    reverse(s);
}