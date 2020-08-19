#include "stdio.h"
#include "stdlib.h"

// Prompt is as follows:
// Write a function rightrot(x,n) that returns the value of the integer x rotated
// to the right by n positions. 

unsigned rightrot (unsigned x, int n);

void main ()
{
    // initialize some integers to test rightrot
    // 2623091161 -> 1001 1100 0101 1001 0011 0001 1101 1001
    unsigned x = 2623091161;
    int n = 3;

    // print the result (and the result fully rotated once), which should be 864757307
    // (bits shifted to the right are 001... the 3 least significant bits of x disappear
    // and these are added to the front -> 0011 0011 1000 1011 0010 0110 0011 1011)
    unsigned result = rightrot(x, n);
    printf("%u\n", result);
    result = rightrot(x, n + 32);
    printf("%u\n", result);

    system("pause");
}

// rightrot: returns x with its bits rotated to the right by n positions (wraps around
// from least significant bit to most significant bit)
// (assumes the integer is 32 bits -> could count to verify, but i didn't do that here)
unsigned rightrot (unsigned x, int n)
{
    // ensure n does not exceed the number of bits in the integer
    // (will otherwise lead to a negative bit shift; although my compiler will give the
    // same answers to these, it is deemed undefined behaviour, so i'll avoid it)
    n = n % 32;

    // initialize an integer that holds the least n significant bits of x at the most
    // significant n positions (mask least n bits with 1's, copy from x, then shift left)
    unsigned y = (x & ~(~0 << n)) << 32 - n;
    // shift x to the right n positions
    x = x >> n;
    // fill the n most significant bits in x (now 0's) with y's contents, return result
    x ^= y;
    return x;
}