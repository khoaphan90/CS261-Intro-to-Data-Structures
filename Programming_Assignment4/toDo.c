/***********************************************************
* Author: Khoa Phan
* Date Created: 07/29/17
* Last Modification Date: 08/05/17
* Filename: toDo.c
*
* Overview:
* Create a todo list using the task interface
*
* Input:
* Users will have options to read tasks from a file, write a
* file for the tasks, set priorities and exit.
*
* Output:
* If a file is saved, a file with tasks, priority and 
* descriptions will be saved to the default location of the
* program's directory.
*
************************************************************/

#include "dynamicArray.h"
#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Loads into heap a list from a file with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listLoad(DynamicArray* heap, FILE* file)
{
    const int FORMAT_LENGTH = 256;
    char format[FORMAT_LENGTH];
    snprintf(format, FORMAT_LENGTH, "%%d, %%%d[^\n]", TASK_NAME_SIZE);
    
    Task temp;
    while (fscanf(file, format, &temp.priority, &temp.name) == 2)
    {
        dyHeapAdd(heap, taskNew(temp.priority, temp.name), taskCompare);
    }
}

/**
 * Writes to a file all tasks in heap with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listSave(DynamicArray* heap, FILE* file)
{
    for (int i = 0; i < dySize(heap); i++)
    {
        Task* task = dyGet(heap, i);
        fprintf(file, "%d, %s\n", task->priority, task->name);
    }
}

/**
 * Prints every task in heap.
 * @param heap
 */
void listPrint(DynamicArray* heap)
{
    DynamicArray* temp = dyNew(1);
    dyCopy(heap, temp);
     while (dySize(temp) > 0)
    {
        Task* task = dyHeapGetMin(temp);
        printf("\n");
        taskPrint(task);
        printf("\n");
        dyHeapRemoveMin(temp, taskCompare);
    }
    dyDelete(temp);
}

/**
 * Handles the given command.
 * @param list
 * @param command
 */
void handleCommand(DynamicArray* list, char command)
{
    // FIXME: Implement

	// variables for files and task descriptions
	char *filename = malloc(sizeof(char) * 256);
	char *description = malloc(sizeof(char) * 256);
	
	int priority;

	// handle command inputs
	switch (command)
	{
	case 'l': // reads from file inputted by user, prompts success, and closes file
	{
		printf("Enter file name: ");
		fgets(filename, 256, stdin);

		FILE *readFile = fopen(filename, "r");

		if (readFile == NULL)
		{
			printf("Error opening file.\n");
			break;
		}

		listLoad(list, readFile);
		printf("Loading success!\n");
		fclose(readFile);
		break;
	}
	case 's': // allows user to save file with a file name
	{
		printf("Enter file name: ");
		fgets(filename, 256, stdin);

		FILE *writeFile = fopen(filename, "w");
		listSave(list, writeFile);
		printf("File saved!\n");
		fclose(writeFile);
		break;
	}
	case 'a': // user inputted description of new task
	{
		printf("Enter task description: ");
		fgets(description, 256, stdin);

		do
		{
			printf("Enter task priority: ");
			scanf("%d", &priority);

		} while (priority == 0);

		while (getchar() != '\n');

		Task *newTask = taskNew(priority, description);
		dyHeapAdd(list, newTask, taskCompare);
		printf("Task %s has been added.\n", description);
		break;
	}
	case 'g': // gets first task from heap list
	{
		if (dySize(list) != 0)
			printf("First task is: %s\n", ((struct Task*) dyHeapGetMin(list))->name);
		else
			printf("List is empty!\n");
		break;
	}
	case 'r': // removes first task from heap list
	{
		if (dySize(list) == 0)
			printf("List is empty!\n");
		else
		{
			Task* temp = (struct Task*) dyHeapGetMin(list);
			printf("Task %s has been removed!\n", temp->name);
			dyHeapRemoveMin(list, taskCompare);
			taskDelete(temp);
		}
		break;
	}
	case 'p': // prints list of tasks
	{
		if (dySize(list) == 0)
			printf("List is empty!\n");
		else
			listPrint(list);
		break;
	}
	case 'e': // exits program
	{
		printf("Exiting program.\n");
		break;
	}
	default:
		printf("Invalid option\n");
	}
	free(filename);
	free(description);
}

int main()
{
    // Implement
    printf("\n\n** TO-DO LIST APPLICATION **\n\n");
    DynamicArray* list = dyNew(8);
    char command = ' ';
    do
    {
        printf("Press:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n"
        );
        command = getchar();
        // Eat newlines
        while (getchar() != '\n');
        handleCommand(list, command);
    }
    while (command != 'e');
 /* free dynamically allocated List pointers in array to avoid memory leaks */
         /* Fix it */
	// loop through all task and delete, deallocate
	for (int i = 0; i < dySize(list); i++)
	{
		Task* temp = dyGet(list, i);
		taskDelete(temp);
	}

    dyDelete(list);
    return 0;
}