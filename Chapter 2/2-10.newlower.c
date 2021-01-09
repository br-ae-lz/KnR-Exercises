#include "stdio.h"

// Prompt is as follows:
// Rewrite the function lower, which converts upper case letters to lower case,
// with a conditional expression instead of if-else. 

int newlower(int c);

int main()
{
    // test newlower by feeding it a 'C' (should print as 'c')
    printf("%c\n", newlower('C'));

    return 0;
}

 // newlower: convert c to lower case; ASCII only
 int newlower(int c)
 {
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
 }
