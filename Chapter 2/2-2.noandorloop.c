#include "stdio.h"
#include "stdlib.h"

void main()
{
	//declaration of things needed for the original and remade loop
	int c, i, lim;
	//(quick initialization of lim)
	lim = 10;
	char s[lim];
	
	// original loop; must be remade without use of && or ||
	//for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
		//s[i] = c;
		
	// declaration and initialization of "switch" variables; check all while loop parameters in an
	// appropriate order to ensure none of them are left behind
	int switch1, switch2, switch3;
	switch1 = switch2 = switch3 = 0;
	
	// just a whole bunch of variables and if statements strung together that accomplish the
	// same old task but help to illustrate the order each condition is verified in a tad
	// better. yay.
	while (switch3 == 0)
	{
		while (switch2 == 0)
		{
			while ((c=getchar()) != '\n')
			{
			system("pause");
				if(i == lim-1)
					switch1 = switch2 = switch3 = 1;
				
				if(c == '\n')
					system("pause");
					switch1 = switch2 = switch3 = 1;
					
				if(c == EOF)
					switch1 = switch2 = switch3 = 1;
				s[i] = c;
				i++;
			}
			system("pause");
		}
		system("pause");
	}
	system("pause");
	printf("hi");
	system("pause");
	// print out resultant character array because... why not?
	printf("%s", s);
	
	system("pause");
}