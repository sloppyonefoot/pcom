/*
 *  Pcom: a program that uses a little knowledge of number theory to compress data.
 *  Author: Sloppy One Foot
 *  Contact: sloppyonefoot@gmail.com
 *  DOB: 13/01/17
 *
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "lookuptable.c"


/* 
 * Note: it's important you read "lookuptable.c" to see some of the 
 * #define and constants that are setup there.
 *
*/

FILE *fptr;											/* Input file. */

int letter_frequency(char *filename);				/* Check the global in lookuptable.c */
void compress(char *filename);
int measure(int let1, int let2);
void create_lookup_table(void);
int bubsort(void);
unsigned int dolookup(unsigned int a, unsigned int b);
void factor(unsigned int *num1, unsigned int *num2, char *filename);





int main(int argv, char *argc[])
{
	int argumen_no = (int)argv, q, n, Z, Q;
	char *file = (char *)argc[1];
	
	if ( argumen_no < 2 )
		exit(1);
	else 
	{
		if ( strlen(file) > 50 ) 
		{
				printf("Get a grip! File name less than 50 letters please.\n");
				exit(1);
		}
		
		fptr = fopen(file, "rb");		
		if ( fptr == NULL ) 
		{
			printf("No such file.\n");
			exit(1);
		}
	}
	fclose(fptr);					/* Keep is closed until we need it. */
	n = letter_frequency(file);
	
	/* For debug purposes... */
	/*for ( n = 0; n < NoCharTypes; n++ )
	{
			printf("%c occured %i times.\n", alphabetsoup[n].letter, alphabetsoup[n].freq);
	}*/
	/*printf("Sorted: \n");
	printf("*******************\n");*/
	if ( !bubsort() )
	{
		create_lookup_table();
		compress(file);
	}
	factor(&Z, &Q, file);
	exit(0);
}

int letter_frequency(char *filename)
{
	int n, b, true = 1, p;
	register unsigned int i;
	/* alphapbetsoup[] struct is declared in lookuptable.c globally 
	 * for easy access 
	 * 
	 */
	
	/* Open file: */
	fptr = fopen(filename, "rb");
	
	if ( fptr == NULL ) 	
		exit(1);
		
	for ( n = 0; n < NoCharTypes; n++ )
	{
		alphabetsoup[n].letter = ASCII_index + n;	/* Setup a bunch of structs containing our charset. */
		alphabetsoup[n].freq = 0;					/* Might aswell initiate the freq element which is the number of times our letter appears within our file. */
	}
	
	while ( true )
	{
		p = getc(fptr);
		if ( p == EOF )	/* Exit while loop when end of file is reached. */
			break;
		
		for ( i = 0; i  < NoCharTypes; i++ )
		{
			if ( alphabetsoup[i].letter == (char)p )
			{
				alphabetsoup[i].freq++;
				break;
			}
		}
	}
	
	rewind(fptr);
	fclose(fptr);

	return 0;

}

void compress(char *filename)
{
	unsigned int two_letters[2], p, n = 0, true = 1, todo = 0, i, product;
	FILE *outfile;
	
	/* Open file: */
	fptr = fopen(filename, "rb");
	
	if ( fptr == NULL )
		exit(1);
	
	/* Open write out file: */
	outfile = fopen(strcat(filename, ".pcom"), "wb");
	if ( outfile == NULL )
		exit(1);
	
	while ( true )
	{
		/* Imagine the following code as batches of bytes; a pair of bytes
		 * infact, each pair put through the measure function post product.  If letter (1)
		 * is greater than letter (2) then we multiply them together to get
		 * the product (3) but we add 1 (3) thus making it even.  We now know
		 * which letter goes first when decompressing and reassembling.
		 * 
		 * If letter (1) is less than letter (2) we keep the product (3)
		 * untouched so it remains odd and we know not to put it in the wrong
		 * order.
		 * 
		 */
		p = getc(fptr);
		two_letters[0] = p;
		p = getc(fptr);
		two_letters[1] = p;
		
		product = dolookup(two_letters[0], two_letters[1]);
	    fputc(product, outfile);
		
		if ( p == EOF )	/* Exit while loop when end of file is reached. */
			break;
		todo = measure(two_letters[0], two_letters[1]);
		
		if ( todo )			/* If the product is to be rearranged on decompression */
			product++;		/* add 1 to make it an even number. */
	}
	
	/* Tidy up before leaving function. */
	rewind(outfile);
	fclose(outfile);
	rewind(fptr);
	fclose(fptr);
}

int measure(int let1, int let2)
{
		int greater = 1, lessthan = -1, equal = 0;
		if ( let1 > let2 )
			return greater;
		if ( let1 < let2 )
			return lessthan;
		else
			return equal;
}

