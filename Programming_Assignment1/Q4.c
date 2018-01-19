/***********************************************************
* Author: Khoa Phan
* Date Created: 07/04/17
* Last Modification Date: 07/09/17
* Filename: Q4.c
*
* Overview:
* This program is a practice with memory and the creation of
* new structures with the C programming style and the use
* of sorting this data based on a member variable of the 
* structure.
*
* Input:
* No user input.
*
* Output:
* A list of student IDs and scores are printed to the screen.
* Each student is stored within a structure and has randomized
* IDs and scores. It is then soreted in order ascending from
* lowest score to highest.
*
* ID10 Score: 48
* ID5  Score: 87
* ID2  Score: 99
* etc.
*
************************************************************/

 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/   

	int swapped;

	while (1)
	{
		// check if all numbers have been swapped
		swapped = 0;

		// swap numbers, bubble sorted
		for (int i = 0; i < n - 1; i++)
			if (students[i].score > students[i + 1].score)
			{
				int temp = students[i].score;
				students[i].score = students[i + 1].score;
				students[i + 1].score = temp;
				swapped = 1;
			}

		// break if no more swapping has occured
		if (swapped == 0)
			break;
	}
}

int main(){
	// Declare students pointer
	struct student* students = NULL;

    /*Declare an integer n and assign it a value.*/
	int n = 16, counter = 0;
    
    /*Allocate memory for n students using malloc.*/
	struct student* sPtr = malloc(n * sizeof(struct student));
	students = sPtr;

	/*Generate random and unique ID and scores for ten students, 
	ID being between 1 and 10, scores between 0 and 100*/

	// assigns default value to each student ID
	for (int i = 0; i != n; i++)
		students[i].id = 0;

 	// loop until # of students all have unique IDs
 	while (counter < n)
 	{
 		// generates random values for ID and score
 		int intAssign = (rand() % n) + 1;
 		int scoreAssign = (rand() % 101);
 
 		// check array for duplicates, assign values
 		for (int i = 0; i < n; i++)
 		{
 			if (students[i].id == intAssign)
 				break;

 			else if (students[i].id == 0)
 			{
 				students[i].id = intAssign;
 				students[i].score = scoreAssign;
 				counter++;
 				break;
 			}
 		}
 	}
    
    /*Print the contents of the array of n students.*/
	printf("***Pre-Sorted Array***\n");
 	for (int i = 0; i < n; i++)
 		printf("ID%d: Score: %d\n", students[i].id, students[i].score);
 
     /*Pass this array along with n to the sort() function*/
 	sort(students, n);
     
     /*Print the contents of the array of n students.*/
	printf("\n***Sorted Array***\n");
 	for (int i = 0; i < n; i++)
 		printf("ID%d: Score: %d\n", students[i].id, students[i].score);
    
    return 0;
}