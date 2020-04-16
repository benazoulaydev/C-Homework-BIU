/******************************************
*Student name: ben azoulay
*Student ID: 
*Submit Info: 
*Exercise name: ex5
******************************************/
#ifndef _MISSION4_H_
#define _MISSION4_H_
#include <stdio.h>
#include <string.h>
//define the constraints
#define MIN_ARRAY  3
#define MAX_ARRAY  25
#define GENERATION_MAX  100000
#define GENERATION_MIN  1
// functions declarations
void mission4();
void runGame(int n, int m, long c, char board[][MAX_ARRAY]);
void loadBoard(char mat[][MAX_ARRAY], int rows, int cols);
int   checkSpot(int spotArr[][MAX_ARRAY], int iSpot, int jSpot, int n, int m);
#endif
