/*	Author: Noah Mutersbaugh
 *	Date 02/12/2020
 *	Name of File: p1.c
 *	Description: This is the file that will house the main method, calling all functions in their proper order.
 */

/* Included header files. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include "sort.h"

int main()
{
	int user_input, scanf_return_val, count=1;
	int * array;
	int * selection_array;
	int * bubble_array;

	struct timespec start, end;
	struct RuntimeData selection, bubble;

	while(1)
	{
		DottedLine();
		printf("\nPlease input the size of the array: ");
		scanf_return_val = scanf("%d", &user_input);
		
		while((getchar()) != '\n');

		if(user_input < 1 || 
				scanf_return_val < 1 ||
				user_input > 1000000)
		{
			printf("I'm sorry, this input is not valid. Goodbye.\n");
			return -1;
		}

		array = CreateArray(user_input); /* Original array, used for both
											sorting methods for accurate
											measurements. */
		selection_array = CopyArray(array, selection_array, user_input); 
		bubble_array = CopyArray(array, bubble_array, user_input);
		
		/* Run Selection Sort */
		clock_gettime(CLOCK_MONOTONIC_RAW, &start);
		SelectionSort(selection_array, user_input);
		clock_gettime(CLOCK_MONOTONIC_RAW, &end);

		/* Selection Array Calculations */
		selection.runtime_ms = (end.tv_sec - start.tv_sec) * 1000.0f + 
				(end.tv_nsec - start.tv_nsec) / 1000000.0f;
		selection.sum_ms += selection.runtime_ms;
		selection.avg_time_ms = selection.sum_ms / count;

		if(count != 1)
		{
			if(selection.runtime_ms < selection.best_time_ms)
			{
				selection.best_time_ms = selection.runtime_ms;
			}
		}
		else // If this is the first run, set this as the best time
		{
			selection.best_time_ms = selection.runtime_ms;
		}

		PrintOutput(user_input, 1, selection.avg_time_ms,
				selection.best_time_ms);

		/* Run Bubble Sort */
		clock_gettime(CLOCK_MONOTONIC_RAW, &start);
		BubbleSort(bubble_array, user_input);
		clock_gettime(CLOCK_MONOTONIC_RAW, &end);
		
		/* Bubble Sort Calculations */
		bubble.runtime_ms = (end.tv_sec - start.tv_sec) * 1000.0f + 
				(end.tv_nsec - start.tv_nsec) / 1000000.0f;
		bubble.sum_ms += bubble.runtime_ms;
		bubble.avg_time_ms = bubble.sum_ms / count;

		if(count != 1)
		{
			if(bubble.runtime_ms < bubble.best_time_ms)
			{
				bubble.best_time_ms = bubble.runtime_ms;
			}
		}
		else // If this is the first run, set this as the best time
		{
			bubble.best_time_ms = bubble.runtime_ms;
		}

		PrintOutput(user_input, 2, bubble.avg_time_ms,
				bubble.best_time_ms);

		fflush(stdin);
		free(array);
		free(selection_array);
		free(bubble_array);
		count++;
	}
	return 0;
}
