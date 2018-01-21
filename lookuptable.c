/*
 *
 *	This file is for pcom.  It defines two 1D arrays  (lookup table) with character values to prime numbers.
 *
 *
*/

	#define NoCharTypes 58					/* This is the number of letters we can encode. */

	const unsigned char ASCII_index = 65;	/* Where start the ASCII charset off (65=A) */

	struct az
	{
		
		char letter;
		int freq;
	} alphabetsoup[NoCharTypes], temp;
	
	unsigned int y_1[NoCharTypes] = { 
									3, 5, 7, 11, 13, 17, 19, 23, 29, 31,
									37, 41, 43, 47, 53, 59, 61, 67, 71, 
									73, 79, 83, 89, 97, 101, 103, 107, 
									109, 113, 127, 131, 137, 139, 149, 
									151, 157, 163, 167, 173, 179, 181, 
									191, 193, 197, 199, 211, 223, 227, 
									229, 233, 239, 241, 251, 257, 263, 
									269, 271, 277 }, y2[NoCharTypes] = {0};
						        

	int bubsort(void)
	{
		int x, y;
		
		for ( y = 0; y < NoCharTypes; y++ )
		{	
			for ( x = 0; x < NoCharTypes; x++ ) 
			{
				if ( alphabetsoup[x].freq < alphabetsoup[x+1].freq )
				{	
					temp.letter = alphabetsoup[x+1].letter;
					temp.freq = alphabetsoup[x+1].freq;
					alphabetsoup[x+1].letter = alphabetsoup[x].letter;	
					alphabetsoup[x+1].freq = alphabetsoup[x].freq;
					alphabetsoup[x].letter = temp.letter;
					alphabetsoup[x].freq = temp.freq;
				}
			}
		}
		
		return 0;
	}

	void create_lookup_table(void)
	{
		/* y_1[PRIME_No]
		 * y2[MOST_FREQUENT_CHAR]
		 * 
		 *  y_1[a+0] ---> y2[a]
		 *  y_1[a+1] ---> y2[b]
		 *  y_1[a+2] ---> y2[c] and so on...
		 * 	 
		 */
		
		int i;
		
		for ( i = 0; i < NoCharTypes; i++ )
			y2[i] = alphabetsoup[i].letter;
	}
	
	unsigned int dolookup(unsigned int a, unsigned int b)
	{
		int i, f, z;
		
		for ( i = 0; i < NoCharTypes; i++ )
		{
				if ( y2[i] == a )
					f = y_1[i];
	
		}
		for ( i = 0; i < NoCharTypes; i++ )
		{
				if ( y2[i] == b )
					z = y_1[i];
	
		}
		
		/* Return the product of the primes associated with the letters. */
		return f * z;
		
	}
	
	void factor(unsigned int *num1, unsigned int *num2, char *filename)
	{
		int g, true = 1, false = 0, i;
		float root_of_g;
		FILE *readCompressedFile;
		
		readCompressedFile = fopen(filename, "r");
		
		
		root_of_g = (unsigned int)sqrt((float)g);		/* Has the benfit of rounding up or down. */
		
		
		while ( true )
		{
			g = getc(readCompressedFile);
		
			if ( g == EOF )
				break;
		
		
			
			if ( (g %= 2) )	/* I'll simplify this letter my head is not switched on. */
			{
				// do even stuff
			for ( i = 1; i < root_of_g; i += 2 )
			{
				if ( (g %= i) == 0 )
				{
					*num2 = i;
				}
				if ( (g %= i) == 0 )
				{
					*num1 = i;
				}
					printf("%i\t%i\n", *num2, *num1);
					
				}
			}
			else
				{
						// do odd stuff loop de looop					
				}
		
	}
	}	
