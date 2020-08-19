#include "stdio.h"
#include "stdlib.h"

#define MAXLINE 1000	   	// max line length
#define MAXDISPLAYLINE 111 	// max display line length
#define TABSTOP 8			// characters between tab stops

// Prompt is as follows:
// Write a program to "fold" long input lines into two or more shorter lines after
// the last non-blank character that occurs before the n-th column of input. Make sure your
// program does something intelligent with very long lines, and if there are no blanks or tabs
// before the specified column. 

void foldLine (char m[], char n[]);

int c, i;
char in[MAXLINE], out[MAXLINE];

void main()
{
	int i = 0;
	
	// if end of file or max input length is not reached, record input in character array in[]
	for (i = 0; (c = getchar()) != EOF && i < 1000; i++)
		in[i] = c;
	
	// add null to mark end of input
	in[i] = '\0';
	
	// run foldLine
	foldLine(in, out);
	// print output
	printf("%s", out);
	
	system("pause");
}

// foldLine: if a line's length exceeds a maximum, fold it over onto another line
void foldLine (char in[], char out[])
{
	int t, foldCount, charCount;
	t = foldCount = charCount = 0;
	
	for(int i = 0; in[i] != '\0' && t < MAXLINE; i++, t++, charCount++, foldCount++)
	{
		// counts up to tab stop to keep track of the nearest one
		if (charCount == TABSTOP)
			charCount = 0;
		
		// if the counter has progressed such that the line must be folded, do so by adding
		// a newline and iterating (don't do this if the current character is a newline)
		if (foldCount == MAXDISPLAYLINE && in[i] != '\n')
		{
		out[t] = '\n';
		t++;
		foldCount = 0;
		}
		
		// if there is a newline, stop counting the characters for the previous line and reset
		// the tab stop count; add the newline to the output and loop from there
		if (in[i] == '\n')
		{
			foldCount = charCount = 0;
			out[t] = in[t];
		}
		
		// if there is a tab, turn its characters into blanks to continuously check if they max
		// out the display line; if so, add a new line and continue to add blanks
		// (I get this is implicitly said to not be necessary in the exercise's description,
		// and that it doesn't even mirror how tabs work... I just wanted to try it out)
		else if (in[i] == '\t')
		{
			while (charCount < TABSTOP)
			{
				if (foldCount == MAXDISPLAYLINE)
				{
					out[t] = '\n';
					t++;
					foldCount = 0;
				}
				out[t] = ' ';
				t++;
				charCount++;
				foldCount++;
			}
			//prepare variables for loop incrementing
			charCount = -1;
			foldCount--;
			t--;
		}
		
		// if the above two statements aren't true, copy the input to the output and loop
		// (this is done to separate the "else if" tab statement and this statement)
		else
		{
			out[t] = in[i];
		}
		
	}
	
}