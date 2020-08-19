#include "stdio.h"
#include "stdlib.h"

// Prompt is as follows:
// Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
// position p set to the rightmost n bits of y, leaving the other bits unchanged. 

unsigned setbits(unsigned x, int p, int n, unsigned y);

void main ()
{
    // initialize a bunch of integers to test setbits
    unsigned x = 100;   // 100 -> (...) 0110 0100 
    unsigned y = 5;     // 5 ->   (...) 0101
    int p = 4;
    int n = 3;

    unsigned result = setbits(x, p, n, y);

    // print the result, which should be 116...
    // (.101 are the bits selected from y, they fit into x at ...0 01.. , so x is 0111 0100)
    printf("%d\n", result);

    system("pause");
}

// setbits: return x with n bits to the right of position p set to the rightmost n bits of y
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    // initialize a integer that consists only of 1's in the position and range specified by
    // p and n, 0's everywhere else
    unsigned z = ~(~0 << n) << p - n + 1;

    // masks the bits in x that fall under the specified range with 1's
    x |= z;

    // z's mask has the first bits of y which fill the range copied into it, though complements
    // are taken so that the 0's outside the range are now 1's
    z = ~(z & ~(y << p - n + 1));

    // x becomes the bitwise and of itself and z -> x is the function's result, it is returned
    x &= z;
    return x;
}