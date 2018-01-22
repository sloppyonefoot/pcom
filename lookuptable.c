/*
 *
 *	This file is for pcom.  It defines two 1D arrays  (lookup table) with character values to prime numbers.
 *
 *
*/

	#define NoCharTypes 256					/* This is the number of letters we can encode. */

	const unsigned char ASCII_index = 0x0;	/* Where start the ASCII charset off (default 65=A) */
											/* NOTE: changed to include more characters i.e. newline. */

	struct az
	{
		
		char letter;
		int freq;
	} alphabetsoup[NoCharTypes], temp;
	
	/* Extended the number of primes to the entire ASCII charaset. Pointless with anything above 3*n = 255 */
	unsigned int y_1[NoCharTypes] =   { 03, 05, 07, 11, 13, 17, 19, 23, 29, 
										31, 37, 41, 43, 47, 53, 59, 61, 67, 
										71, 73, 79, 83, 89, 97, 101, 103, 107, 
										109, 113, 127, 131, 137, 139, 149, 151, 
										157, 163, 167, 173, 179, 181, 191, 193, 
										197, 199, 211, 223, 227, 229, 233, 239,
										241, 251, 257, 263, 269, 271, 277, 281,
										283, 293, 307, 311, 313, 317, 331, 337,
										347, 349, 353, 359, 367, 373, 379, 383,
										389, 397, 401, 409, 419, 421, 431, 433,
										439, 443, 449, 457, 461, 463, 467, 479,
										487, 491, 499, 503, 509, 521, 523, 541,
										547, 557, 563, 569, 571, 577, 587, 593, 
										599, 601, 607, 613, 617, 619, 631, 641, 
										643, 647, 653, 659, 661, 673, 677, 683, 
										691, 701, 709, 719, 727, 733, 739, 743, 
										751, 757, 761, 769, 773, 787, 797, 809, 
										811, 821, 823, 827, 829, 839, 853, 857, 
										859, 863, 877, 881, 883, 887, 907, 911, 
										919, 929, 937, 941, 947, 953, 967, 971, 
										977, 983, 991, 997, 1009, 1013, 1019, 1021,
										1031, 1033, 1039, 1049, 1051, 1061, 1063, 
										1069, 1087, 1091, 1093, 1097, 1103, 1109, 
										1117, 1123, 1129, 1151, 1153, 1163, 1171, 
										1181, 1187, 1193, 1201, 1213, 1217, 1223, 
										1229, 1231, 1237, 1249, 1259, 1277, 1279, 
										1283, 1289, 1291, 1297, 1301, 1303, 1307, 
										1319, 1321, 1327, 1361, 1367, 1373, 1381, 
										1399, 1409, 1423, 1427, 1429, 1433, 1439, 
										1447, 1451, 1453, 1459, 1471, 1481, 1483, 
										1487, 1489, 1493, 1499, 1511, 1523, 1531, 
										1543, 1549, 1553, 1559, 1567, 1571, 1579, 
										1583, 1597, 1601, 1607, 1609, 1613, 1619, 1621 }, y2[NoCharTypes] = { 0 };
																

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
		
		readCompressedFile = fopen(filename, "rb");
		
		
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
