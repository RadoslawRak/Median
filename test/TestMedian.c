/*
 * TestMedian.c
 *
 *  Created on: Aug 26, 2015
 *      Author: rrak
 */

#include <Median.h>
#include <unity.h>

void setUp(void) //This is run before EACH TEST
{

}

void tearDown(void) //This is run after EACH TEST
{

}

//*** Median_int_CompDesc ***

void test_Median_int_CompDesc_Should_ReturnDifference_b_minus_a_Given_b_7_And_a_5(void)
{
	int a = 5;
	int b = 7;

	TEST_ASSERT_EQUAL_INT(2, Median_int_CompDesc(&a,&b));
}

void test_Median_int_CompDesc_Should_ReturnDifference_b_minus_a_Given_b_7_And_a_0(void)
{
	int a = 0;
	int b = 7;

	TEST_ASSERT_EQUAL_INT(7, Median_int_CompDesc(&a,&b));
}

void test_Median_int_CompDesc_Should_ReturnDifference_b_minus_a_Given_b_7_And_a_10(void)
{
	int a = 10;
	int b = 7;

	TEST_ASSERT_EQUAL_INT(-3, Median_int_CompDesc(&a,&b));
}

//*** Median_SortDesc ***

void test_Median_SortDesc_Should_Return_3_2_1_IfGiven_2_1_3(void)
{
	int given[] = {2,1,3};
	int expect[] = {3,2,1};
	int length = sizeof(given) / sizeof(given[0]);

	Median_SortDesc(given, length);

	TEST_ASSERT_EQUAL_INT_ARRAY(expect, given, length);
}

void test_Median_SortDesc_Should_Return_5_4_IfGiven_4_5(void)
{
	int given[] = {4,5};
	int expect[] = {5,4};
	int length = sizeof(given) / sizeof(given[0]);

	Median_SortDesc(given, length);

	TEST_ASSERT_EQUAL_INT_ARRAY(expect, given, length);
}

void test_Median_SortDesc_Should_Return_5_4_IfGiven_5_4(void)
{
	int given[] = {5,4};
	int expect[] = {5,4};
	int length = sizeof(given) / sizeof(given[0]);

	Median_SortDesc(given, length);

	TEST_ASSERT_EQUAL_INT_ARRAY(expect, given, length);
}

void test_Median_SortDesc_Should_Return_7_6_3_2_IfGiven_2_7_3_6(void)
{
	int given[] = {2,7,3,6};
	int expect[] = {7,6,3,2};
	int length = sizeof(given) / sizeof(given[0]);

	Median_SortDesc(given, length);

	TEST_ASSERT_EQUAL_INT_ARRAY(expect, given, length);
}

//*** Median ***

void test_Median_Should_Return_2_IfGiven_2_1_3(void)
{
	int given[] = {2,1,3};
	int median = 0;
	int length = sizeof(given) / sizeof(given[0]);

	median = Median(given, length);

	TEST_ASSERT_EQUAL_INT(2, median);
}

void test_Median_Should_Return_5_IfGiven_4_5(void)
{
	int given[] = {4,5};
	int median = 0;
	int length = sizeof(given) / sizeof(given[0]);

	median = Median(given, length);

	TEST_ASSERT_EQUAL_INT(5, median);
}

void test_Median_Should_Return_4_IfGiven_5_3(void)
{
	int given[] = {5,3};
	int median = 0;
	int length = sizeof(given) / sizeof(given[0]);

	median = Median(given, length);

	TEST_ASSERT_EQUAL_INT(4, median);
}

void test_Median_Should_Return_3_IfGiven_2_7_3_6_1(void)
{
	int given[] = {2,7,3,6,1};
	int median = 0;
	int length = sizeof(given) / sizeof(given[0]);

	median = Median(given, length);

	TEST_ASSERT_EQUAL_INT(3, median);
}
