#include <stdio.h>
#include <string.h>

// Prompt is as follows:
// Write a recursive version of the function reverse(s), which reverses 
// the string s in place.

void recurrev(char []);

int main()
{
    // tests recurrev; if successful, prints "dlroW olleH" to the screen
    char s[] = "Hello World\0";
    recurrev(s);
    printf("%s\n", s);

    return 0;
}

// recurrev: recursively reverse a string s
void recurrev(char s[])
{   
    char temp;
    static int i = 0;
    
    // swap the first and last characters of s, then repeat one index
    // closer to the middle; terminate after meeting or passing middle
    if (i < strlen(s)/2)
    {
        temp = s[i];
        s[i] = s[strlen(s) - 1 - i];
        s[strlen(s) - 1 - i] = temp;

        i++;
        recurrev(s);
    }
}