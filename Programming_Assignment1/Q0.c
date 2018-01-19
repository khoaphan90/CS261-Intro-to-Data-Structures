/***********************************************************
* Author: Khoa Phan
* Date Created: 07/04/17
* Last Modification Date: 07/09/17
* Filename: Q0.c
*
* Overview:
* This program is a practice with pointers in C.
*
*
* Input:
* No user input.
*
* Output:
* Prints out the address and value of the pointer, correctly
* pass to the function.
*
*
************************************************************/

#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr)
{
	/*Print the value pointed to by iptr*/
	printf("Value of pointed iptr: %d\n", *iptr);

	/*Print the address pointed to by iptr*/
	printf("Address of pointed iptr: %p\n", iptr);

	/*Print the address of iptr itself*/
	printf("Address of iptr: %p\n", &iptr);
}

int main()
{

	/*declare an integer x*/
	int x = 19;

	/*print the address of x*/
	printf("Address of X: %p\n", &x);

	/*Call fooA() with the address of x*/
	fooA(&x);

	/*print the value of x*/
	printf("Value of X: %i\n", x);

		return 0;
}
