/******************************************
*Student name: ben azoulay
*Student ID: 
*Submit Info: 
*Exercise name: ex5
******************************************/
#include "Mission4.h"
/************************************************************************
* function name: mission4											    *
* The Input:   Number of rows, column, c iteration, array string board  *
* The output:  the array string of the board after c iteration		    *
*				if all the population are dead  after a<=c iteration    *
*				print the counter a else c                              *
* The Function operation:											 	*
*			We have a finite torus board of square cells, each of which *
*			is in one of two possible states, alive or dead,            *
*			(or populated and unpopulated, respectively).				*
*			Every cell interacts with its eight neighbours, which are	*
*			the cells that are horizontally, vertically, or diagonally	*
*			adjacent. At each step in time, the following transitions	*
*			occur:														*
*			- Any live cell with fewer than two live neighbors dies,	*
*			as if by underpopulation.									*
*			- Any live cell with two or three live neighbors lives		*
*			on to the next generation.									*
*			- Any live cell with more than three live neighbors dies,	*
*			as if by overpopulation.									*
*			- Any dead cell with exactly three live neighbors becomes a *
*			live cell, as if by reproduction.	                        *
*************************************************************************/
void mission4()
{
	/*
	initalize variables
	n: number of row
	m: the number of column 
	c: the number of iteration
	*/
	int n, m;
	long c;
	char board[MAX_ARRAY][MAX_ARRAY];
	printf("Please enter the number of rows (n):\n");
	scanf("%d", &n); // Input the n
	// if the row not in the given range return to main menu
	if (n > MAX_ARRAY || n < MIN_ARRAY)
	{
		return;
	}
	printf("Please enter the number of columns (m):\n");
	scanf("%d", &m); // Input the m
	// if the column not in the given range return to main menu
	if (m > MAX_ARRAY || m < MIN_ARRAY)
	{
		return;
	}
	printf("Please enter the number of iterations (c):\n");
	scanf("%ld", &c); // Input the c
	// if the iteration not in the given range return to main menu
	if (c > GENERATION_MAX || c < GENERATION_MIN)
	{
		return;
	}
	printf("Please enter the board:\n");
    loadBoard(board, n, m);		// Reading the Board
	runGame(n, m, c, board);
}
/************************************************************************
* function name:  runGame								                *
* The Input: n :  the row size                               	        *
*            m :  the col size										    *
*			 c :  the iteration										    *
*			 board :	the array board							        *
* The output: the array board after c iteration                         *
* The Function operation: it takes  char board array and translate it   *
*			 to 1 and 0  int board. for each value in the array it      *
*			 call the function check spot to know if the next           * 
*			 generation  the value will be a dead or a live value       *
*			 then return the board after c iteration, if all the cell   *
*			 are dead after n<=c iteration it print the n iteration     *
*************************************************************************/
void runGame(int n, int m, long c, char board[][MAX_ARRAY])
{
	/*
	initalize variables
	k, x, y, i, j : indexes of for
	counter : the number of iteration each time
	counterAlivePop: counter od alive population
	boardToInt: the board array that is translated to int 
	boardHelper: take the value each row of the  number
	returned by the func loadBoard
	*/
	int x, y;
	int i = 0, j = 0, k=0;
	int counter = 0;
	int counterAlivePop = 0;
	int boardToInt[MAX_ARRAY][MAX_ARRAY];
	int boardHelper[MAX_ARRAY][MAX_ARRAY];
	//this for will repeat c row unless all population are dead
	for (k = 0; k < c; k++)
	{
		//this two for will help us to translate the char to int array
		for (x = 0; x < n; x++)
		{
			for (y = 0; y < m; y++)
			{
				// if value - create array in help board to 0
				if (board[x][y] == '-')
				{
					boardToInt[x][y] = 0;
				}
				// if value * create array in help board to 1
				else if (board[x][y] == '*')
				{
					boardToInt[x][y] = 1;
				}
			}
		}
		// this will check the value of the return value by checkspot func
		for (x = 0; x < n; x++)
		{
			for (y = 0; y < m; y++)
			{
				/* 
				create a bordhelper equal to all value 
				return by checkspot func
				*/
				boardHelper[x][y] = checkSpot(boardToInt, x + 1, y + 1, n, m);
				//if the board is 0  make the board array  value -
				if (boardHelper[x][y] == 0)
				{
					board[x][y] = '-';
				}
				//if the board is 1  make the board array  value *
				else if (boardHelper[x][y] == 1)
				{
					counterAlivePop++;
					board[x][y] = '*';
				}
			}
		}
		counter++;
		/* 
		if the counteralivepop didnt increase
		it mean the board is only dead cell
		so break from the for k
		*/
		if (counterAlivePop == 0)
		{
			break;
		}
		counterAlivePop = 0;
	}
	printf("The board after %d iterations is: \n", counter);
	// print the board after counter iteration
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%c", board[i][j]);
		}
		printf("\n");

	}
}
/************************************************************************
* function name: loadBoard 											    *
* The Input:  mat[][MAX_ARRAY] :  array for the input board		        *
*             rows :  the row size, cols the col size   		        *
* The output: past to the array the input board                         *
* The Function operation: it takes the user input board and create   	*
			an array of it                  							*
*************************************************************************/
void  loadBoard(char mat[][MAX_ARRAY], int rows, int cols)
{
	//initialize variable i for the for
	int i;
		//take the value of the board and past it to the array
		for (i = 0; i < rows; i++)
		{
			scanf("%s", &mat[i]);
		}
}
/************************************************************************
* function name: checkSpot 											    *
* The Input:  spotArr[][MAX_ARRAY] :  array for the input board		    *
*             iSpot,jSpot the number position           		        *
*             n the row size ,m the colum size       		            *
* The output: 1 or 0 if the cell is alive or dead                       *
* The Function operation: it takes the user input board translated   	*
*			to int and return 1 or 0 with the condition of the exercice *
*************************************************************************/
int   checkSpot(int spotArr[][MAX_ARRAY], int iSpot, int jSpot, int n, int m)
{
	/*
	initalize variables
	k, i, j : indexes of for
	spot[9] : a 9 array for all the number that are near the current 
	number
    mHelper, nHelper: will help us to take the values for  
	 that form : spotArr[nHelper][mHelper]
	spotCheck: the current value at i j position
	sum: the sum of all of the spot near the current value
	*/
	int i = 0, j = 0, k=0;
	int spot[9];
	int mHelper, nHelper;
	int spotCheck;
	int sum = 0;
	/* 
	this for  will help us to assign to spot[]
	each value (the 8 value) 
	around the current value
	*/
	for (i = -1 + iSpot; i < 2 + iSpot; i++)
	{
		nHelper = i % n -1;
		/*
		in c language % is not modulo but rest so 
		if negative number is entered we add the base
		to the negative number to make it positive
		*/
		if (nHelper < 0)
		{
			nHelper += n;
		}
		for (j = -1 + jSpot; j < 2 +jSpot; j++)
		{
			mHelper = j % m -1;
			/*
			in c language % is not modulo but rest so
			if negative number is entered we add the base
			to the negative number to make it positive
			*/
			if (mHelper < 0)
			{
				mHelper += m;
			}
			spot[k] = spotArr[nHelper][mHelper];
			/* 
			if the value is the current value and not the 
			around value make it  equal to 0
			*/
			if (i == iSpot && j == jSpot) 
			{
				spotCheck = spotArr[nHelper][mHelper];
				spot[k] = 0;
			}
			k++;
		}
	}
	// this for will sum all of the array in spot
	for (i = 0; i < 9; i++)
	{
		sum += spot[i];
	}
	/* 
	the condition in the exercice to make the 
	cell live or die in the nest generation
	*/
	if (spotCheck == 0)
	{
		if (sum == 3)
		{
			return 1; // live
		}
		else
		{
			return 0; // die
		}
	}
	else
	{
		if (sum < 2 || sum >3)
		{
			return 0; // die
		}
		else if (sum ==  2 || sum == 3)
		{
			return 1; // live
		}
	}
}
