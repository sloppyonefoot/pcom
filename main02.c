/*
 * depcom for pcom
 *
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void factor(unsigned int *num1, unsigned int *num2, char *filename);

int main(int argv, char *argc[])
{
	int argumen_no = (int)argv, n1, n2, *n1ptr, *n2ptr;
	char *file = (char *)argc[1];
	
	n1ptr = &n1, n2ptr = &n2;
	
	if ( argumen_no < 2 )
		exit(1);
	else 
	{
		
		if ( strlen(file) > 50 ) 
		{
				printf("Get a grip! File name less than 50 letters please.\n");
				exit(1);
		}
	}
	
	factor(n1ptr, n2ptr, file);
	
	exit(0);
}



void factor(unsigned int *num1, unsigned int *num2, char *filename)
{
	unsigned int g, true = 1, false = 0, i, q = 0, letters[2] = {0};
	static unsigned long int byte_counter = 0;
	
	float root_of_g;
	FILE *readCompressedFile, *fileOut;
	
	readCompressedFile = fopen(filename, "rb");
	fileOut = fopen("output-test.txt", "wb+");
	
while ( true )
{
	g = getc(readCompressedFile);
	
	if ( g == EOF )
		true = false;		/* To make sure we finish the current write op. */
		
	root_of_g = (unsigned int)sqrt((float)g);		/* Has the benfit of rounding up or down. */

	for ( i = 3; i <= root_of_g; i += 2 )
	{
		if ( g % i == 0 )
		{
			letters[q] =  i;
			q++;
			letters[q] = g / i;
			q = 0;
			break;
		}
	}
	
	fprintf(fileOut, "%c%c", letters[0], letters[1]);
}
	fclose(fileOut);	
	fclose(readCompressedFile);	

	
	
}	
