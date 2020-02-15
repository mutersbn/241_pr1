/*	Author: Noah Mutersbaugh 
 *	Date: 02/12/2020 
 *	Name of File: sort.c
 *	Description: This file holds the logic for each function used for this
 *	project. 
 */

/* Included header files. */
#include <stdio.h>  
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>
#include "sort.h"


/*	Function: create_array()
 *	Arguments: int size_of_array 
 *	Return Type: pointer to an int array Description: Creates an array of
 *	size 'size_of_array' and stores in pointer '*array'
 */
int * CreateArray(int size_of_array)
{
	/* Local Variables. */
	int * array;

	array = (int*)malloc(size_of_array*sizeof(int));

	if(array == NULL)
	{ 
		printf("Memory not allocated."); 
		exit(0);
	}

	/* Seed the Random Number Generator (RNG) with the current time.  
	 * This will ensure that each randomly generated array has different
	 * values.
	 */
	srand(time(0));
	for(int i=0; i<size_of_array; i++)
	{ 
		array[i] = rand();
	}

	return array;
}

/*
*	Function: selection() 
*	Arguments: pointer to array, size of array
*	Return Type: int
*	Description: Selection sort using an array generated using the function
*	'CreateArray'
*/
int SelectionSort(int * array, int size_of_array)
{
	/* Local variables. */
	int min_location, i, n, k;
	double avg_time_ms, best_time_ms, sum_ms=0, ms;

	/* Loop through the entire array, starting at the first position. */
	for(i=0; i < size_of_array; i++)
	{
		/* 
		 * Minimum location set to the first element 
		 * in the array from 'array[i .. size_of_array]'
		 */
		min_location = i;

		/* 
		 * See if any numbers past 'i' are smaller than
		 * 'array[i]'
		 */
		for(n = min_location; n < size_of_array; n++)
		{
			/* Remember this new minimum location. */
			if(array[n] < array[min_location])
			{
				min_location = n;
			}
		}
		
		Swap(&array[i], &array[min_location]);
	}

	if(size_of_array < 50)
	{
		DottedLine();
		printf("\nSorted Selection Array:");
		PrintArray(array, size_of_array);
	}
	
	DottedLine();
	printf("\nSelection Sort Output:");

	return 1; 
}

/*
 * Function: BubbleSort()
 * Arguments: pointer to int array, size of array
 * Return Type: int
 * Description: Sorting method using Bubble Sort technique.
 */
int BubbleSort(int * array, int size_of_array)
{
	/* Local Variables. */
	int i, j, k;

	for(i=0; i < size_of_array - 1; i++)
	{
		for(j=0; j < size_of_array - i - 1; j++)
		{
			if(array[j] > array[j+1]) // If the next number is smaller..
			{
				Swap(&array[j], &array[j+1]); // Switch these 2 numbers
			}
		}
	}

	if(size_of_array < 50)
	{
		DottedLine();
		printf("\nSorted Bubble Array:");
		PrintArray(array, size_of_array);
	}

	DottedLine();
	printf("\nBubble Sort Output:");

	return 1;
}

/*
 * Function: PrintArray()
 * Arguments: pointer to array, size of array
 * Return Type: void
 * Description: Helper function to print out an array when passed its pointer.
 */
void PrintArray(int * array, int size_of_array)
{
	/* Local Variables. */
	int i;

	for(i = 0; i < size_of_array; i++)
	{
		if(i%5==0)
		{
			printf("\n");
		}
		printf("%16d\t", array[i]);
	}
}

/*
 * Function: PrintOutput()
 * Arguments: size of array, algorithm used, average time for each swap, best
 * time of all the swaps
 * Return Type: void
 * Description: Helper function to print a readable output.
 */
void PrintOutput(int size_of_array, int algorithm, double avg_time, double
		best_time)
{
	char * algorithm_str;

	if(algorithm == 1)
	{
		algorithm_str = "Selection";
	}
	else if(algorithm == 2)
	{
		algorithm_str = "Bubble";
	}

	printf("\n%16s\t%16s\t%16s\t%16s", "Array_Size", "Algorithm", "Average(ms)",
			"Best(ms)");
	printf("\n%16d\t%16s\t%16f\t%16f", size_of_array, algorithm_str, avg_time, best_time);
}

/*
 * Function: Swap()
 * Arguments: two integers
 * Return Type: void
 * Description: Swaps two integer's storage location.
 */
void Swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*
 * Function: DottedLine()
 * Arguments: none
 * Return Type: void
 * Description: Creates a line of dashes for easily separating parts of the
 * project.
 */
void DottedLine()
{
	printf("\n");
	for(int x=0; x<112; x++)
	{
		printf("-");
	}
}

/*
 * Function: CopyArray()
 * Arguments: pointer to an array
 * Return Type: pointer to another array
 * Description: Loop through Original array and copy all data over to a
 * secondary array.
 */
int * CopyArray(int * array1, int * array2, int size_of_array)
{
	array2 = (int*)malloc(size_of_array*sizeof(int));

	if(array2 == NULL)
	{
		printf("\nMemory not allocated. Aborting.\n");
		exit(0);
	}

	for(int i=0; i<size_of_array; i++)
	{
		array2[i] = array1[i];
	}

	return array2;
}
