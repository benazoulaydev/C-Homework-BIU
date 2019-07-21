/******************************************
*Student name: ben azoulay
*Student ID: 330485269
*Submit Info: azoualb1
*Exercise name: ex5
******************************************/
#include "Mission3.h"
/************************************************************************
* function name: mission3 											    *
* The Input: A string													*
* The output:  if the string a palindrome print it (lexically order)    *
* The Function operation: figure out whether any anagram of the string 	*
			can be a palindrome or not.									*
*************************************************************************/
void mission3()
{
	/*
	initalize variables
	i: index of for
	str[] for a char array
	*/
	int i;
	char str[MAX_STRING];
	printf("Please enter the string:\n");
	scanf("%s", str);	// input the str
	// this for to check each value in array are in the given range (a->z)
	for (i = 0; i < strlen(str); i++) {
		// if not in the given range return to the main menu
		if (str[i] > Z_LOW_LET || str[i] < A_LOW_LET)
		{
			return;
		}
	}
	//call the function that will check if the string have a palindrome
	canAnagram(str);
}
/************************************************************************
* function name: canAnagram 											*
* the input: str - string containing a-z letters 						*
* the output: none														*
* the function operation: the function prints if str can be changed to 	*
							be a polindrom								*
*************************************************************************/
void canAnagram(char str[])
{
	/*
	initalize variables
	i, j, k , l ,m ,n : indexes of for
	- counter of alone char 
	- keepStr : to copy the initial value of string
	- keepChar : will help us to keep the value of 
	the alone char if it exist
	- strHelper the array that will be at the end the 
	polindrom if it exist
	- strLeft for the left side of the arr aranged 
	- evenOrOdd to know if the str is long is even or odd
	*/
	int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, counter = 0;
	char keepChar = '0';
	int keepIndex = 0;
	char keepStr[MAX_STRING];
	char strHelper[MAX_STRING];
	char strLeft[MAX_STRING];
	int evenOrOdd = strlen(str) % 2;
	// copy the value of str to keepstr and strHelper
	strcpy(keepStr, str);
	strcpy(strHelper, str);
	//here we call the sortArray func that sort arr from A to Z
	sortArray(str, strlen(str));
	// if str is only one letter print the letter and return to main menu
	if (strlen(str) == 1)
	{
		printf("The string %s has the palindrome %s \n", str, str);
		return;
	}
	// while form index 0 to the size of the str
	while (strlen(str) > i)
	{
		// if the number is even 
		if (evenOrOdd == 0)
		{
			/*
			if there is a character alone 
			(only one like that)  or not 2 by 2
			it is not palindrome 
			else i+2 to check the two next number in the next row
			*/
			if (str[i] != str[i + 1])
			{
				printf("The string %s does not have a palindrome\n", keepStr);
				return;
			}
			else
			{
				i += 2;
			}
		}
		else
		{
			/* 
			here the size string is odd so there is one 
			char that is alone and the rest 2 by 2
			we are good but we have to register it in a variable 
			next time it will not be possible
			else i+2 to check the two next number in the next row
			*/
			if (str[i] != str[i + 1])
			{
				++counter;
				keepChar = str[i];
				keepIndex = i;
				++i;
			}
			else
			{
				i += 2;
			}
			/* 
			if counter is greater than 1 that mean there
			is more than one char alone so it no palindrome
			*/
			if (counter > 1)
			{
				printf("The string %s does not have a palindrome\n", keepStr);
				return ;
			}
		}
	}
	//if the number is odd keepchar has the value of the alone var
	if (keepChar != '0') 
	{
		// remove the character alone
		for (j = keepIndex; j < strlen(str) - 1; j++)
		{
			str[j] = str[j + 1];
		}
		str[j] = '\0';
	}
	// make the double character to only one
	for (n = 0; n <= strlen(str); n += 2)
	{
		strLeft[k] = str[n];
		k++;
	}
	// make the left side of the array 
	for (m = 0; m < (strlen(str) / 2); m++)
	{
		strHelper[m] = strLeft[m];
	}
	// make the center  of the array if it is odd
	if (evenOrOdd != 0)
	{
		strHelper[m] = keepChar;
	}
	/* 
	make the right side of the array
	the right side is the same as the left side before created 
	so we copy the left side in the inverse order
	*/
	for (l = 0; l <= (strlen(str) / 2) - 1; l++)
	{
		//if even
		if (evenOrOdd != 0)
		{
			strHelper[(strlen(strHelper) / 2) + 1 + l] = strLeft[strlen(strLeft) - 1 - l];
		}
		else //if odd
		{
			strHelper[(strlen(strHelper) / 2) + l] = strLeft[strlen(strLeft) - 1 - l];
		}
	}
	printf("The string %s has the palindrome %s \n", keepStr, strHelper);
}
/************************************************************************
* function name: swaper													*
* The Input:  a char array, i, j indexes								*
* The output: swap two value in array									*
* The Function operation: the function swap two value in arrays     	*
*************************************************************************/
void swaper(char arr[], int i, int j)
{
	char tmp;
	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}
/************************************************************************
* function name: sortArr												*
* The Input:  char array, the array size					    		*
* The output: the swap array in order									*
* The Function operation: the function swap array char until it is in   *
* the logical order		(a, b, c,....)									*
*************************************************************************/
char  sortArray(char arr[], int size)
{
	int i, j;
	//go over the array
	for (i = 0; i < size - 1; i++) {
		//for each element in the array
		for (j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) 
			{
				//if elements not sorted - swap
				swaper(arr, j, j + 1);
			}
		}
	}
	return arr;
}