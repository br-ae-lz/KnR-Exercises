#include "stdio.h"
#include "stdlib.h"

// Prompt is as follows:
// Rewrite the function lower, which converts upper case letters to lower case,
// with a conditional expression instead of if-else. 

int newlower(int c);

void main()
{
    // test newlower by feeding it a 'C' (should print as 'c')
    printf("%c\n", newlower('C'));

    system("pause");
}

 // newlower: convert c to lower case; ASCII only
 int newlower(int c)
 {
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
 }
