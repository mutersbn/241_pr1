#include <stdio.h>
#include <stdlib.h>
#include "test.h"

int main()
{
	//int * main_array1 = (int*)malloc(3*sizeof(int));
	//int * main_array2 = (int*)malloc(3*sizeof(int));
/*
	for(int i=0; i<3; i++)
	{
		main_array1[i] = array1
	}
*/
	int * main_array1;
	main_array1 = array1();

	int * main_array2;
	main_array2 = array2();
	printf("Array 1 Location: %pn\nArray 2 Location: %pn\n", main_array1,
			main_array2);
	return 1;
}

int * array1()
{
	int array[] = { 1, 2, 3 };
	return array;
}

int * array2()
{
	int array[] = { 100, 200, 300 };
	return array;
}
