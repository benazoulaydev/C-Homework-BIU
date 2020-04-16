/******************************************
*Student name : Ben Azoulay	
* Student :
* Exercise name : Exercise 2
******************************************/

/* ex2.c */
// this define is for removing the scanf error unsafe
#define _CRT_SECURE_NO_WARNINGS

// Here I created # Define for the mission 3 (required for the exercise)
#define WEATHER_COLD  "This year the weather was cold\n"
#define WEATHER_HOT  "This year the weather was hot \n"
#define WEATHER_NORM  "This year the weather was normal\n"
#include <stdio.h>


/************************************************************************
 * function name: the main function *
 * The Input: Our program *
 * The output: exit if the main function work correctly (return 0) *
 * The Function operation: If you write int main(), it means that main() will return some integer,
 you can return anything,but as a convension we use 0,which means success
 The return value of the main function is considered the "Exit Status"
 of the application. *
 *************************************************************************/
int main()
{
	// initialise int num1 that will take the value 1,2 or 3 for the switch
	int num1;
	
	printf("Please choose an option:\n");
	scanf("%d", &num1);

	
	switch (num1)
	{

	case 1:
	{
		// Mission 1

		printf("Please enter four chars:\n");
		// Here we are initializing 4 differents char variables that match the input user type
		char char1, char2, char3, char4;

		/*
		Here a dummy char is created because the user had to type his mission's number 
		in the beginning of the program but also type 'enter'. 
		Because our variables are char type  in the scanf the program take the 'enter' as a char
		value and we do not want that to happen, so I assign this enter to the dummy char created.
		*/
		char dummy;

		scanf("%c", &dummy);
		scanf("%c %c %c %c", &char1, &char2, &char3, &char4);

		/*
		Here we are checking  what is the first char : char1 if it is in our domain or not
		*/

		// First if : to check if the first character that the user write is : [
		if (char1 == '[')
		{
			/*
			 If the first character is [ there is only one case that will work : [()] and print Ok
			*/
			if (char2 == '(' && char3 == ')' && char4 == ']')
			{
				printf("Ok\n");
			}

			/*
			Else : it will be a bad structure, even if the structure is like [ab] or [aa]
			it will be a bad structure because only one structure is accepted for that case[()]
			*/
			else
			{
				printf("Bad structure\n");
			}
		}
		// Second if : to check if the first character that the user write is : (
		else if (char1 == '(')
		{

			/*
			Here there are 3 case possible : 
			or it is good and will print Ok
			or an Invalid Input like (abc with bc not valid
			or it is a bad structure like ((((
			*/

			/*
			The first if will print Ok only in 4 cases : 
			-  (a)a
			-  ()aa
			-  (aa)
			-  ()()
			*/
			if ((char2 == 'a' && char3 == ')' && char4 == 'a') || 
				(char2 == ')' && char3 == 'a' && char4 == 'a') || 
				(char2 == 'a' && char3 == 'a' && char4 == ')') || 
				(char2 == ')' && char3 == '(' && char4 == ')'))
			{
				printf("Ok\n");
			}

			/*
			The Second if will check if either char2, char3 or char4 are not 
			one of : ()[]a for example : char2 = w it will print an invalid input
			*/
			else if ((char2 != '(' && char2 != '[' && char2 != ']' && char2 != ')' && char2 != 'a') || 
					(char3 != '(' && char3 != '[' && char3 != ']' && char3 != ')' && char3 != 'a') || 
					(char4 != '(' && char4 != '[' && char4 != ']' && char4 != ')' && char4 != 'a'))
				 {
					printf("Invalid input \n");
				 }

			/*
			The else will print a bad structure on its own without checking something 
			because if the user input is neither ok or invalid input it has to be 
			a bad structure
			*/
			else
			{
				printf("Bad structure\n");
			}
		}
			

		// Third if : to check if the first character that the user write is : a
		else if (char1 == 'a')
		{
			/*
			Here there are 3 case possible :
			or it is good and will print Ok
			or an Invalid Input like aabc with bc not valid
			or it is a bad structure like a(((
			*/


			/*
			The first if will print Ok only in 4 cases :
			-  aaaa
			-  a()a
			-  aa()
			-  a(a)
			*/
			if ((char2 == 'a' && char3 == 'a' && char4 == 'a') || 
				(char2 == '(' && char3 == ')' && char4 == 'a') || 
				(char2 == 'a' && char3 == '(' && char4 == ')') || 
				(char2 == '(' && char3 == 'a' && char4 == ')'))
			{
				printf("Ok\n");
			}

			/*
			The Second if will check if either char2, char3 or char4 are not 
			one of : ()[]a for example : char2 = w it will print an invalid input
			*/
			else if ((char2 != '(' && char2 != '[' && char2 != ']' && char2 != ')' && char2 != 'a') || 
					(char3 != '(' && char3 != '[' && char3 != ']' && char3 != ')' && char3 != 'a') || 
					(char4 != '(' && char4 != '[' && char4 != ']' && char4 != ')' && char4 != 'a'))
			{
				printf("Invalid input \n");
			}

			/*
			The else will print a bad structure on its own without checking something
			because if the user input is neither ok or invalid input it has to be
			a bad structure
			*/
			else
			{
				printf("Bad structure\n");
			}
		}

		/*
		Fourth if : to check if the first input character is : ] or ) 
		it will display a Bad structure Message
		*/
		else if (char1 == ']' || char1 == ')')
		{
			printf("Bad structure\n");
		}

		/*
		Final else : if the first input character is not 
		one of : ()[]a it  will display an invalid input
		*/
		else
		{
			printf("Invalid input \n");
		}



		break;





	case 2:
	{
		// Mission 2
		/* code block 1 */

		// Here we are initializing 2 int variables that match the input user type
		int a;
		int b;

		/*
		Here a dummy char is created because the user have 2 int type 'enter' key 
		and type a char variable (operator).
		Because our variable operator is char type  in the scanf the program take the 'enter' 
		( after typing the int variable b)  as a char variable.
		 We do not want that to happen, so I assign this enter to the dummy char created.
		*/
		char dummy;

		// Here we initialize a char operator for the switch
		char operator;

		printf("Please enter first number: \n");
		scanf("%d", &a);
		printf("Please enter second number: \n");
		scanf("%d", &b);
		printf("Please enter operator: \n");
		scanf("%c", &dummy);
		scanf("%c", &operator);


		/* 
		Here I Created a Switch to handle the operations process.
		To not have to write multiple if and be as clear as possible,
		each case in the switch will handle a different operator.
		*/
		switch (operator)
		{

		// First case if the operator is + then it will print the result a+b
		case '+':
		{
			a += b;

			/*
			 Here i use a cast method to make the int variables
			 float and display it with two 0 after the dot (%.2f).
			 Also the 7 is for a minimum size of 7 space :%7 (with the variable
			 in it). for exemple 5 will be displayed (%7.2f)
			 "   5.00" of course  without the ""
			*/
			printf("The result is:%7.2f\n", (float)a);

		}
		break;

		// Second case if the operator is - then it will print the result a-b
		case '-':
		{
			a -= b;

			/*
			 Here i use a cast method to make the int variables
			 float and display it with two 0 after the dot (%.2f).
			 Also the 7 is for a minimum size of 7 space :%7 (with the variable
			 in it). for exemple 5 will be displayed (%7.2f)
			 "   5.00" of course  without the ""
			*/
			printf("The result is:%7.2f\n", (float)a);

		}
		break;

		// Third case if the operator is * then it will print the result a*b
		case '*':
		{
			a *= b;

			/*
			 Here i use a cast method to make the int variables
			 float and display it with two 0 after the dot (%.2f).
			 Also the 7 is for a minimum size of 7 space :%7 (with the variable
			 in it). for exemple 5 will be displayed (%7.2f)
			 "   5.00" of course  without the ""
			*/
			printf("The result is:%7.2f\n", (float)a);

		}
		break;

		// Fourth case if the operator is % then it will print the result a%b
		case '%':
		{
			/* 
			Here we are checking if b equal to 0 and in that case
			the operation a % 0 is not defined and cannot be 
			applied  so we are printing an invalid input message
			*/
			if (b == 0)
			{
				printf("Invalid input\n");
			}
			//Else : the function is defined and we can print the a%b operation
			else
			{
				a = a % b;

				/*
				 Here i use a cast method to make the int variables
				 float and display it with two 0 after the dot (%.2f).
				 Also the 7 is for a minimum size of 7 space :%7 (with the variable
				 in it). for exemple 5 will be displayed (%7.2f)
				 "   5.00" of course  without the ""
				*/
				printf("The result is:%7.2f\n", (float)a);
			}
			

		}
		break;

		// Fitfh case if the operator is / then it will print the result a/b
		case '/':
		{
			/*
			Here we are checking if b equal to 0 and in that case
			the operation a/0 is not defined and cannot be
			applied  so we are printing an invalid input message
			*/
			if (b==0)
			{

				printf("Invalid input\n");
			}

			//Else : the function is defined and we can print the a/b operation
			else 
			{
				float d = (float)a / (float)b;

				/*
				 Here i use a cast method to make the int variables
				 float and display it with two 0 after the dot (%.2f).
				 Also the 7 is for a minimum size of 7 space :%7 (with the variable
				 in it). for exemple 5 will be displayed (%7.2f)
				 "   5.00" of course  without the ""
				*/
				printf("The result is:%7.2f\n", d);
			}
		}
		break;

		default:
		{
			/* 
			Default block if the input is not correct either a not int variable
			or a bad operator
			*/
			printf("Invalid input\n");
		}

		}
		


	}
	break;

	case 3:
	{
		/* Mission 3 */

		// Here we are initializing 4 float variables that match the user's input temperature 
		float temp1, temp2, temp3, temp4;

		// Here we are initializing a float variable for the average temperature 
		float tempAvg;

		// Here we are initializing a enumeration type variable (required for the exercise)
		enum temp {COLD, NORMAL, HOT};

		printf("Please enter the average temperature per season:\n");
		scanf("%f %f %f %f", &temp1, &temp2, &temp3, &temp4);

		// The average temperature of the user's input
		tempAvg = (temp1 + temp2 + temp3 + temp4)/4;

		/*
		Here we are creating a new value actualTemp for the switch expression.
		that will take one of the three (0, 1 or 2 ) value if the user input is correct 
		(cold = 0, normal = 1, hot = 2 as default) 
		*/
		enum temp actualtemp;
		
		/*
		the first if will determine if minimum one of 
		temp1, temp2, temp3, temp4 are less than 10,  or 
		temp1, temp2, temp3, temp4 are bigger than 37 
		If so the program will print Invalid input and stop.
		If I did not make a condition here :  
		For exemple the input is : 9 11 12 13 average = 22.5
		the average will tell the user that this year the weather
		was cold but we do not want that because of the 9.
		So with that IF, the program will say Invalid input 
		and make a break to stop the program 
		and to not continue with the average.
		*/
		if (temp1 < 10 || temp2 < 10 || temp3 < 10 || temp4 < 10 || 
			temp1 > 37 || temp2 > 37 || temp3 > 37 || temp4 > 37)
		{
			printf("Invalid input\n");
			break;
		}

		/*
		the second if check if the average of temperature
		is between [10-20) and set enum Temp actualTemp
		equal to cold (0 by default)
		*/
		if (tempAvg >= 10 && tempAvg < 20)
		{
			actualtemp = COLD;
		}

		/*
		the else if check if the average of temperature
		is between [20-30)  and set enum Temp actualTemp
		equal to normal (1 by default)
		*/
		else if (tempAvg >= 20 && tempAvg < 30)
		{
			actualtemp = NORMAL;
		}

		/*
		the else if check if the average of temperature
		is between [30-37) and set enum Temp actualTemp
		equal to normal (2 by default)
		*/
		else if (tempAvg >= 30 && tempAvg <= 37)
		{
			actualtemp = HOT;
		}
		
		/*
		Here I Created a Switch (required for the exercise)
		with variable actualTemp as the expression to display 
		the year Weather and the estimated average
		*/
		switch (actualtemp)
		{
		
		/*
		in this case 0 = cold as defined in the
		enum Temp {cold, normal, hot}. it will 
		print the year Weather cold, the 
		estimated average and break (stop)
		*/
		case 0:
		{
			printf(WEATHER_COLD);
			printf("Estimated average: %.2f", tempAvg);
			
		}
		break;

		/*
		in this case 1 = normal as defined in the
		enum Temp {cold, normal, hot}. it will
		print the year Weather normal, the
		estimated average and break (stop)
		*/
		case 1:
		{
			printf(WEATHER_NORM);
			printf("Estimated average: %.2f", tempAvg);
		}
		break;

		/*
		in this case 2 = hot as defined in the
		enum Temp {cold, normal, hot}. it will
		print the year Weather hot, the
		estimated average and break (stop)
		*/
		case 2:
		{
			printf(WEATHER_HOT);
			printf("Estimated average: %.2f", tempAvg);
			
		}
		break;

		/*
		the defaul case is empty here because all of the case
		are used but I write this for the a better understanding
		*/
		default:
		{
			printf("Invalid input\n");
			
		}

		}




	}
	break;

	/*
	Default  case of the all program if the input
	not equal 1 or 2 or 3 it will display 
	the wrong key error

	*/
	default:
	{
		/* code block default */
		printf("Wrong key!!!\n"); }
	}
	}

	return 0;
}
