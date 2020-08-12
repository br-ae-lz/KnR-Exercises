#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "float.h"
#include "math.h"

void header (void);
void computation (void);

void main()
{
	
	//run header and computation functions, compare
	printf("header:\n");
	header();
	printf("\n\n");
	printf("computation:\n");
	computation();
	
	system("pause");
	
}

// header: determine the ranges of char, short, int, and long (signed and unsigned) by printing
// values from standard headers, output them to the screen
void header (void)
{
	
	// prints the range of a char from least to greatest, then prints its unsigned range
	// (size of 8 bits)
	printf("char range: %d to %d, thus unsigned range is %u\n", SCHAR_MIN, SCHAR_MAX, UCHAR_MAX);
	// prints the range of a short integer from least to greatest, then prints its unsigned range
	// (size of 16 bits)
	printf("short range: %d to %d, thus unsigned range is %u\n", SHRT_MIN, SHRT_MAX, USHRT_MAX);
	// prints the range of an integer from least to greatest, then prints its unsigned range
	// (size of 32 bits)
	printf("integer range: %d to %d, thus unsigned range is %u\n", INT_MIN, INT_MAX, UINT_MAX);
	// prints the range of a long integer from least to greatest, then prints its unsigned range
	// (size of 32 bits)
	printf("long range: %f to %d, thus unsigned range is %u\n", DBL_MAX, LONG_MAX, ULONG_MAX);
	
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
	// float variable declaration
	float float_min, float_max;
	// double variable declaration
	double double_min, double_max;
	// misc. declaration
	int power = 1250;
	
	// determine the min and max values of each variable by continuously incrementing them until
	// they overflow; once this happens, determine the range between these variables to
	// acknowledge their unsigned ranges
	// (char's calculations)
		//for (char_max = 0; char_max <= 0; char_max--);
		//char_min = char_max + 1;
		//uchar_max = char_max - char_min;
	// (short's calculations)
		//for (short_max = 0; short_max <= 0; short_max--);
		//short_min = short_max + 1;
		//ushort_max = short_max - short_min;
	// (int's calculations)
		//for (int_min = 0; (int_min - 1) < int_min; int_min--);
		//int_max = int_min - 1;
		//uint_max = int_max - int_min;
	// (long's calculations)
		//for (long_min = 0; (long_min - 1) < long_min; long_min--);
		//long_max = long_min - 1;
		//ulong_max = long_max - long_min;
	double_min = -1;
	int kill = 0;
	int extra = 0;
	// (float's calculations)
	printf("before first: %f, %f, %d\n", double_min, double_min - pow(2, 1250), isinf(double_min - pow(2, 1250)));
	while ((float_min - 1.0) < float_min)
	{
		kill = power;
		printf("first: \n%f, \n%f, \n%d, \n%d, %d, %.f, %.f\n", double_min, double_min - (pow(2, power) - extra), power, kill, extra, pow(2, 970), pow(2, 969) + extra);
		
		if (isinf(double_min - pow(2, power)) == 1)
		{
			kill = power;
			power--;
		}
		else
			{
				if (kill == power)
					extra++;
			double_min = double_min - pow(2, power) - extra;
			}
			
	}
	double_max = double_min - 1;
	printf("second: %f, %d\n", double_min, power);
	printf("third: %f, %d\n", double_min - 1.0, isinf(double_min - pow(2, power)));
	
	
	
	// prints the range of a char from least to greatest, then prints its unsigned range
	// (size of 8 bits)
	printf("char range: %d to %d, thus unsigned range is %u\n", char_min, char_max, uchar_max);
	// prints the range of a short integer from least to greatest, then prints its unsigned range
	// (size of 16 bits)
	printf("short range: %d to %d, thus unsigned range is %u\n", short_min, short_max, ushort_max);
	// prints the range of an integer from least to greatest, then prints its unsigned range
	// (size of 32 bits)
	printf("integer range: %d to %d, thus unsigned range is %u\n", int_min, int_max, uint_max);
	// prints the range of a long integer from least to greatest, then prints its unsigned range
	// (size of 32 bits)
	printf("long range: %d to %d, thus unsigned range is %u\n", long_min, long_max, ulong_max);
	
}