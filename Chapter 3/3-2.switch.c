#include "stdio.h"
#include "conio.h"  // non-standard header
#define MAXLINE 1000

// Prompt is as follows:
// Write a function escape(s,t) that converts characters like newline and tab into visible
// escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a
// function for the other direction as well, converting escape sequences into the real characters. 

// In escape, the only characters that are escaped are \n and \t; anything else is either not a 
// feasible input or may not need to be escaped in the first place (would just be an added \).
// In altescape, \\, \?, \', and \" are converted along with \n and \t... Because why not?

// I made use of a non-standard header here, conio.h, to pass getch() in the initial prompt which
// determines which function the user would like to test. I chose to do this because I couldn't find
// any standard function which passes an input from the console immediately, and although I could
// use a workaround to make things work without immediate input, I wanted to experiment a bit. It
// should be noted that this is not a standard-adhering practice and should be avoided for portability!

void escape(char s[], char t[]);
void altescape(char s[], char t[]);

int main()
{
    // initializing some variables which will be of use in testing escape and altescape
    char s[MAXLINE], t[MAXLINE];
    int c, i;

    // program gives decision to test escape or altescape, with the result being dictated by a switch
    // statement processing the input; if the response is valid, ask the user for input, run the function,
    // then print the output, otherwise end the program
    printf("Input 0 to test escape, 1 to test altescape.\n");
    switch (getch()) {
        case '0':
            printf("Enter your input. (End with EOF)\n");
            for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF; i++)
                t[i] = c;
            t[i] = '\0';
            escape(s, t);
            printf("Output: %s\n", s);
            break;
        case '1':
            printf("Enter your input. (End with EOF)\n");
            for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF; i++)
                t[i] = c;
            t[i] = '\0';
            altescape(s, t);
            // (newline after output omitted here because user would have already entered one before EOF)
            printf("Output: %s", s);
            break;
        default:
            printf("That input isn't recognised! Exiting...\n");
            break;
    }
    return 0;
}

// escape: convert newlines and tabs in the input string into visible escape sequences (\n and \t)
void escape(char s[], char t[])
{
    // initialize variable to track position in s[]
    int j = 0;
    
    // if a newline or tab show up in the input, copy them to the output in two characters: a backslash
    // and appropriate letter (ensure this addition of one character doesn't exceed array length)
    for (int i = 0; j < MAXLINE - 1 && t[i] != '\0'; i++)
    {
        switch(t[i]) {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        default:
            s[j++] = t[i];
            break;
        }
    }
    // if boundaries were pushed and j *barely* made it over the array's length by a newline or tab,
    // ensure the null character takes the place of the last character to stay in bounds
    if (j == MAXLINE)
        j--;
    // top off string with null character
    s[j] = '\0';
}

// altescape: convert visible escape sequences in the input string into the characters they reference
void altescape(char s[], char t[])
{
    // initialize variable to track position in s[]
    int j = 0;
    
    // if a backslash shows up in the input, verify if a suitable escape character is attached to it; if
    // so, add this character to the output and skip ahead, if not, copy all to output as with anything else
    for (int i = 0; t[i] != '\0'; i++)
    {
        if(t[i] == '\\')
        {
            i++;
            switch(t[i]) {
            case '\\':
                s[j++] = '\\';
                break;
            case '?':
                s[j++] = '?';
                break;
            case '\'':
                s[j++] = '\'';
                break;
            case '"':
                s[j++] = '"';
                break;
            case 'n':
                s[j++] = '\n';
                break;
            case 't':
                s[j++] = '\t';
                break;
            default:
                s[j++] = t[--i];
                break;
            }
        }
        else
            s[j++] = t[i];
    }
    // (no checking of boundaries here because output will either be shorter than or equal to input)
    // top off string with null character
    s[j] = '\0';
}