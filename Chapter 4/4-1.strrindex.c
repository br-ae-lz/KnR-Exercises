#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAXLINE     // max char array length

// Prompt is as follows:
// Write the function strindex(s,t) which returns the position of the rightmost occurrence
// of t in s, or -1 if there is none. 

int strrindex(char s[], char t[]);

void main()
{
    // initialize some strings to test strrindex with
    char s[MAXLINE] = "here's hoping this ends up working!\0";
    char t[MAXLINE] = "ing\0";

    // print out the strings above, then test strrindex using them and print output
    // (should be 31)
    printf("searched string: \"%s\", string to search for: \"%s\"\n", s, t);
    printf("strrindex output: %d\n", strrindex(s, t));

    system("pause");
}

// strrindex: return index of rightmost instance of t in s, -1 if none
int strrindex(char s[], char t[])
{
    int i, j, k;
    // start searching for matches at the end of the string, and count backwards through
    // both strings simultaneously; if they match to the start of t, then return the index
    // that the matching starts at in s when it is viewed from left -> right
    for (i = strlen(s) - 1; s[i] != '\0'; i--) {
        for (j=i, k = strlen(t) - 1; t[k]!='\0' && s[j]==t[k]; j--, k--)
            ;
        if (k == -1)
        {
            return i - strlen(t)+1;
        }
    }
    return -1;
}