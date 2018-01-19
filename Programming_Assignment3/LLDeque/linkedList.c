/***********************************************************
* Author: Khoa Phan
* Date Created: 07/18/17
* Last Modification Date: 07/13/17
* Filename: linkedList.c
*
* Overview:
* This program is a practice with linked list, queue and
* deques as well as bags.
*
* Input:
* No user input.
*
* Output:
* No output (test file).
*
************************************************************/

#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Double link
struct Link
{
	TYPE value;
	struct Link* next;
	struct Link* prev;
};

// Double linked list with front and back sentinels
struct LinkedList
{
	int size;
	struct Link* frontSentinel;
	struct Link* backSentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinels' next and prev should point to eachother or NULL
 * as appropriate.
 */
static void init(struct LinkedList* list) {
	// FIXME: you must write this
	assert(list != 0);

	// create sentinels and check
	list->frontSentinel = (struct Link *) malloc(sizeof(struct Link));
	list->backSentinel = (struct Link *) malloc(sizeof(struct Link));
	assert(list->frontSentinel != 0);
	assert(list->backSentinel != 0);

	// set sentinel links
	list->frontSentinel->next = list->backSentinel;
	list->backSentinel->prev = list->frontSentinel;

	// set size
	list->size = 0;
}

/**
 * Adds a new link with the given value before the given link and
 * increments the list's size.
 */
static void addLinkBefore(struct LinkedList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this
	assert(list != 0);
	assert(link != 0);

	// create new link 
	struct Link * newLink = (struct Link *) malloc(sizeof(struct Link));

	// set new links 
	newLink->value = value;
	newLink->next = link;
	newLink->prev = link->prev;

	link->prev->next = newLink;
	link->prev = newLink;

	list->size++;

}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct LinkedList* list, struct Link* link)
{
	// FIXME: you must write this
	assert(list != 0);
	assert(link != 0);

	// set link's next and prev
	link->prev->next = link->next;
	link->next->prev = link->prev;

	// remove link
	free(link);

	list->size--;
}

/**
 * Allocates and initializes a list.
 */
struct LinkedList* linkedListCreate()
{
	struct LinkedList* newDeque = malloc(sizeof(struct LinkedList));
	init(newDeque);
	return newDeque;
}

/**
 * Deallocates every link in the list including the sentinels,
 * and frees the list itself.
 */
void linkedListDestroy(struct LinkedList* list)
{
	while (!linkedListIsEmpty(list))
	{
		linkedListRemoveFront(list);
	}
	free(list->frontSentinel);
	free(list->backSentinel);
	free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void linkedListAddFront(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	assert(list != 0);
	addLinkBefore(list, list->frontSentinel->next, value);

}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void linkedListAddBack(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	assert(list != 0);
	addLinkBefore(list, list->backSentinel, value);
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE linkedListFront(struct LinkedList* list)
{
	// FIXME: you must write this
	assert(list != 0);
	assert(list->size != 0);

	return(list->frontSentinel->next->value);
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE linkedListBack(struct LinkedList* list)
{
	// FIXME: you must write this
	assert(list != 0);
	assert(list->size != 0);

	return(list->backSentinel->prev->value);
}

/**
 * Removes the link at the front of the deque.
 */
void linkedListRemoveFront(struct LinkedList* list)
{
	// FIXME: you must write this
	assert(list != 0);
	assert(list->size != 0);

	removeLink(list, list->frontSentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void linkedListRemoveBack(struct LinkedList* list)
{
	// FIXME: you must write this
	assert(list != 0);
	assert(list->size != 0);

	removeLink(list, list->backSentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int linkedListIsEmpty(struct LinkedList* list)
{
	// FIXME: you must write this
	assert(list != 0);

	if (list->size > 0)
		return 0;
	else
		return 1;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void linkedListPrint(struct LinkedList* list)
{
	// FIXME: you must write this
	assert(list != 0);
	struct Link *current = list->frontSentinel;
	
	// variable for ID
	int count = 1;

	while (current != list->backSentinel->prev)
	{
		current = current->next;
		printf("Value %i: %d\n", count, current->value);
		count++;
	}
}

/**
 * Adds a link with the given value to the bag.
 */
void linkedListAdd(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	assert(list != 0);
	linkedListAddFront(list, value);
}

/**
 * Returns 1 if a link with the value is in the bag and 0 otherwise.
 */
int linkedListContains(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	assert(list != 0);
	assert(list->size != 0);

	struct Link * current = list->frontSentinel->next;

	// find value within linked list
	for (int i = 0; i < list->size; i++)
	{
		if (EQ(current->value, value))
		{
			free(current);
			return 1;
		}
		else
		 current = current->next;
	}
	free(current);
	return 0;
}

/**
 * Removes the first occurrence of a link with the given value.
 */
void linkedListRemove(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	assert(list != 0);
	assert(list->size > 0);

	struct Link * current = list->frontSentinel;

	// find value within linked list
	for (int i = 0; i < list->size; i++)
	{
		if (EQ(current->value, value))
			removeLink(list, current);
		else
			current = current->next;
	}
}
