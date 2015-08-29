/*
 ============================================================================
 Name        : C_UnityTestsProject.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <Median.h>
#include <BPM.h>

int main(void)
{
	int DataPoints[] = {14, 15, 14, 1, 16, 14, 37, 15, 14, 2, 14, 100, 14, 15, 14, 14, 41, 15, 14, 15};
	const int DataLenght = sizeof(DataPoints) / sizeof(DataPoints[0]);
	int DataBuffer[DataLenght];

	printf("Estimate heart rate based on an array of samples [ms]:\n");

	int i;
	for(i = 0; i < DataLenght; i++)
	{
		printf( "%d, ", DataPoints[i] );
	}
	printf("\n\n");

	int BPM_Simple = BPM(DataPoints,DataLenght);
	int BPM_Median = BPM_MedianFilter_Window3Samples(DataPoints,DataLenght,DataBuffer);

	printf("Estimation based on simple beat interval average: %d BPM\n\n", BPM_Simple);


	printf("Median filtered samples [ms]:\n");
	for(i = 0; i < DataLenght; i++)
	{
		printf( "%d, ", DataBuffer[i] );
	}
	printf("\n\n");

	printf("Estimation based on median filtered interval average: %d BPM\n", BPM_Median);

	return EXIT_SUCCESS;
}

