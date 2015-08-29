/*
 * BPM.h
 *
 *  Created on: Aug 26, 2015
 *      Author: rrak
 */

#ifndef BPM_H_
#define BPM_H_

#define MILISECONDS_IN_ONE_SECOND 1000

int BPM(int *StepSamples_ms, int nSamples);
int BPM_MedianFilter_Window3Samples(int *StepSamples_ms, int nSamples, int *FilterBuffer_nSamplesLong);

#endif /* BPM_H_ */
