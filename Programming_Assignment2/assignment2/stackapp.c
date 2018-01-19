/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


struct DynArr
{
	TYPE *data;		/* pointer to the data array */
	int size;		/* Number of elements in the array */
	int capacity;	/* capacity ofthe array */
};


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;
	char c = 'a';
	++i;
	c = *(s + i);
	if (c == '\0')
		return '\0';
	else
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
	char c = nextChar(s);
	// new array to check balance
	struct DynArr *checkBalance = newDynArr(20);

	// execute char checking for initial
	do
	{
		switch (c)
		{
			// if encountered, push matching brace to stack
		case '(':
			pushDynArr(checkBalance, ')');
			break;
		case '[':
			pushDynArr(checkBalance, ']');
			break;
		case '{':
			pushDynArr(checkBalance, '}');
			break;
			// check for end brace, pop from stack if true
		case ')':
		case ']':
		case '}':
			if (!(isEmptyDynArr(checkBalance)) && (topDynArr(checkBalance) == c))
				popDynArr(checkBalance);
			else
				return 0; // if top is not matched, it is false
			break;
		default:
			break;
		}
		// set next character to check in loop
		c = nextChar(s);
	} while (c != '\0');

	// if not empty, it is not balanced
	if (!isEmptyDynArr(checkBalance))
		return 0;

	// deallocate memory
	deleteDynArr(checkBalance);
	return 1;
}

int main(int argc, char* argv[]){
	
	char* s = "()()[]{{}}";
	int res;

	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

