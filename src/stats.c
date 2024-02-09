/******************************************************************************
 * Copyright (c) 2023 JESUS CHRIST
 * 
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
 * @file stats.c 
 * @brief This main file will calculate the mean, median, maximum and minimum of the array and will sort its values
 *
 * 
 *
 * @author Jesus Christ
 * @date 12/12/23
 *
 */


#include "stats.h"
#include <stdio.h>
#include <stdlib.h>

/* Size of the Data Set */
#define SIZE (40)

/*
This function will print Minimum, Maximum Number, the Mean and Median
*/
void print_statistics (unsigned char min, unsigned char max, double mean, double median)
{
    // Various values will be printed here
    printf ("The Minimum Number is %d \n", min);
    printf ("The Maximum Number is %d \n", max);
    printf ("The Mean is %.0f \n", mean);
    printf ("The Median is %.0f \n", median);
}

/*
This function will print the array
*/
void print_array (unsigned char array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf ("Array %d = %d \n", i, array[i]);
    }
}

/*
This function will find the median of the data from the array
*/
int find_median (unsigned char array[], int size)
{
    sort_array (array, size); // This will call the sort function and arrange all numbers in the array

    // The statement will check if the number of values are odd
    if (size % 2 == 1)
    {
        int index = (size / 2);

        return array[index];
        
    }

    // This statement will check if the number of values are even
    else if (size % 2 == 0)
    {
        int index1 = (size / 2) - 1;    // The First value will be calculated here
        int index2 = (size / 2);    // The Second value will be calculated here

        int median = (double)(array[index1] + array[index2]) / 2;    // The median will be calculated here

        return median;
    }

    return 0.0;
}

/*
This function will find the mean of the data from the array
*/
int find_mean (unsigned char array[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }

    int average = (double)sum / size;

    return average;
}

/*
This function will find the largest number in the array
*/
unsigned char find_maximum (unsigned char array[], int size)
{
    unsigned char temp; 

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            // Values will be sorted in this statement
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    return array[size - 1];
}

/*
This function will find the smallest number in the array
*/
unsigned char find_minimum (unsigned char array[], int size)
{
    unsigned char temp;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            // Values will be sorted in this statement
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    return array[0];
}

/*
This function will sort the data in the array in Descending order
*/
void sort_array (unsigned char array[], int size)
{
    unsigned char temp;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            // Values will sorted in this statement
            if (array[i] < array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}


int main() 
{

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  // This function will sort the data
  sort_array (test, SIZE);

  // This function will print the sorted data array
  print_array (test, SIZE);

  puts ("\n\n");

  // This function will print the Minimum, Maximum number, the Mean and the Median
  print_statistics (find_minimum (test, SIZE), find_maximum (test, SIZE), find_mean (test, SIZE), find_median (test, SIZE));

  return 0;
}

/* Add other Implementation File Code Here */
