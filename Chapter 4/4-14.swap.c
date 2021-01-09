#include <stdio.h>
#include <string.h>

// Prompt is as follows:
// Define a macro swap(t,x,y) that interchanges two arguments of type t. 
// (Block structure will help.)

// swap(t,x,y): swaps two arguments of type t
#define swap(t,x,y)\
{\
t temp = x;\
x = y;\
y = temp;\
}

int main()
{
    // tests swap when x and y are of type int; if successful, prints that "x = 2, y = 1"
    int x = 1;
    int y = 2;

    swap(int, x, y);
    printf("x = %d, y = %d\n", x, y);
    
    return 0;
}