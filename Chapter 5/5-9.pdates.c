#include <stdio.h>

// Prompt is as follows:
// Rewrite the routines day_of_year and month_day with pointers instead of indexing.

static char daytab[2][13] = {
{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

// pday_of_year: set day of year from month & day using pointers
int day_of_year(int year, int month, int day)
{
    int leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    char *p = *(daytab + leap);

    while (month-- > 0)
        day += *p++;
    
    return day;
}

// pmonth_day: set month, day from day of year using pointers
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    char *p = *(daytab + leap);

    while(yearday > *p)
        yearday -= *p++;  
        
    *pmonth = p - *(daytab + leap);
    *pday = yearday;
}