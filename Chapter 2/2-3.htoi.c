#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "ctype.h"
#define MAXCHAR 1000    //limit for character entry

// Prompt is as follows:
// Write a function htoi(s), which converts a string of hexadecimal digits
// (including an optional 0x or 0X) into its equivalent integer value. The
// allowable digits are 0 through 9, a through f, and A through F. 

long htoi(char s[]);

void main()
{
    // initializes a long integer to hold the eventual output of the htoi function
    long result;
    // initializes two integers and a character array...
    int c, i;
    char s[MAXCHAR];
    // ...and subsequently asks the user for a string which is filed from one integer to
    // be stored in the character array
    for (i = 0; i < MAXCHAR && (c = getchar()) != '\n'; i++)
        s[i] = c;
    // turns the input character array into a string by bestowing upon it a null character
    s[i] = '\0';
    // runs the inputted string through the htoi function, storing the result in a long
    result = htoi(s);
    // outputs the long returned from the htoi function
    printf("%d\n", result);
    system("pause");
}

// htoi: convert an input string of hexadecimal digits (optionally prefaced by 0x or 0X) into
// an equivalent integer value (decimal form)
long htoi(char s[])
{
    // initializes an integer to keep track of the current place in the input string
    int i = 0;
    // initializes a long to be returned by the function when it has reached its
    // conclusion
    long returnlong = 0;
    // initializes an integer to hold the length of the input string
    int length = strlen(s);
    // initializes an integer to verify whether the input is negative
    int negcheck = 0;

    // runs the first check to determine if the input is negative; this concerns what
    // is at the VERY start of the string, at position 0
    if(s[i] == '-')
    {
        negcheck++;
        i++;
    }
    // examines the input string to determine whether or not it is headlined with a "0x" 
    // or "0X"; if such is the case, acts accordingly to disregard this
    if(s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X'))
        i = i + 2;
    // runs the second check to determine if the input is negative; this only occurs if the
    // first check was passed or the input string is headlined with a "0x" or "0X"
    if (s[i] == '-' && i >= 1 && i <= 3)
    {
        negcheck++;
        i++;
    }
    // perhaps a bit too specific of an error, but i thought it best to include it nonetheless; 
    // if there are multiple signs present to indicate the negativity of the input, the input is 
    // rejected with an error stating so
    // (the one exception is when something like "0x--" precedes the rest of the input, as this
    // requires both negative checks to succeed... no harm done though, still gives an error!)
    if(negcheck == 2)
    {
        printf("htoi [ERROR]: two or more signs detected; syntax unrecognised\n");
        return 0;
    }

    // loop which runs through the input string to convert the hexadecimal input to decimal form
    // (assumes the ASCII character set is in use)
    for(i; s[i] != '\0'; i++)
    {
        // if the current character is a digit 0 through 9, calculate its value in decimal form
        // and add it to the return variable 
        // (character's value is subtracted by 48 to align it with its numerical value in the 
        // character set, length is subtracted by 1 to calculate with accurate powers of 16)
        if((s[i] - 48) >= 0 && (s[i] - 48) <= 9)
            returnlong = returnlong + pow(16, length - i - 1)*(s[i] - 48);
        // if the current character is a lowercase or uppercase letter, calculate its value in
        // decimal form and add it to the return variable
        // (lowercase characters are converted to uppercase to maintain consistency in matching
        // numerical values in the character set -> character's value is subtracted by 55 to align
        // it with its numerical value in the character set, length is subtracted by 1 to 
        // calculate with accurate powers of 16)
        else if((s[i] >= 97 && s[i] <= 102) || (s[i] >= 65 && s[i] <= 70))
        {
            s[i] = toupper(s[i]);
            returnlong = returnlong + pow(16, length - i - 1)*(s[i] - 55);
        }
        // if the current character is invalid, explicitly say so and return a preset value
        else
        {
            printf("htoi [ERROR]: one or more invalid input characters\n");
            return 0;
        }

    }

    // if the input previously passed a negative check, make the return integer negative
    if(negcheck == 1)
    {
        returnlong = -returnlong;
    }

    //if all went well, return the return integer
    return returnlong;
}