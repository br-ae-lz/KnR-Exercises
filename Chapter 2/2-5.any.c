#include "stdio.h"
#include "stdlib.h"

// Prompt is as follows:
// Write the function any(s1,s2), which returns the first location in a string s1 where
// any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
// (The standard library function strpbrk does the same job but returns a pointer to the
// location.) 

int any(char s1[], char s2[]);

void main()
{
    // initialize some strings to test any
    char s1[] = "ah, what a life to live\0";
    char s2[] = "v\0";

    // print the input strings and the index value spat out by any
    printf("first string: %s\nsecond string: %s\n", s1, s2);
    int result = any(s1, s2);
    printf("result: %d\n", result);

    system("pause");
}

// any: return the first location in a string where any character from another occurs
int any(char s1[], char s2[])
{
    int i;

    // declare "holding" character array to hold every character s2 may use
    char allchar[256];
    
    // nullify interference of garbage values by prefilling array
    allchar[0] = 1;
    for (int i = 1; i <= 255; i++)
        allchar[i] = 0;

    // file all characters in s2 into their respective positions in the holding array
    // (input character + 128 to avoid negative array indices, don't know what those do yet)
    for (i = 0; s2[i] != '\0'; i++)
        allchar[s2[i] + 128] = s2[i];

    // compare characters in the holding array to the character in s1; if a match, return
    // the current index
    for (i = 0; s1[i] != '\0'; i++)
        if (s1[i] == allchar[s1[i] + 128])
            return i;

    // if there are no character matches, return an impossible result (-1)
    return -1;

}
