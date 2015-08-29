/*
 * BPM.c
 *
 *  Created on: Aug 26, 2015
 *      Author: rrak
 */

#include <BPM.h>
#include <Median.h>

int BPM(int *StepSamples_ms, int nSamples)
{
	int i;
	int AverageSample_ms = 0;
	int nNonZeroSamples = nSamples;

	for(i = 0; i < nSamples; i++)
	{
		AverageSample_ms += StepSamples_ms[i];

		if( 0 == StepSamples_ms[i]) nNonZeroSamples--;
	}

	if( 0 < nNonZeroSamples)
	{
		AverageSample_ms = (AverageSample_ms / nNonZeroSamples);

		return (MILISECONDS_IN_ONE_SECOND / AverageSample_ms);
	}

	return 0; //No valid samples
}

int BPM_MedianFilter_Window3Samples(int *StepSamples_ms, int nSamples, int *FilterBuffer_nSamplesLong)
{
	int MedianWindow[] = {0,0,0};
	const int WindowLength = sizeof(MedianWindow) / sizeof(MedianWindow[0]);

	if(nSamples >= WindowLength) //Only filter if there is enough data
	{
		//1. Window touches data start, use first sample twice
		MedianWindow[0] = StepSamples_ms[0];
		MedianWindow[1] = StepSamples_ms[0];
		MedianWindow[2] = StepSamples_ms[1];

		FilterBuffer_nSamplesLong[0] = Median(MedianWindow,WindowLength);

		//2. Window fits fully in data
		int i;

		for(i = 1; i < (nSamples - 1); i++)
		{
			MedianWindow[0] = StepSamples_ms[i - 1];
			MedianWindow[1] = StepSamples_ms[i];
			MedianWindow[2] = StepSamples_ms[i + 1];

			FilterBuffer_nSamplesLong[i] = Median(MedianWindow,WindowLength);
		}

		//3. Window touches data end, use last sample twice
		MedianWindow[0] = StepSamples_ms[nSamples - 2];
		MedianWindow[1] = StepSamples_ms[nSamples - 1];
		MedianWindow[2] = StepSamples_ms[nSamples - 1];

		FilterBuffer_nSamplesLong[nSamples - 1] = Median(MedianWindow,WindowLength);
	}

	//Pass filtered version of data to BPM
	return BPM(FilterBuffer_nSamplesLong,nSamples);
}
