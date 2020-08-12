#include "stdio.h"
#include "stdlib.h"

#define MAXLINE 1000 // maximum input line length
#define TABSTOP 8

void detab (char d[], char e[]);

int c, i, charCount;
char in[MAXLINE], out[MAXLINE];

void main()
{
	//if end of file or max input length is not reached, record input in character array in[]
	for (i = 0; (c = getchar()) != EOF && i < MAXLINE; i++)
	{
		in[i] = c;
	}
	//add null to mark end of input
	in[i] = '\0';
	
	//run detab
	detab(in, out);
	//print both in and out
	printf("%s", in);
	printf("%s", out);
	
	system("pause");
}

// detab: remove tabs from input by replacing them with blanks
// (there is a tab stop after every set of 8 characters)
void detab (char in[], char out[])
{
	charCount = 0;
	int t = 0;
	
	
	for(int i = 0; in[i] != '\0' && t < MAXLINE; i++, t++, charCount++)
	{
		//counts from 0 to 8 to keep track of nearest tab stop
		if (charCount == 8)
			charCount = 0;
			
		//if tab, place blanks until you reach tab stop, then continue from original location
		if (in[i] == '\t')
		{
			while (charCount != TABSTOP)
			{
				out[t] = ' ';
				t++;
				charCount++;
			}
			// because they'll both iterate upon looping
			charCount = -1;
			t--;
		}
		
		//if not tab, copy input to output as is
		else 
		{
			out[t] = in[i];
		}
			
	}
	
}