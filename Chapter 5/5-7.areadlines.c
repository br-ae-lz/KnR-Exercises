#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXLINE 1000
#define MAXLEN 10000

// Prompt is as follows:
// Rewrite readlines to store lines in an array supplied by main, rather 
// than calling alloc to maintain storage. How much faster is the program?

// To determine how much faster areadlines is, I used the clock_t variable type
// and the clock() function from time.h. To normalize the timing, I wrote an
// alternative version of getline, getaline, that passes a predefined line for a
// number of calls rather than accepting user input on every call. This program
// calls getaline 100 times, printing both its progress and the final times for each
// function to the screen. On my machine, the output paints areadlines as roughly
// one to two hundredths of a second faster than readlines for an input of 100 lines.

int getaline(char [], int);
int areadlines(char [], char *[], int);
int readlines(char *[], int);
char *alloc(int);

// controls how many iterations getaline can be run for
int numlines = 100;

int main()
{
    char lines[MAXLEN];
    char *lineptr[MAXLINE];

    // phase 1; times areadlines for 100 lines
    printf("phase 1 start!\n");
    clock_t p1start = clock();
    areadlines(lines, lineptr, 100);
    clock_t p1end = clock();

    // reset lines for phase 2
    numlines = 100;

    // phase 2; times readlines for 100 lines
    printf("phase 2 start!\n");
    clock_t p2start = clock();
    readlines(lineptr, 100);
    clock_t p2end = clock();

    // calculate times for phase 1 and phase 2 in seconds
    double p1secdiff = (double) (p1end - p1start)/CLOCKS_PER_SEC;
    double p2secdiff = (double) (p2end - p2start)/CLOCKS_PER_SEC;

    // print phase times to the screen
    printf("\nareadlines time: %.3f seconds\nreadlines time: %.3f seconds\n", p1secdiff, p2secdiff);

    return 0;
}

// areadlines: read input lines, store in main() array
int areadlines(char lines[], char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLINE], *endlines;

    p = lines;
    nlines = 0;
    endlines = p + MAXLEN;

    // routine for collecting input lines
    while ((len = getaline(line, MAXLINE)) > 0)
        // too much input read; return error
        if (nlines >= maxlines || p + len > endlines)
            return -1;
        // line may be collected; copy to its proper place, move on
        else 
        {
            // replace '\n' with '\0', copy line to proper location
            line[len-1] = '\0';
            strcpy(p, line);
            // save current line location, then prepare for the next
            lineptr[nlines++] = p;
            p += len;
        }
    return nlines;
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = getaline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = malloc(len)) == NULL)
            return -1;
    else {
        line[len-1] = '\0'; /* delete newline */
        strcpy(p, line);
        lineptr[nlines++] = p;
        }
    return nlines;
}

// getline: read a preset line into s, return length
int getaline(char s[], int lim)
{
    int c, i;
    char *p;
    char line[9] = "testing!\n";
    // shows program progress and slows things down enough for my machine to measure
    printf("current num: %d\n", numlines);

    // if numlines is greater than 0, read line again; otherwise terminate, return 0
    if (numlines > 0)
    {
        c = line[0];
        numlines--;
    }
    else
        c = EOF;
        
    for (i=0; i < lim-1 && c !=EOF && c!='\n'; ++i)
        c = s[i] = line[i];
    if (c == '\n') 
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}