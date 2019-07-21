/******************************************
*Student name: ben azoulay
*Student ID: 330485269
*Submit Info: azoualb1
*Exercise name: ex5
******************************************/
#include "Mission2.h"
/************************************************************************
* function name: mission2 											    *
* The Input: You are given Cookie monster's cookies 					*
* 			 You are given the desired sweetness						*
* The output:  Print the number of operations required to give the      *
			   cookies a sweetness >= K	    						    *
* The Function operation: Cookie monster loves cookies. He wants the    *
	sweetness of all his cookies to be greater than value K.			*
	To do this, Cookie monster repeatedly mixes two cookies with		*
	the least sweetness. He creates a special combined cookie with:		*
	sweetness = (1*(Least Swee cookie)+2*(2ndLeast Swee cookie))		*
	He repeats this procedure until all the cookies in his collection	*
	have a sweetness >= K. Print -1 if this isn't possible.             *
*************************************************************************/
void mission2()
{
	/*
	initalize variables
	n :  the amount of cookie 
	sweet : the required sweetness
	i: index of for
	result for the final result by calling the func
	sweetCookies
	*/
	int n, sweet;
	int cookies[COOKIE_SIZE_MAX];
	int i;
	int result;
	printf("Please enter the amount of cookies:\n");
	scanf("%d", &n); // Reading the amount of cookies
	/* 
	if amount of cookies is not in the given 
	range return to main menu (1-> 1000)
	*/
	if (n > COOKIE_SIZE_MAX || n < COOKIE_SIZE_MIN)
	{
		return;
	}
	printf("Please enter the minimum required sweetness:\n");
	scanf("%d", &sweet); // Reading the desired sweetness
	/*
	if  the desired sweetness is not in the given
	range return to main menu (1-> 10000)
	*/
	if (sweet > MAX_SWEETNESS || sweet < MIN_SWEETNESS)
	{
		return;
	}
	for (i = 0; i < n; i++)
	{
		printf("Please enter cookie number %d:\n", i + 1);
		scanf("%d", &cookies[i]); // Reading the current cookie sweetness
		/*
		if  the current cookie sweetness is not in the given
		range return to main menu (1-> 100000)
		*/
		if (cookies[i] > MAX_COOKIE_I_SWEET || cookies[i] < MIN_COOKIE_I_SWEET) 
		{
			return;
		}
	}
	// result equal of the returned value of the func sweetCookies
	result = sweetCookies(cookies, n, sweet);
	printf("The number of operations that are needed is %d\n", result);
}
/************************************************************************
* function name: sweetCookies 											*
* The Input: cookies[] for the array of cookies							*
* 			 n the amount of cookies, k the desired sweetness			*
* The output: number of step to make all cookies >= desired sweetness	*
* The Function operation: The function each time use the special		*
*  combination sweetness = (Least Swee cookie)+2*(2ndLeast Swee cookie) *
* by calling each time the bubble sort function	to arrange the array 	*
*************************************************************************/
int sweetCookies(int cookies[], int n, int k)
{
	/*
	initalize variables
	count :  counter of step
	i: index of for
	*/
	int count=0;
	int i;
	/* 
	here we call the buble sort func that we learn 
	in course to arrange the array in order
	*/
	sortArr(cookies, n);
	// this for will change the array value i to the desired new cookie
	for (i = 0; i<n; i++)
	{ 
		/*
		because after we call i+1 we are cheking 
		if i+1 is not in our array then break 
		from the for. 
		*/
		if (i + 1 == n)
		{
			break;
		}
		else 
		{
			/*
		 we are cheking that if the cookie in place i
			is lttle that the deired sweetness do the formula
			*/
			if (cookies[i] < k)
			{
				++count;
				cookies[i + 1] = cookies[i] + 2 * cookies[i + 1]; //the formula
			}
		}
		// here we are calling the sort func to the next row
		sortArr(cookies, n);
	}
	/*
	if after all of the changes there is a cookie < desired sweetness 
	: return -1 (impossible to do that)
	else return the counter
	*/
	if (cookies[i] < k)
	{
		return -1;
	}
	else
	{
		return count;
	}
}

/************************************************************************
* function name: swap													*
* The Input:  an int array, i, j indexes								*
* The output: swap two value in array									*
* The Function operation: the function swap two value in arrays     	*
* these two functions we learned in course								*
*************************************************************************/
void swap(int arr[], int i, int j) 
{
	int tmp;
	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}
/************************************************************************
* function name: sortArr												*
* The Input:  an int array, the array size					    		*
* The output: the swap array in order									*
* The Function operation: the function swap array number until it is in *
* the logical order		(0, 1,....)										*
* these two functions we learned in course								*
*************************************************************************/
void sortArr(int arr[], int size) 
{
	int i, j;
	//go over the array
	for (i = 0; i < size - 1; i++) 
	{
		//for each element in the array
		for (j = 0; j < size - 1 - i; j++) 
		{
			if (arr[j] > arr[j + 1]) 
			{
				//if elements not sorted - swap
				swap(arr, j, j + 1);
			}
		}
	}
}