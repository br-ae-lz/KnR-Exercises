#include "stdio.h"

#define ARRAYLENGTH 20

// Prompt is as follows:
// Our binary search makes two tests inside the loop, when one would suffice (at the price
// of more tests outside). Write a version with only one test inside the loop and measure
// the difference in run-time. 

int binsearch(int x, int v[], int n);
int newbinsearch(int x, int v[], int n);

int main()
{
    // initialize a variable and an array to test (and time?) the binsearch functions
    int x = 2;
    int v[ARRAYLENGTH] = {1, 1, 1, 1, 1, 2, 3, 6, 10, 11, 11, 12, 15, 17, 18, 19, 20, 22, 25, 29};

    // run binsearch and its revised counterpart 2000 times each to (inefficiently and
    // indeterminately) examine the difference in their run-times
    // (on my machine, it's incredibly difficult to see a difference with how quickly things go;
    // nevertheless, I believe newbinseach is *just* visibly faster with this setup)
    for (int i = 0; i < 2000; i++)
        printf("%d\n", binsearch(x, v, ARRAYLENGTH));
    printf("done old!\n");
    for (int i = 0; i < 2000; i++)
        printf("%d\n", newbinsearch(x, v, ARRAYLENGTH));
    printf("done new!\n");

    return 0;
}

// binsearch: find x in v[0] <= v[1] <= ... <= v[n-1]
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high)/2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else // found match
            return mid;
    }
    return -1; // no match
}

// newbinsearch: find x in v[0] <= v[1] <= ... <= v[n-1] (but newer!)
int newbinsearch(int x, int v[], int n)
{
    // aw yeah, variable declaration + initialization
    int low, high, mid;
    low = 0;
    high = n - 1;
    mid = (low+high)/2;

    // check if x is already equal to mid by default -> if so, return right there
    if (x == v[mid])
        return mid;
    // revised loop which will only check for a match once it is broken (when low = high)
    while (low < high) 
    {
        mid = (low+high)/2;
        if (x <= v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    // now verifies if a match is found by examining low -> mid didn't update before the
    // loop broke, but it would have become equal to low and high
    if (x == v[low])
        return low;
    // if the number low and high settled on was not x, it is not in the array; ERROR!
    return -1; 
}