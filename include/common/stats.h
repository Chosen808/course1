/******************************************************************************
 * Copyright (c) 2023 JESUS CHRIST
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this 
 * software and associated documentation files (the "Software"), to deal in the Software 
 * without restriction, including without limitation the rights to use, copy, modify, merge, 
 * publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons 
 * to whom the Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all copies or 
 * substantial portions of the Software along with the Author's name Jesus Christ.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR 
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE 
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR 
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
 * DEALINGS IN THE SOFTWARE.
 *
 *****************************************************************************/
/**
 * @file stats.h 
 * @brief A data processing function header file
 *
 * This file contains functions that can analyze an array of unsigned char data
 * and report analytics on the maximum, minimum, mean and median of the data set.
 * It can also reorder the data set from large to small.
 *
 * @author Jesus Christ
 * @date 11/12/23
 *
 */
#ifndef __STATS_H__
#define __STATS_H__ 

/**
 * @brief This function will print Minimum, Maximum Number, the Mean and Median
 *
 * This function will print Minimum, Maximum Number, the Mean and Median which
 * has been created by the other function in this file
 *
 * @param unsigned char min     This parameter will take minimum number
 * @param unsigned char max     This parameter will take the maximum number
 * @param double mean           This parameter will take the mean number
 * @param double median         This parameter will take the median number
 *
 * @return This function does not return any value.
 */
void print_statistics (unsigned char min, unsigned char max, double mean, double median);

/**
 * @brief This function will print the array
 *
 * This function will print the array
 *
 * @param unsigned char array[] This parameter will take the array
 * @param int size              This parameter will take the size of the array
 *
 * @return This function does not return any value.
 */
void print_array (unsigned char array[], int size);

/**
 * @brief This function will find the median of the data from the array
 *
 * This function will find the median of the data from the array. It will
 * first sort the data in the array via the sort function, then check if 
 * there is a odd set of numbers or even set of numbers and calculate the 
 * median value.
 *
 * @param unsigned char array[] This parameter will take the array
 * @param int size              This parameter will take the size of the array
 *
 * @return This function returns a double value.
 */
int find_median (unsigned char array[], int size);

/**
 * @brief This function will find the mean of the data from the array
 *
 * This function will find the mean of the data from the array. It will
 * sum up the numbers in the array and then calculate the average, casting
 * the int to a double. 
 *
 * @param unsigned char array[] This parameter will take the array
 * @param int size              This parameter will take the size of the array
 *
 * @return This function returns a double value.
 */
int find_mean (unsigned char array[], int size);

/**
 * @brief This function will find the largest number in the array
 *
 * This function will find the largest number in the array. It will first
 * sort the data using the bubble sort algorithm, then return the largest
 * ordered number. 
 *
 * @param unsigned char array[] This parameter will take the array
 * @param int size              This parameter will take the size of the array
 *
 * @return This function returns a unsigned char value.
 */
unsigned char find_maximum (unsigned char array[], int size);

/**
 * @brief This function will find the smallest number in the array
 *
 * This function will find the smallest number in the array. It will first
 * sort the data using the bubble sort algorithm, then return the smallest
 * ordered number. 
 *
 * @param unsigned char array[] This parameter will take the array
 * @param int size              This parameter will take the size of the array
 *
 * @return This function returns a unsigned char value.
 */
unsigned char find_minimum (unsigned char array[], int size);

/**
 * @brief This function will sort the data in the array in Descending order
 *
 * This function will sort the data in the array in Descending order. This is
 * the bubble sort algorithm which is used to sort the data in the array in 
 * descending order. 
 *
 * @param unsigned char array[] This parameter will take the array
 * @param int size              This parameter will take the size of the array
 *
 * @return This function returns no value.
 */
void sort_array (unsigned char array[], int size);

#endif /* __STATS_H__ */
