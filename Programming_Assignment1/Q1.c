/***********************************************************
* Author: Khoa Phan
* Date Created: 07/04/17
* Last Modification Date: 07/09/17
* Filename: Q1.c
*
* Overview:
* This program is a practice with memory and the creation of
* new structures with the C programming style.
*
* Input:
* No user input.
*
* Output:
* A list of student IDs and scores are printed to the screen.
* Each student is stored within a structure and has randomized
* IDs and scores.
* 
* ID10 Score: 48
* ID2  Score: 99
* ID5  Score: 87
* etc.
*
************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int NUM_STUDENTS = 10;

struct student
{
	int id;
	int score;
};

struct student* allocate()
{
	/*Allocate memory for ten students*/
	struct student* sPtr = malloc(NUM_STUDENTS * sizeof(struct student));

	/*return the pointer*/
	return sPtr;
}

void generate(struct student* students)
{
	/*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/

	// keeps track of unique IDs
 	int counter = 0;
 
	// assigns default value to each student ID
 	for (int i = 0; i != NUM_STUDENTS; i++)
 		students[i].id = 0;
 
	// loop until # of students all have unique IDs
 	while (counter < NUM_STUDENTS)
 	{
		// generates random values for ID and score
 		int intAssign = (rand() % 10) + 1;
 		int scoreAssign = (rand() % 101);

		// check array for duplicates, assign values
 		for (int i = 0; i < 10; i++)
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
}

void output(struct student* students)
{
	/*Output information about the ten students in the format:
	ID1 Score1
	ID2 score2
	ID3 score3
	...
	ID10 score10*/

	for (int i = 0; i < 10; i++)
		printf("ID%d: Score: %d\n", students[i].id, students[i].score);
}

void summary(struct student* students)
{
	/*Compute and print the minimum, maximum and average scores of the ten students*/

	int min, max, total = 0, average;

	// set max and min to first value to compare
	max = students[0].score;
	min = students[0].score;

	// compares values to initial, assigns new value if true
	for (int i = 1; i < 10; i++)
	{
		if (students[i].score < min)
			min = students[i].score;
		if (students[i].score > max)
			max = students[i].score;
	}

	// running total of scores
	for (int i = 0; i < 10; i++)
		total += students[i].score;

	// calculates average of scores
	average = total / NUM_STUDENTS;
	
	printf("\n");
	printf("Minimum Score: %i\n", min);
	printf("Maximum Score: %i\n", max);
	printf("Average Score: %i\n", average);
}

void deallocate(struct student* stud)
{
	/*Deallocate memory from stud*/
	free(stud);
}

int main()
{
	// seed random time
	//srand(time(0));
	struct student* stud = NULL;

	/*call allocate*/
	stud = allocate();

	/*call generate*/
	generate(stud);

	/*call output*/
	output(stud);

	/*call summary*/
	summary(stud);

	/*call deallocate*/
	deallocate(stud);

	return 0;
}
