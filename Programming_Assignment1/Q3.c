/***********************************************************
* Author: Khoa Phan
* Date Created: 07/04/17
* Last Modification Date: 07/09/17
* Filename: Q3.c
*
* Overview:
* Program that allocates memory for an pointer that is then 
* sorted in ascending order based on the value that have
* been randomly generated.
*
* Input:
* No user input.
*
* Output:
* Unsorted-
* 67
* 23
* 45
* 87
* ...
*
* Sorted-
* 23
* 45
* 67
* 87
* ...
*
************************************************************/
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>


void sort(int* number, int n){
     /*Sort the given array number , of length n*/
	int swapped;

	while (1)
	{
		// check if all numbers have been swapped
		swapped = 0;

		// swap numbers, bubble sorted
		for (int i = 0; i < n - 1; i++)
			if (number[i] > number[i + 1])
			{
				int temp = number[i];
				number[i] = number[i + 1];
				number[i + 1] = temp;
				swapped = 1;
			}

		// break if no more swapping has occured
		if (swapped == 0)
			break;
	}
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
	int n = 20;
    
    /*Allocate memory for an array of n integers using malloc.*/
	int* iArray = malloc(n * sizeof(int));
    
    /*Fill this array with random numbers, using rand().*/
	for (int i = 0; i < n; i++)
	{
		int randomNumber = rand() % 101;
		iArray[i] = randomNumber;
	}
    
    /*Print the contents of the array.*/
	printf("***Pre-Sorted Array***\n");
	for (int i = 0; i < n; i++)
		printf("Array[%i] = %i\n", i, iArray[i]);

    /*Pass this array along with n to the sort() function of part a.*/
	sort(iArray, n);

    /*Print the contents of the array.*/
	printf("\n***Sorted Array***\n");
	for (int i = 0; i < n; i++)
		printf("Array[%i] = %i\n", i, iArray[i]);
    
    return 0;
}
