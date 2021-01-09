#include "stdio.h"
#include "ctype.h"
#include "string.h"
#include "math.h"

#define MAXLINE 1000    // max char array length

// Prompt is as follows:
// Extend atof to handle scientific notation of the form 123.45e-6, where a 
// floating-point number may be followed by e or E and an optionally signed exponent. 

double sciatof(char s[]);

int main()
{
    // initialise a string to test sciatof with; output result, which should be 0.00012345
    char s[MAXLINE] = "123.45E-6\0";
    printf("%.8f\n", sciatof(s));

    return 0;
}

// atof: convert string s to double 
// (+ support scientific notation of form 123.45e-6 or 123.45E-6)
double sciatof(char s[])
{
    double val;
    int i, e, sign;
    char expstr[strlen(s)];
    // initialise power now so it may be altered whenever
    double power = 1.0;

    // skip white space
    for (i = 0; isspace(s[i]); i++);
    // record sign if present, then advance past it
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    // record digits up to a decimal or exponent
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    // if decimal, advance past it to prepare for counting decimal digits
    if (s[i] == '.')
        i++;
    // if there is an exponent rather than a decimal, record the digits of the exponent
    // in a string to recurse through this function with; the returned double will be
    // used to multiply power by the power of 10 represented by the exponent if its sign
    // were flipped (sign is flipped here because the return statement divides by power)
    else if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
        for (e = 0; s[i] != '\0' && (isdigit(s[i]) || s[i] == '-' || s[i] == '+' || s[i] == '.'); e++, i++)
            expstr[e] = s[i];
        expstr[e] = '\0';

        power *= pow(10, -sciatof(expstr));
    }

    // record digits after the decimal and "count" them by iterating power by powers of 10
    for (; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    // exact same process as the "else if" statement above -> alter power so the returned 
    // value accounts for the influence of the scientific notation exponent
    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
        for (e = 0; s[i] != '\0' && (isdigit(s[i]) || s[i] == '-' || s[i] == '+' || s[i] == '.'); e++, i++)
            expstr[e] = s[i];
        expstr[e] = '\0';

        power *= pow(10, -sciatof(expstr));
    }

    return sign * val / power;
}