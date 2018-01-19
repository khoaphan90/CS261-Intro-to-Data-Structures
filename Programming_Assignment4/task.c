/***********************************************************
* Author: Khoa Phan
* Date Created: 07/29/17
* Last Modification Date: 08/03/17
* Filename: tasks.c
*
* Overview:
* Practice with tasks and priorities.
*
* Input:
* No user input.
*
* Output:
* No output (test file).
*
************************************************************/

#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Creates a new task with the given priority and name.
 * @param priority
 * @param name
 * @return  The new task.
 */
Task* taskNew(int priority, char* name)
{
    // FIXME: implement
	Task *newTask = malloc(sizeof(Task));
	strcpy(newTask->name, name);
	newTask->priority = priority;

	return newTask;
}

/**
 * Frees a dynamically allocated task.
 * @param task
 */
void taskDelete(Task* task)
{
    free(task);
}

/**
 * Casts left and right to Task pointers and returns
 * -1 if left's priority < right's priority,
 *  1 if left's priority > right's priority,
 *  0 if left's priority == right's priority.
 * @param left  Task pointer.
 * @param right  Task pointer.
 * @return 
 */
int taskCompare(void* left, void* right)
{
	// FIXME: implement
	Task* tLeft = (struct Task*)left;
	Task* tRight = (struct Task*)right;

	int compare = 0;

	if (tLeft->priority < tRight->priority)
		compare = -1;
	else if (tLeft->priority > tRight->priority)
		compare = 1;

    return compare;
}

/**
 * Prints a task as a (priority, name) pair.
 * @param value  Task pointer.
 */
void taskPrint(void* value)
{
    Task* task = (Task*)value;
    printf("(%d, %s)", task->priority, task->name);
}
