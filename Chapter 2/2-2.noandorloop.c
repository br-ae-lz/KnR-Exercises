#include "stdio.h"

// Prompt is as follows:
// Write a loop equivalent to the for loop above without using && or ||. 
	
// commented version of original loop; must be remade without use of && or ||
//for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
	//s[i] = c;

int main()
{
	// declaration of things needed for the original and remade loop
	int c, i, lim;
	// (quick initialization of lim)
	lim = 10;
	char s[lim];
		
	// declaration and initialization of "switch" variables; check all while loop parameters in an
	// appropriate order to ensure none of them are left behind
	int switch1, switch2, switch3;
	i = switch1 = switch2 = switch3 = 0;
	
	// just a whole bunch of variables and if statements strung together that accomplish the
	// same old task but help to illustrate the order each condition is verified in a tad
	// better. yay.
	while (switch3 == 0)
	{
		while (switch2 == 0)
		{
			while (switch1 == 0)
			{
				if(i = lim-1)
					switch1 = switch2 = switch3 = 1;
				
				if((c=getchar())== '\n')
					switch1 = switch2 = switch3 = 1;
					
				if(c == EOF)
					switch1 = switch2 = switch3 = 1;
				s[i] = c;
				i++;
			}
		}
	}
	// print out resultant character array to verify because... why not?
	printf("%s", s);
	
	return 0;
}