/******************************************
 *Student name : Ben Azoulay
 * Student :
 * Exercise name : Exercise 3
 ******************************************/

 /* ex3.c */
 // this define is for removing the scanf error unsafe
#define _CRT_SECURE_NO_WARNINGS
// theses two defines are used as constrain for the bases in the  first exercice
#define MAX_BASE 10
#define MIN_BASE 2
// theses two defines are used as constrain for the range  in the  second exercice 10^7=10000000
#define MAX_TIME 10000000
#define MIN_TIME 1
// theses two defines are used as constrain for the range of the Kaprekar number in the third exercice
#define RANGE_TOP 10000
#define RANGE_BOTTOM 0
// theses two defines are used as constrain for the range of the richar and louise 's game in the fourth exercise
#define MAX_NUMBER 1073741824
#define MIN_NUMBER 1

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
	//here I created an infinite loop, 1 different than 0 so it stay in the loop unless break
	while (1)
	{
		// initialise int num1 that will take the value 1,2,3,4 for the switch
		int num1;
		printf("Please enter the mission number:\n");
		scanf("%d", &num1);

		switch (num1)
		{

		case 1: {
			//first mission

			//initialisation of variable : base of the numbers asked
			int base;

			printf("Please enter the base of the problem: \n");
			scanf("%d", &base);

			/*
			Here a if else is created , if the base is not from the range it will 
			print an error else it will execute the rest of the first mission
			*/
			if (base < MIN_BASE || base>MAX_BASE)
			{
				printf("ERROR - The base %d is not between 2 and 10\n", base);

			}
			else
			{
				/*
				initialisation of variables num1, num2 that will take the value of the 
				2 numbers input. digit_num1 and digit_num2 will take the value of digits
				in the for loop. multiplier will help us for the base translation to base 
				10. i for the for loop. num1InBase10, num2InBase10 will be the numbers in
				base 10. the rest and the final num will be used to translate the addition 
				of the two numbers in base 10 to the base input.
				
				*/
				int num1;
				int num2;
				int digit_num1;
				int digit_num2;
				int multiplier = 1;
				int i;
				int num1InBase10 = 0;
				int num2InBase10 = 0;
				int rest = 0;
				int final_num = 0;

				printf("Please enter the first number in base %d: \n", base);
				scanf("%d", &num1);
				printf("Please enter the second number in base %d: \n", base);
				scanf("%d", &num2);

				/*
				the num1_1  num2_1 variable will keep the original value of number 1 
				and 2 to display it at the end
				*/
				int num1_1 = num1;
				int num2_1 = num2;

				/*
				i variable for the for loop
				What we do here : we change each number to base 10.
				The digit_num1/2 variable will be each time the last 
				digit of the number * base.
				Firstly the base will be in the power 0 (1)
				on the second loop base^1,  base^2...
				This base will be multiply with the current digit,
				then for the next loop we divide num1and num2 by 10
				they are int so for exemple 143 / 10.
				will be 14 and then we redo the same thing.
				All of the loop we add the digit result in the base 10.
				*/
				for (i = 1; i < 9; i++)
				{
					digit_num1 = (num1 % 10);
					digit_num1 *= multiplier;
					digit_num2 = (num2 % 10);
					digit_num2 *= multiplier;
					multiplier *= base;
					num1 /= 10;
					num2 /= 10;
					num1InBase10 += digit_num1;
					num2InBase10 += digit_num2;
				}

				// here we are reinitializing the multiplyer to reuse it in the while
				multiplier = 1;
				//here we sum up the 2 numbers in base 10
				int sum = num1InBase10 + num2InBase10;

				/*
				this While loop is for translating the given number in base 10 to the base 
				of the input. We  use the rest var to be the rest of the addition in the base.
				the sum is after that divided by the base. The multipliier is equal to one 
				in the first loop and then multiply by 10. so we can add each digit 
				in the order for exemple : 102 the digit are 1, 0,2 we multiply 2by1 
				then add 0*10 and add 1 * 100 = 100+2 = 102.
				in other word we multiply the rest with the multiplier then add it one loop
				after another

				*/
				while (sum != 0)
				{
					rest = sum % base;
					sum = sum / base;
					final_num += rest * multiplier;
					multiplier *= 10;
				}//end while
				printf("The result of %d + %d in base %d is %d\n", num1_1, num2_1, base, final_num);
			}
			//the continue will stop here and restart the loop while so return to the main menu
			continue;
		}

		case 2:
		{
			// mission 2
			// here we arethe time variable for the user input
			int time;
			

			printf("Please enter the time:\n");
			scanf("%d", &time);

			/*
			here we are checking if the time is in the given range if not it 
			will print error else it will execute the program
			*/
			if (MAX_TIME < time || MIN_TIME>time)
			{
				printf("ERROR - The time %d is invalid\n", time);
			}
			else
			{
				
				//here we are initializing 3 variables that we will use in the while
				
				
				int power2 = 2;
				int biggerTime = 0;
				int size = 3;

				/*
				here we have some variable one to be the power of 2 : power2
				biggertime to be the time in the last  time in the range
				for exemple if the user input 6 it is between 4 and 9 in the
				given table so 9 is the biggertime.
				the bigger time is succesvely 3, 9 ,21, 45 so we can write it
				like that : it is a serie that can be write like that : 
				3(2-1) = 3, 3(4-1)=9,  3(8-1)=21,  3(16-1)=45
				so biggertime can be writed like 3 * (power2 - 1) with power 
				2 multuplied by 2 each loop
				*/
				while (biggerTime < time)
				{
					biggerTime = 3 * (power2 - 1);
					power2 *= 2;
				}//end while
				/*
				we can see in the table that for time 6 the output
				will be 4 and the biggertime is 9 same for all numbers
				so the final output is biggertime-time +1
				9-6+1=4
				*/
				printf("The time in the timer after %d seconds is %d\n", time, biggerTime - time + 1);
			}
		}
		//the continue will stop here and restart the loop while so return to the main menu
		continue;

		case 3:
		{
			//Mission 3
			//initialisation of the range for the user input
			int lowerLimit;
			int upperLimit;

			printf("Please enter the lower limit of the range (p):\n");
			scanf("%d", &lowerLimit);
			printf("Please enter the upper limit of the range (q):\n");
			scanf("%d", &upperLimit);

			/*
			if the range is supperior or inferior the given range it will print an error 
			else it will run the program
			*/
			if (lowerLimit <= RANGE_BOTTOM || upperLimit > RANGE_TOP || lowerLimit >= upperLimit)
			{
				printf("ERROR - The range %d to %d isn't valid\n", lowerLimit, upperLimit);
			}
			else
			{
				/*
				initialisation of vraiables : 
				numb and numbInit  will be the begining og the range
				and the other varianles will be used in the for and while
				*/
				int numb = lowerLimit;;
				int numbInit = lowerLimit;
				int digitModulo = 1;
				int i;
				int square;
				int r;
				int l;
				int counterIf = 0;
				// here we are creating a for loop for printing the output in the given range to upperlimit
				for (i = 0; i <= upperLimit; i++)
				{
					/* 
					this will will permit us to know the height of the number (d in the exercise)
					and multiply a modulo variable each time by ten. in other word if the number is 
					17 for exemple it will make digimodulo = 100
					*/
					while (numbInit != 0)
					{
						numbInit /= 10;
						digitModulo *= 10;
					}//end while
					/*
					here we are creating the square of the number,
					the right side as described in the exercice and the left side
					the right can be d or d-1 
					the l is the rest 
					for exemple numb= 9 sqare to 81 r = 1 and l equal to 8
					*/
					square = numb * numb;
					r = square % (digitModulo);
					l = square / (digitModulo);

					//if the number r + l equal to the initial number it will be a modified kaperlach number
					if (numb == l + r)
					{
						/*
						 the counterif variable permit us to display one time "The numbers between.."
						 sentence after that only the numbers
						*/
						if (counterIf == 0)
						{
							printf("The numbers between %d and %d are:\n", lowerLimit, upperLimit);
							counterIf++;
						}
						printf("%d\n", numb);
					}

					// here we qre reinitializing the numbers to the next loop of the for
					digitModulo = 1;
					numb++;
					i = numb - 1;
					numbInit = numb;
				}
				/*
				if counterif ==0 the only optionis that it was not trigered so there is no
				kaperlach number in the given range and print a no number message
				*/
				if (counterIf == 0)
				{
					printf("NO NUMBERS BETWEEN %d AND %d\n", lowerLimit, upperLimit);
				}
			}
			//the continue will stop here and restart the loop while so return to the main menu
			continue;
		}

		case 4:
		{
			//mission 4
			// initializing variable num for the louise and richard game long because it can be 2^30 
			long int numb;
			printf("Please enter the initial value for the game:\n");
			scanf("%u", &numb);

			/*
			here we are creating 3 variables one : a to be the number powto the power
			of 2 and rilo a counter for the louise or richard print 
			*/
			long int a = numb;
			long int powTwo = 1;
			int riLo = 1;

			// here we are creating a while because at the end the number had to be one 
			while (numb != 1)
			{
				
				/*
				here we are dividing a variable a and multiplying a variable powtwo by 2
				so it pow two will be <=a 
				for exemple if a is equal to 14
				we divid it 3 time  and multiplying powtwo 2 time by two (the first time by one)
				a = 14 pwtwo = 8
				*/
				while (a != 1)
				{
					a >>= 1;
					powTwo <<= 1;
				}//end while
				/*
				here by using xor with 2^n number we substract it (only work with 2^n number)
				if the number is not directly  apower of two for exemple 3 we substract the most 
				close power of two 2 and the result is one. else if it was 4 we divid it by 2 one time
				as the game ask.
				*/
				if (powTwo != numb)
				{

					numb ^= powTwo;
				}
				else
				{

					numb >>= 1;
				}

				// here powtwo is reinitialized and a equal to the new number for the next loop
				a = numb;
				powTwo = 1;

				/*
				here we are simply printing louise or richard with their numbers if one is 
				printed the next time it will be the other with the counter riLo variable
				*/
				if (riLo == 1)
				{
					riLo = 0;
					printf("Louise: %u\n", numb);

				}
				else
				{
					riLo = 1;

					printf("Richard: %u\n", numb);
				}
			}//end while

			/*
			here we are printing the final score that  depend to the rilo variable
			if the last was richard the winner is louise
			*/
			if (riLo == 1)
			{
				printf("The winner is: Louise\n");
			}
			else
			{

				printf("The winner is: Richard\n");

			}
			//the continue will stop here and restart the loop while so return to the main menu
			continue;
		}
		//default case for a better understanding
		default:
		{}

		}
		return 0;
	}
}

