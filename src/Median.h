/*
 * Median.h
 *
 *  Created on: Aug 26, 2015
 *      Author: rrak
 */

/**@file
 * @brief Median calculation from a set of samples.
 *
 * Calculating a median from a set of samples requires sorting them.
 * Sorting is done in a separate function.
 * Sorting mechanism needs a comparator function for the sorted type.
 */

#ifndef MEDIAN_H_
#define MEDIAN_H_

/**
 * Descending sort function. Implemented using qsort() included in stdlib.
 * @param Array Array to be sorted
 * @param Length Sorted array length
 */
void Median_SortDesc(int *Array, int Length);

/**
 * \brief Sorting function requires sorted item comparator.
 *
 * This function serves that purpose, it returns b - a value from items passed as pointers.
 * @param a First compared param
 * @param b Second compared param
 * @return (b - a) calculated from pointed items value seen as int
 * @see Median_SortDesc
 */
int Median_int_CompDesc (const void *a, const void *b);

/**
 * Calculates a median from passed samples. Sorts passed samples, so the operation is destructive to the data!
 *
 * Works with odd and even lengths of data. For even - averages two central data points
 * @param ArrayBuffer Data samples to calculate median from. Buffer indicates that this should be a copy of the original data, cause passed array will be altered (sorted).
 * @param Length Data array length
 * @return Median value of the passed data
 */
int Median(int* ArrayBuffer, int Length);

#endif /* MEDIAN_H_ */
