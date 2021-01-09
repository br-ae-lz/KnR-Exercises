#include "stdio.h"

// Prompt is as follows:
// Write a function invert(x,p,n) that returns x with the n bits that begin at
// position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged. 

unsigned invert(unsigned x, int p, int n);

int main ()
{
    // initialize a bunch of integers to test invert
    unsigned x = 100;   // 100 -> (...) 0110 0100 
    int p = 4;
    int n = 3;

    unsigned result = invert(x, p, n);

    // print the result, which should be 120
    // (...0 01.. are the bits selected from x, so x is 0111 1000 when they are inversed)
    printf("%d\n", result);

    return 0;
}

// invert: return x with n bits to the right of position p inverted
unsigned invert(unsigned x, int p, int n)
{
    // initialize an integer, then mask the bits in it that fall under the position and range 
    // specified by p and n with 1's
    unsigned y = ~(~0 << n) << p - n + 1;

    // set the bits of y in the specified range to the bits of x at that range
    y &= x;
    // invert the bits of y, letting it consist entirely of 1's with the specified range being
    // filled with the inverted bits of x at that range
    y = ~y;

    // mask the bits in x that fall under the specified range with 1's, just as was done with y
    x |= ~(~0 << n) << p - n + 1;
    // x becomes the bitwise and of itself and z -> x is the function's result, it is returned
    x &= y;
    return x;
}