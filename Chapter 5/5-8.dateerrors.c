#include <stdio.h>
#include <stdlib.h>

// Prompt is as follows:
// There is no error checking in day_of_year or month_day. Remedy this defect.

// In the case of error, my solutions were to have day_of_year return -1 and have month_day
// suddenly terminate (by way of a return statement, since the function is of void type).
// It's clear how day_of_year's output could be interpreted, though month_day leaves a bit
// more to the imagination, so I'll state my idea here. I'd initialize the variables that
// pmonth and pday point to as impossible values such as -1, and interpret the result as an
// error if those values remained as such after the function was ran.

static char daytab[2][13] = {
{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

// day_of_year: set day of year from month & day (and check for errors)
int day_of_year(int year, int month, int day)
{    
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    // first validate month, then day; if either are invalid, return error
    if (month < 1 || month > 12 || day < 1 || day > daytab[leap][month])
        return -1;

    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

// month_day: set month, day from day of year (and check for errors)
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    // check for errors, terminate if a check fails
    // first check; is lower bound of day violated?
    if (yearday < 1)
        return;
    // second check; is upper bound of day violated?
    if (leap)
        if (yearday > 366)
            return;
    else if (yearday > 365)
        return;
    
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}