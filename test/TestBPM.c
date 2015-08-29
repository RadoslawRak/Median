/*
 * TestMedian.c
 *
 *  Created on: Aug 26, 2015
 *      Author: rrak
 */

#include <BPM.h>
#include <Median.h>
#include <unity.h>

void setUp(void) //This is run before EACH TEST
{

}

void tearDown(void) //This is run after EACH TEST
{

}

//*** BPM ***

void test_BPM_Should_Return_100PBM_From10msSamples(void)
{
	int samples[] = {10,10,10,10,10};
	int length = sizeof(samples) / sizeof(samples[0]);

	TEST_ASSERT_EQUAL_INT(100, BPM(samples,length));
}

void test_BPM_Should_Return_50PBM_From20msSamples(void)
{
	int samples[] = {20,20,20};
	int length = sizeof(samples) / sizeof(samples[0]);

	TEST_ASSERT_EQUAL_INT(50, BPM(samples,length));
}

void test_BPM_Should_Return_100PBM_From_15ms_10ms_5ms_Samples(void)
{
	int samples[] = {15,10,5};
	int length = sizeof(samples) / sizeof(samples[0]);

	TEST_ASSERT_EQUAL_INT(100, BPM(samples,length));
}

void test_BPM_Should_Return_100PBM_From_10ms_10ms_0ms_0ms_SamplesIgnoringZeros(void)
{
	int samples[] = {10,10,0,0};
	int length = sizeof(samples) / sizeof(samples[0]);

	TEST_ASSERT_EQUAL_INT(100, BPM(samples,length));
}

void test_BPM_Should_Return_0_From0msSamples(void)
{
	int samples[] = {0,0,0,0};
	int length = sizeof(samples) / sizeof(samples[0]);

	TEST_ASSERT_EQUAL_INT(0, BPM(samples,length));
}

void test_BPM_Should_NotAlterPassedSamples(void)
{
	int samples[] = {10,10,10,10,10};
	int expect[] = {10,10,10,10,10};
	int length = sizeof(samples) / sizeof(samples[0]);

	BPM(samples,length);

	TEST_ASSERT_EQUAL_INT_ARRAY(expect, samples, length);
}

//*** BPM_MedianFilter_Window3Samples ***

void test_BPM_MedianFilter_Window3Samples_Should_Return_50PBM_From20msSamples(void)
{
	int samples[] = {20,20,20};
	const int length = sizeof(samples) / sizeof(samples[0]);
	int filter_buffer[length];

	int BPM = BPM_MedianFilter_Window3Samples(samples,length,filter_buffer);

	TEST_ASSERT_EQUAL_INT(50, BPM);
}

void test_BPM_MedianFilter_Window3Samples_Should_Return_100PBM_From_15ms_10ms_5ms_Samples(void)
{
	int samples[] = {15,10,5};
	const int length = sizeof(samples) / sizeof(samples[0]);
	int filter_buffer[length];

	int BPM = BPM_MedianFilter_Window3Samples(samples,length,filter_buffer);

	TEST_ASSERT_EQUAL_INT(100, BPM);
}

void test_BPM_MedianFilter_Window3Samples_Should_Return_100PBM_From_10ms_10ms_0ms_0ms_SamplesIgnoringZeros(void)
{
	int samples[] = {10,10,0,0};
	const int length = sizeof(samples) / sizeof(samples[0]);
	int filter_buffer[length];

	int BPM = BPM_MedianFilter_Window3Samples(samples,length,filter_buffer);

	TEST_ASSERT_EQUAL_INT(100, BPM);
}

void test_BPM_MedianFilter_Window3Samples_Should_Return_100PBM_From10msSamplesWithIsolated_1ms_AND_100ms_Samples(void)
{
	int samples[] = {10,10,1,10,10,10,100,10,10,10};
	const int length = sizeof(samples) / sizeof(samples[0]);
	int filter_buffer[length];

	int BPM = BPM_MedianFilter_Window3Samples(samples,length,filter_buffer);

	TEST_ASSERT_EQUAL_INT(100, BPM);
}

void test_BPM_MedianFilter_Window3Samples_Should_Return_50PBM_From20msSamplesWithIsolated_1ms_AND_100ms_Samples(void)
{
	int samples[] = {20,20,1,20,20,20,20,20,100,20,20,20};
	const int length = sizeof(samples) / sizeof(samples[0]);
	int filter_buffer[length];

	int BPM = BPM_MedianFilter_Window3Samples(samples,length,filter_buffer);

	TEST_ASSERT_EQUAL_INT(50, BPM);
}

void test_BPM_MedianFilter_Window3Samples_Should_NotAlterPassedSamples(void)
{
	int samples[] = {10,10,10,10,10};
	int expect[] = {10,10,10,10,10};
	const int length = sizeof(samples) / sizeof(samples[0]);
	int filter_buffer[length];

	BPM_MedianFilter_Window3Samples(samples,length,filter_buffer);

	TEST_ASSERT_EQUAL_INT_ARRAY(expect, samples, length);
}
