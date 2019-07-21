/******************************************
*Student name: ben azoulay
*Student ID: 330485269
*Submit Info: azoualb1
*Exercise name: ex5
******************************************/
#ifndef _MISSION2_H_
#define _MISSION2_H_
#include <stdio.h>
//define the constraints
#define COOKIE_SIZE_MAX 1000
#define COOKIE_SIZE_MIN 1
#define MAX_SWEETNESS 10000
#define MIN_SWEETNESS 0
#define MAX_COOKIE_I_SWEET 100000
#define MIN_COOKIE_I_SWEET 0
// functions declarations
void mission2();
int sweetCookies(int cookies[], int n, int k);
void sortArr(int arr[], int size);
void swap(int arr[], int i, int j);
#endif