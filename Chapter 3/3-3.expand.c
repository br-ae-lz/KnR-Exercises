#include "stdio.h"

#define MAXLINE 1000   // max char array length

// Prompt is as follows:
// Write a function expand(s1,s2) that expands shorthand notations like a-z in the string s1 
// into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits,
// and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or 
// trailing - is taken literally.

void expand(char s1[], char s2[]);

int main()
{
    // declare variables to use in testing expand()
    char s1[MAXLINE], s2[MAXLINE];
    int i, c;

    // accept input from the user which terminates when they advance to a new line, follow by
    // running expand on the input string and printing the output string
    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != '\n'; i++)
        s1[i] = c;
    s1[i] = '\0';

    expand(s1, s2);
    printf("%s\n", s2);

    return 0;
}

// expand: whenever two characters are hyphenated in the input, insert every character lying
// between them (as dictated by the character set) in place of the hyphen
// (works best for ASCII character set, where alphanumeric character ids' are grouped together)
void expand(char s1[], char s2[])
{
    // initialize variable to track position in the output string
    int j = 0;

    // the main loop; copy contents of input to output except for when an element needs expanding
    for (int i = 0; s1[i] != '\0' && j < MAXLINE - 1; i++)
    {
        // if an expansion is needed, then do so by including all elements of the character set 
        // between the two listed
        if (s1[i] == '-')
            for (int pos = s1[i-1] + 1; pos <= s1[i+1] - 1; pos++)
                s2[j++] = pos;
        else
            s2[j++] = s1[i];
    }
    // cap off output with null character, making it a string
    s2[j] = '\0';
}
