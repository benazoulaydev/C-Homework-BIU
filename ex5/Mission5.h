/******************************************
*Student name: ben azoulay
*Student ID: 330485269
*Submit Info: azoualb1
*Exercise name: ex5
******************************************/
#ifndef _MISSION5_H_
#define _MISSION5_H_
#include <stdio.h>
#include <string.h>
//define the constraints
#define ARRAY_MIN  1
#define ARRAY_MAX  25
#define BIG_NUMB 1000000000
// functions declarations
void mission5();
void loadCastleBoard(char mat[][ARRAY_MAX], int rows, int cols);
int getMinLength(char mat[][ARRAY_MAX], int startX, int startY,  int goalX, int goalY, int n, int counter);
#endif