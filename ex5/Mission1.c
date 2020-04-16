/******************************************
*Student name: ben azoulay
*Student ID: 
*Submit Info: 
*Exercise name: ex5
******************************************/ 
#include "Mission1.h"
/************************************************************************
* function name: mission1 											    *
* The Input: target - The target string containing a-z letters 			*
* 			 source - The source string containing a-z letters			*
* The output: The function print how many time the 2 string are the     *
*			  same each for all the row                                 *
* The Function operation: The function call the isSemiSimilar           *
*              function checks first string equal to second string      *
*			   every row and return the associated value of counter     *
*************************************************************************/
void mission1()
{
	/* 
	initalize variables 
	n :  the amount of pair input
	i, l : indexes of for 
	count :  to count each time similar similar 
	string appear.
	semisimilar : to take the value of 
	the returned function.
	arrays, source and target :  to the first 
	string input each row and the second.
	*/
	int n, i, l = 0, count = 0;
	int semiSimilar;
	char source[SIZE_MAX], target[SIZE_MAX];
	printf("Please enter the amount of pairs:\n");
	// Input the n
	scanf("%d", &n);
	// if n is not in the given range return to main menu (1-> 10000)
	if(n> HIGH_RANGE || n< LOW_RANGE)
	{
		return;
	}
	else
	{
		//input of the two string n time
		for (i = 0; i < n; i++)
		{
			printf("Please enter the first string of pair %d:\n", i + 1);
			//  input the first string (target)
			scanf("%s", target);
			for (l = 0; l < strlen(target); l++)
			{
				// if target is not in the given range return to main menu (a->z)
				if (target[l] > Z_LOW_LETTER || target[l] < A_LOW_LETTER)
				{
					return;
				}
			}
			printf("Please enter the second string pair %d:\n", i + 1);
			//  input the second string (source)
			scanf("%s", source);
			for (l = 0; l < strlen(source); l++)
			{
				// if source is not in the given range return to main menu (a->z)
				if (source[l] > Z_LOW_LETTER || source[l] < A_LOW_LETTER)
				{
					return;
				}
			}
			/* 
			here we call the function isSemiSimilar(target, source)
			with the first string and the second stig od the n row
			assign it to semiSimilar variable.
			*/
			semiSimilar = isSemiSimilar(target, source);
			/* 
			if semisimilar did not return -1 it means
			that there is no error so it return the current 
			counter and add it to the counter var of previous 
			step.
			else it return to the main menu
			*/
			if (semiSimilar != -1) {
				count += isSemiSimilar(target, source);
			}
			else
			{
				return;
			}
		}
		//print the result 
		printf("The amount of Semi-Similar strings is %d\n", count);
	}
}
/************************************************************************
* function name: isSemiSimilar 											*
* The Input: target - The target string containing a-z letters 			*
* 			 source - The source string containing a-z letters			*
* The output: The function returns 1 or 0 (or -1 if error)				*
* The Function operation: The function checks if target is 				*
*						   semi-similar to source 						*
*************************************************************************/ 
int isSemiSimilar(char target[], char source[])
{
	/*
	initalize variables
	j, k : indexes of for
	equalCounter :  to count each time same letter appear
	in the two strings.
	arrays, sourceHelper and targetHelper :  to keep 
	the value of the first string and the second.
	*/
	int j, k;
	int equalCounter = 0;
	char sourceHelper[SIZE_MAX], targetHelper[SIZE_MAX];
	// copy value source string to sourceHelper string 
	strcpy(sourceHelper, source);
	// copy value target string to targetHelper string 
	strcpy(targetHelper, target);
	/*
	here we check if the size of first string is not the
	same than the second and if yes we return 0
	so that the counter for this row will be 0
	else we check inside the two strings
	*/
	if (strlen(target) != strlen(source))
	{
		return 0;
	}
	else 
	{
		// this for in for help us to check if the string are semisimilar 
		for (k = 0; k < strlen(target); k++)
		{
			// if target is not in the given range return -1 (error message)
			if (target[k] > Z_LOW_LETTER || target[k] < A_LOW_LETTER)
			{
				return -1;
			}
			for (j = 0; j < strlen(source); j++)
			{
				// if source is not in the given range return -1 (error message)
				if (source[j] > Z_LOW_LETTER || source[j] < A_LOW_LETTER)
				{
					return -1;
				}
				// if the frst string and the second string have a letter in common
				if (targetHelper[k] == sourceHelper[j])
				{
					/* 
					the same character are now 0 so in the next row we 
					do not compare it another time.
					equalCounter +1 to specify that sameletter are present in 
					the two string
					*/
					targetHelper[k] = '0';
					sourceHelper[j] = '0';
					++equalCounter;
					break;
				}
			}
		}
		/*
		here is the final check to see if the equalCounter equal to 
		the size of one of the two string if yes it means
		that : to each letter of the first string 
		there is the same in the second.
		if yes return 1 to add to the row counter of the mission1
		else add 0 so the counter not change
		*/
		if (equalCounter == strlen(target))
		{
			return 1;
		}
		else 
		{
			return 0;
		}
	}	// Complete
}
