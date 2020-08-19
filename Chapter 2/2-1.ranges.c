#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "float.h"
#include "math.h"

// Prompt is as follows:
// Write a program to determine the ranges of char, short, int, and long variables, both signed 
// and unsigned, by printing appropriate values from standard headers and by direct computation. 
// Harder if you compute them: determine the ranges of the various floating-point types. 

void header (void);
void computation (void);

void main()
{
	// run header and computation functions for comparison
	printf("header:\n");
	header();
	printf("\n\n");
	printf("computation:\n");
	computation();
	
	system("pause");
}

// header: determine the ranges of char, short, int, long (signed and unsigned), float, and double
// by printing values from standard headers, output them to the screen
void header (void)
{
	// prints the range of a char from least to greatest, then prints its unsigned range
	// (size of 8 bits)
	printf("char range: %d to %d, thus unsigned range is 0 to %u\n", SCHAR_MIN, SCHAR_MAX, UCHAR_MAX);
	// prints the range of a short integer from least to greatest, then prints its unsigned range
	// (size of 16 bits)
	printf("short range: %d to %d, thus unsigned range is 0 to %u\n", SHRT_MIN, SHRT_MAX, USHRT_MAX);
	// prints the range of an integer from least to greatest, then prints its unsigned range
	// (size of 32 bits)
	printf("integer range: %d to %d, thus unsigned range is 0 to %u\n", INT_MIN, INT_MAX, UINT_MAX);
	// prints the range of a long integer from least to greatest, then prints its unsigned range
	// (size of 32 bits)
	printf("long range: %d to %d, thus unsigned range is 0 to %u\n", LONG_MIN, LONG_MAX, ULONG_MAX);
	// prints the range of a single-precision float from least to greatest, then prints its unsigned range
	// (size of 32 bits, not easily visible like others because of the imprecision of floating point arithmetic)
	printf("float range: %.3f to %.3f, no unsigned form\n", -FLT_MAX, FLT_MAX);
	// prints the range of a double-precision float from least to greatest, then prints its unsigned range
	// (size of 64 bits, not easily visible like others because of the imprecision of floating point arithmetic)
	printf("double range: %.3f to %.3f, no unsigned form\n", -DBL_MAX, DBL_MAX);
}

// computation: determine the ranges of char, short, int, and long (signed and unsigned) by 
// direct computation of these values, output them to the screen
void computation (void)
{
	// char variable declaration
	char char_min, char_max;
	unsigned char uchar_max;
	// short integer variable declaration
	short short_min, short_max;
	unsigned short ushort_max;
	// integer variable declaration
	int int_min, int_max;
	unsigned int uint_max;
	// long integer variable declaration
	long long_min, long_max;
	unsigned long ulong_max;
	// float variable declaration (+1 initialization)
	float float_min, float_max;
	float_min = 0;
	// double variable declaration (+1 initialization)
	double double_min, double_max;
	double_min = 0;
	// misc. declaration + initialization
	int power = 0;
	float infinitycheck;
	double limitcheck = 1;
	
	// determine the min and max values of each variable by continuously incrementing them until
	// they overflow; once this happens, determine the range between these variables to acknowledge
	// their unsigned ranges
	// (char's calculations)
		for (char_max = 0; char_max <= 0; char_max--);
		char_min = char_max + 1;
		uchar_max = char_max - char_min;
	// (short's calculations)
		for (short_max = 0; short_max <= 0; short_max--);
		short_min = short_max + 1;
		ushort_max = short_max - short_min;
	// (int's calculations)
		for (int_min = 0; (int_min - 1) < int_min; int_min--);
		int_max = int_min - 1;
		uint_max = int_max - int_min;
	// (long's calculations)
		for (long_min = 0; (long_min - 1) < long_min; long_min--);
		long_max = long_min - 1;
		ulong_max = long_max - long_min;
	
	// since float variables take on a value representing infinity instead of overflowing,
	// a different strategy is taken...
	// these variables can hold some very large values, and due to the magic of floating point 
	// arithmetic, these values grow further apart as we move away from zero; decrementing each
	// by 1 until a limit is reached would not only take obscene amounts of time, but is also
	// literally impossible, as the values would eventually be so far apart that attempting to
	// decrement them by 1 would just reproduce the operand.
	// to nullify this, i attempt to decrease the value of the variable by powers of two starting
	// from zero. the calculation takes less time and it is certain that a limit (where the power of
	// two cannot be raised without having the variable reach infinity and where the variable cannot
	// be decreased by the current power without reproducing a value due to imprecision) will be reached. 
	// i use isinf() to check if the current calculation will reach infinity; if so, the power of two is
	// decreased, and if not, it is increased. limitcheck checks to see if a point where the variable
	// cannot be decremented any further (without reaching infinity) has been reached. the variable
	// will be caught in a loop of having its value reproduced in such a case; it will equal limitcheck
	// at this point, and so, the loop will break. when this happens, the variable has reached its minimum.
	// (float's calculations)
	while (float_min != limitcheck)
	{
		// (infinitycheck accounts for weird behaviour between the isinf() function and floats, which i
		// suspect is due to isinf() specifically checking if a double (rather than a float) would reach
		// infinity when given an expression to evaluate; when it is given a single float like infinitycheck,
		// this does not happen -> this occurs if this loop is set up the same way as the double's)
		infinitycheck = float_min - pow(2, power);
		if (isinf(infinitycheck))
			power--;
		else
		{
			limitcheck = float_min;
			float_min = float_min - pow(2, power);
			power++;
		}
	}
	float_max = -float_min;

	// reset power and limitcheck
	power = 0;
	limitcheck = 1;

	// (double's calculations)
	while (double_min != limitcheck)
	{
		if (isinf(double_min - pow(2, power)))
			power--;
		else
		{
			limitcheck = double_min;
			double_min = double_min - pow(2, power);
			power++;
		}
	}
	double_max = -double_min;
	
	// prints the range of a char from least to greatest, then prints its unsigned range
	// (size of 8 bits)
	printf("char range: %d to %d, thus unsigned range is 0 to %u\n", char_min, char_max, uchar_max);
	// prints the range of a short integer from least to greatest, then prints its unsigned range
	// (size of 16 bits)
	printf("short range: %d to %d, thus unsigned range is 0 to %u\n", short_min, short_max, ushort_max);
	// prints the range of an integer from least to greatest, then prints its unsigned range
	// (size of 32 bits)
	printf("integer range: %d to %d, thus unsigned range is 0 to %u\n", int_min, int_max, uint_max);
	// prints the range of a long integer from least to greatest, then prints its unsigned range
	// (size of 32 bits)
	printf("long range: %d to %d, thus unsigned range is 0 to %u\n", long_min, long_max, ulong_max);
	// prints the range of a single-precision float from least to greatest, then prints its unsigned range
	// (size of 32 bits, not easily visible like others because of the imprecision of floating point arithmetic)
	printf("float range: %.3f to %.3f, no unsigned form\n", float_min, float_max);
	// prints the range of a double-precision float from least to greatest, then prints its unsigned range
	// (size of 64 bits, not easily visible like others because of the imprecision of floating point arithmetic)
	printf("double range: %.3f to %.3f, no unsigned form\n", double_min, double_max);
	
}