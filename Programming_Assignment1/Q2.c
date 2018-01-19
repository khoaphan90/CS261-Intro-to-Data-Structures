/***********************************************************
* Author: Khoa Phan
* Date Created: 07/04/17
* Last Modification Date: 07/09/17
* Filename: Q2.c
*
* Overview:
* This program is a practice with variables that are
* referenced into a function.
*
* Input:
* No user input.
*
* Output:
* The results of variables that have either been passed by
* value or reference. x and y are passed by reference while
* z is passed by value. This shows that passing by value
* does not change the original variable.
*
************************************************************/

 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
	*a *= 2;

    /*Set b to half its original value*/
	*b /= 2;
    
    /*Assign a+b to c*/
	c = *a + *b;
    
    /*Return c*/
	return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
	int x = 5, y = 6, z = 7;
    
    /*Print the values of x, y and z*/
	printf("Value of X: %i\n", x);
	printf("Value of Y: %i\n", y);
	printf("Value of Z: %i\n\n", z);
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
    /*Print the value returned by foo*/
	printf("Value returned by foo: %i\n\n", foo(&x, &y, z));
    
    /*Print the values of x, y and z again*/
	printf("Value of X: %i\n", x);
	printf("Value of Y: %i\n", y);
	printf("Value of Z: %i\n", z);
 
    /*Is the return value different than the value of z?  Why?*/
	// Yes, because Z was passed in as a value, thus creating a copy of Z. This value(c)
	// was then modified by a(x) and b(y), which were passed as references due to 
	// a and b being pointed variables. X and Y as pointers, were changed directly
	// changed, thus why they have new values.

    return 0;
}
    
    
