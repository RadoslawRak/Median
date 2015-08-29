/*
 * Median.c
 *
 *  Created on: Aug 26, 2015
 *      Author: rrak
 */

#include <Median.h>
#include <stdlib.h> //For qsort() func.

void Median_SortDesc(int *Array, int Length)
{
	qsort(Array, Length, sizeof(int), Median_int_CompDesc);
}

int Median_int_CompDesc (const void *a, const void *b)
{
	return ( *(int*)b - *(int*)a );
}

int Median(int* ArrayBuffer, int Length)
{
	Median_SortDesc(ArrayBuffer,Length);

	if(0 == (Length % 2)) //Even number of elements
	{
		/* SELECTION EXPLANATION
		 * Length: 6	Indexes: [0 1 2 3 4 5]
		 * Median = (Array[2] + Array[3]) / 2
		 *
		 * 2 == (6 / 2) - 1
		 * 3 == (6 / 2)
		 */
		int Middle2;
		Middle2 = ArrayBuffer[(Length / 2) - 1];
		Middle2 += ArrayBuffer[(Length / 2)];

		/* MODULO CORRECTION EXPLANATION
		 * Case 1: Middle2 = 6
		 * Middle2 / 2 = 3, that is correct
		 * iddle2 = Middle2 / 2 + Middle2 % 2 = 3 + 0
		 *
		 * Case 2: Middle2 = 7
		 * Middle2 / 2 = 3, should be rounded to 4
		 * Middle2 = Middle2 / 2 + Middle2 % 2 = 3 + 1
		 */
		return (Middle2 / 2) + (Middle2 % 2);
	}
	else //Odd number of elements
	{
		/* SELECTION EXPLANATION
		 * Length: 5	Indexes: [0 1 2 3 4]
		 * Median = (Array[2])
		 *
		 * 2 == (5 / 2)		NOTE: 5 / 2 = 2, division uses floor rounding
		 */
		return ArrayBuffer[ (Length / 2) ];
	}
}


