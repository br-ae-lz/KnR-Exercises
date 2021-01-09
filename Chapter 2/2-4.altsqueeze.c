#include "stdio.h"

// Prompt is as follows:
// Write an alternative version of squeeze(s1,s2) that deletes each character in
// s1 that matches any character in the string s2. 

void altsqueeze(char s1[], char s2[]);

int main()
{
    // initialize some strings to test altsqueeze
    char s1[] = "oh, what a nice day\0";
    char s2[] = "a h,\0";

    // print the input strings and the results of running altsqueeze
    printf("first string: %s\nsecond string: %s\n", s1, s2);
    altsqueeze(s1, s2);
    printf("result: %s\n", s1);

    return 0;
}

// altsqueeze: delete all characters included in s2 from s1
void altsqueeze(char s1[], char s2[])
{
    int i, j;

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

    // compare characters in the holding array to the character in s1; if a match, don't use
    for (i = j = 0; s1[i] != '\0'; i++)
        if (s1[i] != allchar[s1[i] + 128])
            s1[j++] = s1[i];
            
    // finish string
    s1[j] = '\0';
}
