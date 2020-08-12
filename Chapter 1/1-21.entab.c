#include "stdio.h"
#include "stdlib.h"

#define MAXLINE 1000 //maximum input line length
#define TABSTOP 8

void entab (char d[], char e[]);

int c, i, charCount, blankCount;
char in[MAXLINE], out[MAXLINE];

void main()
{
	// if end of file or max input length is not reached, record input in character array in[]
	for (i = 0; (c = getchar()) != EOF && i < MAXLINE; i++)
	{
		in[i] = c;
	}
	// add null to mark end of input
	in[i] = '\0';
	
	// run entab
	entab(in, out);
	// print both in and out
	printf("%s", in);
	printf("%s", out);
	
	system("pause");
}

// entab: replace strings of blanks in input with tabs (and a few blanks, if necessary)
// (there is a tab stop after every set of 8 characters)
void entab (char in[], char out[])
{
	charCount = 0;
	blankCount = 0;
	int t = 0;
	
	
	for(int i = 0; in[i] != '\0' && t < MAXLINE; i++, t++, charCount++)
	{
		
		// counts up to tab stop to keep track of the nearest one
		if (charCount == TABSTOP)
			charCount = 0;
		
		if (in[i] == ' ')
		{
		
			// while the current input character is a blank...
			while (in[i] == ' ')
			{
				i++;
				blankCount++;
				charCount++;
				
				// ...check if blanks make up the input until the next tab stop; if so, 
				// place a tab, reset counters, and keep counting blanks
				if (charCount == TABSTOP)
				{
					out[t] = '\t';
					t++;
					blankCount = charCount = 0;
				}
				
			}
			
			// because they'll both iterate upon looping
			charCount--;
			t--;
			i--;
		}
		
		//if there are excess blanks that cannot be covered by a tab, copy them to the output
		if (blankCount != 0)
		{
			// undo previous preparation for loop
			t++;
			while (blankCount != 0)
			{
				out[t] = ' ';
				blankCount--;
				t++;
			}
			// prepare for loop once more
			t--;
		}
		
		// if tab or blank process hasn't been gone through, copy input to output as is
		if (out[t] != '\t' && ' ')
		{
			//if tab is placed in output, then reset count to next tab stop
			if (in[i] == '\t')
				charCount = 0;
				
			out[t] = in[i];
			
		}
			
	}
	
}