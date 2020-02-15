/*	Author: Noah Mutersbaugh
 *	Date: 02/12/2020
 *	Name of File: sort.h
 *	Description: This header file is only for creating the prototypes of the functions for this project.
 */
#ifndef SORT_H
	#define SORT_H

/* Structure Declarations */
struct RuntimeData
{
	double runtime_ms, sum_ms, avg_time_ms, best_time_ms;
};

int * CreateArray(int size_of_array);
int SelectionSort(int * array, int size_of_array);
int BubbleSort(int * array, int size_of_array);
void PrintArray(int * array, int size_of_array);
void PrintOutput(int size_of_array, int algorithm, double avg_time, double
		best_time);
void Swap(int * a, int * b);
void DottedLine();
int * CopyArray(int * array1, int * array2, int size_of_array);
double * Calculations(struct RuntimeData * algorithm, int count);
	#endif /* SORT_H */
