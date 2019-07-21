/******************************************
*Student name: ben azoulay
*Student ID: 330485269
*Submit Info: azoualb1
*Exercise name: ex5
******************************************/
#include "Mission5.h"
/************************************************************************
* function name: mission5											    *
* The Input:   Number of rows, column, c iteration, array string board  *
* The output:  the array string of the board after c iteration		    *
				if all the population are dead  after a<=c iteration    *
				print the counter a else c                              *
* The Function operation:											 	*
			You are given a square grid with some cells open (-) and    *
			some blocked (X). Your playing piece can move along any row *
			or column until it reaches the edge of the grid				*
			or a blocked cell. Given a grid, a start and an end			*
			position, determine the number of moves it will take to get *
			to the end position.										*
			You can only move Up, Down, Left & Right					*
			(No diagonal movement!)										*
*************************************************************************/
void mission5()
{
	/*
	initalize variables
	n: number of row and column
	counter: for the number in the func getMinLength
	board: the array of the table user will input
	startX, startY : start x and y point
	goalX, goalY  :goal x and y point
	*/
	int n;
	char board[ARRAY_MAX][ARRAY_MAX];
	int counter = 0;
	int startX, startY, goalX, goalY, result;
	printf("Please enter the number of rows and columns (n):\n");
	scanf("%d", &n); 	// Input the n
	// if n is not in the given range return to main menu
	if (n > ARRAY_MAX || n < ARRAY_MIN)
	{
		return;
	}
	printf("Please enter the X of the starting position:\n");
	scanf("%d", &startX); // Input the startX
	// if startX is not in the given range return to main menu 
	if (startX >= n || startX < 0)
	{
		return;
	}
	printf("Please enter the Y of the starting position:\n");
	scanf("%d", &startY); // Input the startY
	// if startY is not in the given range return to main menu 
	if (startY >= n || startY < 0)
	{
		return;
	}
	printf("Please enter the X of the goal position:\n");
	scanf("%d", &goalX); // Input the goalX
	// if goalX is not in the given range return to main menu 
	if (goalX >= n || goalX < 0)
	{
		return;
	}
	printf("Please enter the Y of the goal position:\n");
	scanf("%d", &goalY); // Input the goalY
	// if goalY is not in the given range return to main menu 
	if (goalY >= n || goalY< 0)
	{
		return;
	}
	printf("Please enter the grid:\n");
	loadCastleBoard(board, n, n);		// Reading the Board
	result = getMinLength(board, startX, startY, goalX, goalY, n, counter);	// Getting the Minimum Value
	//if it didnot print an error print the number of step else no path possible 
	if (result != -1)
	{
		printf("The minimum number of steps is %d\n", result);
	}
	else
	{
		printf("No path was found from (%d,%d) to (%d,%d)\n", startX, startY, goalX, goalY);
	}
}
/************************************************************************
* function name: getMinLength 											*
* The Input:  mat[][MAX_ARRAY] :  array for the input board		        *
*             startX, startY : start x and y point						*
			  goalX, goalY  : goal x and y point  		                *
			  n: number of row and column		 		                *
			  counter : begin at 0				                        *
* The output: the minimum required counter for the path                 *
* The Function operation: Given a grid, a start and an end				*
			position, determine the number of moves it will take to get *
			to the end position.	               						*
*************************************************************************/
int getMinLength(char mat[][ARRAY_MAX], int startX, int startY,  int goalX, int goalY, int n, int counter)
{
	/*
	initalize variables
	i, j to be equal to the current point x y
	up, down, left, right : the moves
	cantWalk the cantwalk counter to no reenter two time in a path
	tempC to keep the value of the current place
	*/
	int i, j;
	int up, down, left, right;
	int cantWalk;
	j = startY;
	i = startX;
	char tempC;
	/* 
	condition that assign a big number to one of four movement 
	if it is not possible to move in that place
	*/
	if (mat[i][j] == 'X' || i >= n  || i  < 0 || j >= n  || j < 0)
	{
		return BIG_NUMB;
	}
	// recursive stop and return counter when finished
	if ((j == goalY) && (i == goalX))
	{
		return counter;
	}
	/* 
	we assign to tempC the current value in the array[i][j]
	then we make the current value equal to X so we cannot 
	return and move to that place another time
	*/
	tempC = mat[i][j];
	mat[i][j] ='X';
	/*
	here we try to move down if it is not possible 
	make down a big number
	*/
	if (i + 1 > n - 1 || mat[i+1][j] == 'X')
	{
		down = BIG_NUMB;
	}
	else
	{
		/*
		else we assign down the reucursive func of down (i+1)
		and if it return -1 down get a big number 
		*/
		down = getMinLength(mat, i+1, j, goalX, goalY, n, counter + 1);
		if (down == -1)
		{
			down = BIG_NUMB;
		}
	}
	/*
	here we try to move up if it is not possible
	make up a big number
	*/
	if (i - 1 < 0 || mat[i - 1][j] == 'X')
	{
		up = BIG_NUMB;
	}
	else
	{
		/*
		else we assign up the reucursive func of up (i-1)
		and if it return -1 up get a big number
		*/
		up = getMinLength(mat,  i-1, j, goalX, goalY, n, counter + 1);
		if (up == -1)
		{
			up = BIG_NUMB;
		}
	}
	/*
	here we try to move right if it is not possible
	make right a big number
	*/
	if (j + 1 > n - 1 || mat[i][j+1] == 'X')
	{
		right = BIG_NUMB;
	}
	else
	{
		/*
		else we assign right the reucursive func of up (j+1)
		and if it return -1 right get a big number
		*/
		right = getMinLength(mat, i, j+1,  goalX, goalY, n, counter + 1);
		if (right == -1)
		{
			right = BIG_NUMB;
		}
	}
	/*
	here we try to move left if it is not possible
	make left a big number
	*/
	if (j - 1 < 0 || mat[i][j - 1] == 'X')
	{
		left = BIG_NUMB;
	}
	else
	{
		/*
		else we assign left the reucursive func of up (j-1)
		and if it return -1 left get a big number
		*/
		left = getMinLength(mat, i, j-1, goalX, goalY, n, counter + 1);
		if (left == -1)
		{
			left = BIG_NUMB;
		}
	}
	// here we make the current i j equal to his current char
	mat[i][j] = tempC;
	// if down the more smaller return it
	if (down <= left && down <= up && down <= right && down >=0 && down < BIG_NUMB)
	{
		return down;
	}
	// if right the more smaller return it
	else if (right <= left && right <= up && right <= down && right >= 0 && right < BIG_NUMB)
	{
		return right;
	}
	// if up the more smaller return it
	else if (up <= left && up <= right && up <= down && up >= 0 && up < BIG_NUMB)
	{
		return  up;
	}
	// if left the more smaller return it
	else if (left <= right && left <= up && left <= down && left >= 0 && left < BIG_NUMB)
	{
		return left;
	}
	//if none of the smaller than the others return -1
	return -1;
}
/************************************************************************
* function name: loadCastleBoard 											    *
* The Input:  mat[][MAX_ARRAY] :  array for the input board		        *
*             rows :  the row size, cols the col size   		        *
* The output: past to the array the input board                         *
* The Function operation: it takes the user input board and create   	*
			an array of it                  							*
*************************************************************************/
void loadCastleBoard(char mat[][ARRAY_MAX], int rows, int cols)
{
	// The Function reads from the IO and loads to the array
	int i;
	for (i = 0; i < rows; i++)
	{
		scanf("%s", mat[i]);
	}
}