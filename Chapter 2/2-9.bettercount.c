#include "stdio.h"
#include "stdlib.h"

// Question prompt is as follows:
// In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
// in x. Explain why. Use this observation to write a faster version of bitcount. 

// The given operation always deletes the rightmost 1-bit in x -> upon subtracting 1
// from x, the rightmost 1-bit will become 0 and every bit to the right of it (if there
// are any) will become 1. All of these values conflict with x's, so the bitwise AND
// replaces all of these bits with 0. Thus, the rightmost 1-bit is now 0.

// as bitcount runs as a loop which continuously checks if every rightmost bit is a 1
// until there are no 1's left, we can utilise this operation to create a bettercount
// which only loops for however many 1-bits are in a number...

int bettercount(unsigned x);

void main() 
{
    // initialize an integer to test out bettercount
    unsigned x = 11;    // 11 -> (...) 1011

    // run bettercount and print its result, which should be 3
    printf("%d\n", bettercount(x));

    system("pause");

}

 // bettercount: count 1 bits in x
 int bettercount(unsigned x)
 {
    int b;
    // on each loop: delete the rightmost 1-bit from x, iterate b; when x is 0, return b
    for (b = 0; x != 0; x &= (x - 1))
        b++;
    return b;
 }