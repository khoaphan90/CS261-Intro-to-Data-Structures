/***********************************************************
* Author: Khoa Phan
* Date Created: 07/04/17
* Last Modification Date: 07/09/17
* Filename: Q5.c
*
* Overview:
* Program practicing pointers.Take a string and converts it 
* to a 'sticky caps' format.
*
* Input:
* User inputs a string of characters.
*
* Output:
* The string of characters are converted to "sticky caps".
*
* Example: 
*	Enter a string: teststring
*	New string: TeStStRiNg
*
************************************************************/

#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
     /*Convert to sticky caps*/

	// get string length
	int s = 0;
	while (word[s] != '\0')
		s++;

	// check each char
	for (int i = 0; i < (s - 1); i++)
	{
		// if even, check casing
		if (i % 2 == 0)
		{
			if (word[i] >= 'a' && word[i] <= 'z')
				word[i] = toUpperCase(word[i]);
		}
		else // anything not even
		{
			if (word[i] >= 'A' && word[i] <= 'Z')
				word[i] = toLowerCase(word[i]);
		}
	}
}

int main(){

	char word[256];

    /*Read word from the keyboard using scanf*/
	printf("Enter a word: ");
	scanf("%s", word);
    
    /*Call sticky*/
	sticky(word);
    
    /*Print the new word*/
	printf("New word: %s\n", word);
    
    return 0;
}
