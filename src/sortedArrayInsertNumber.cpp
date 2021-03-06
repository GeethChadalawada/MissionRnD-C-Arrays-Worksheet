/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int i = 0, j = 0;

	if (Arr == NULL || len <= 0)
		Arr = NULL;
	else if (num >= Arr[len - 1])
		Arr[len] = num;
	else
	{
		i = len - 1;
		while (num < Arr[i] && i >= 0)
		{
			Arr[i + 1] = Arr[i];
			i--;
		}
		Arr[i + 1] = num;

	}

	return Arr;
}