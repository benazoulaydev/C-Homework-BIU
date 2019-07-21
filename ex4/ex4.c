/******************************************
 *Student name : Ben Azoulay
 * Student : 330485269
 * Exercise name : Exercise 4
 ******************************************/
#include <stdio.h>
// constraints for the first mission
#define MAX_N 1000
#define MIN_N 1
#define MAX_EVEN_AB 1000000000
#define MIN_EVEN_AB 1
// constraints for the second mission
#define THE_NUMBER 300
// constraints for the third mission
#define MIN_NUMBER 1
#define MAX_NUMBER 100
// constraints for the second mission
#define MIN_COUNTER 1
#define MAX_COUNTER 30
#define ROCK_STR "Rock"
#define PAPER_STR "Paper"
#define SCISSORS_STR "Scissors"
#define LIZARD_STR "Lizard"
#define SPOCK_STR "Spock"
// declaration missions functions
void Mission1();
void Mission2();
void Mission3();
void Mission4();
//declaration functions for mission 2
int max(int number, int divider);
int heroToZero(int myNumb, int countNumb);
void printNumb(int printMyNumb);
//declaration functions for mission 3
int xor(int myNumber, int helper, int countNum);
//declaration functions for mission 4
int bobFunc(int bobShape, int bobCounter);
int aliceFunc(int bobShape, int aliceShape, int aliceCounter);
int winner(int bobShape, int aliceShape, int counter, int printMe);
void shapeToStr(int shapeOfPlayer);
/************************************************************************
 * function name: the main function *
 * The Input: mission number that the program will execute *
 * The Output: exit if the main function work correctly (return 0) *
 * The Function operation: If you write void main(), it means that main()
 will return nothing
 *************************************************************************/
// initialisation of enum for
enum shapes { ROCK = 0, PAPER = 1, SCISSORS = 2, LIZARD = 3, SPOCK = 4};
void main() {
    int mission;
    do {
        printf("Please enter the mission number:\n");
        scanf("%d", &mission);
        switch (mission) {
            case 1: Mission1();
                break;
            case 2: Mission2();
                break;
            case 3: Mission3();
                break;
            case 4: Mission4();
                break;
            default:
                break;
        }
    } while (mission >= 1 && mission <= 4);
}
/************************************************************************
 * function name: Mission 1 *
 * The Input: n couple of two numbers with n the count *
 * The Output: the result of the function and no return : void fonction *
 * The Function operation: the function will print to the user how many
 time The first number contains the second number for n loop of
 two numbers. *
 *************************************************************************/
void Mission1()
{
    // initialisation of variables pair for the number of uput pairs
    int pair;
    /*
     initialisation of two counters :
     counterSame to count each time if the second number is in the first.
     counterLoop to count how many loop of numbers the user will input.
     */
    int counterSame = 0;
    int counterLoop = 1;
    printf("Please enter the number of pairs:\n");
    scanf("%d", &pair);
    /*
     This while will loop each time to ask the user two numbers
     and stop after the number of pair loops, that the user input,
     just before in the scanf.
     */
    while (pair)
    {
        /*
         initialisation of 3 variables :
         modTen that will take the value of 10^(digit of the number)
         in the while largerNumber and smallerNumber to be the
         user input numbers a and b
         */
        int modTen = 1;
        int largerNumber, smallerNumber;
        printf("Please enter the larger number of pair %d (a):\n", counterLoop);
        scanf("%d", &largerNumber);
        printf("Please enter the smaller number of pair %d (b):\n", counterLoop);
        scanf("%d", &smallerNumber);
        //initialisation of smallNumToZero variable equal to the smallerNumber
        int smallNumToZero = smallerNumber;
        /*
         In this loop we want to know how many digit the smallerNumber has.
         this smallNumToZero variable will help us with the modTen variable to
         know how much digit the smallerNumber variable contain.
         */
        while (smallNumToZero != 0)
        {
            smallNumToZero /= 10;
            modTen *= 10;
        }
        /*
         In this loop we are searching the smallerNumber variable is in the
         largerNumber variable.
         */
        while (largerNumber != 0)
        {
            /*
             if the largerNumber modulo the digit count of the
             smallerNumber (modTen) is equal to the smallerNumber,
             add 1 to counterSame variable. And break to stop with
             this two numbers and recheck the next two numbers if
             they exist (in the while(pair)).
             */
            if (smallerNumber == largerNumber % modTen)
            {
                counterSame++;
                break;
            }
            /*
             else divide the largerNumber by ten (integer)
             and continue the loop
             */
            largerNumber /= 10;
        }
        // the pair variable will decrease by one for the next while
        pair--;
        // add 1 to the counterLoop var each loop to print it the next loop
        counterLoop++;
    }
    /*
     when the pair are all entered it print the result how many time
     the second number was in the first max ome time for each two numberw
     */
    printf("The number of pairs satisfying the condition is: %d\n", counterSame);
}//end mission 1
/************************************************************************
 * function name: Mission 2 *
 * The Input: a number *
 * The Output: each action to the number and how many action*
 * The Function operation: It determine the minimum number of moves required
 to reduce the value of N to 0. With two move possible :
 or the number-1 or the maximum divider of the number*
 *************************************************************************/
void Mission2()
{
    //initialisation variable that will be the number input
    int theNumber;
    printf("Please enter the number:\n");
    scanf("%d", &theNumber);
    printf("The sequence of numbers produced by the actions is:\n");
    /*
     call the function printNumb that will print each number after
     the move is executed
     */
    printNumb(theNumber);
    //print the number of move by calling the function HeroToZero
    printf("The minimum number of moves is %d\n", heroToZero(theNumber, 0));
}
/************************************************************************
 * function name: max *
 * The Input: a number, the divider that is in the beginning equal
 to the number *
 * The Output: the maximum divider*
 * The Function operation: the function print the maximum divider
 if there is one and the number one if the number is a prime number *
 *************************************************************************/
int max(int number, int divider)
{
    /*
     here we are checking if the number is superior or equal to one
     then the function will return something else it will return 1
     */
    if (divider >= 1)
    {
        // if the number is a prime number return 1
        if (divider == 1) {
            return  1;
        }
        /*
         here we decrease each time the divider by one to check the
         if number modulo divider equal to 0 it means that the divider
         is the maximum divider for the number and return it
         else recall the function and decrease the new divider by one
         */
        --divider;
        if (number % divider == 0)
        {
            return divider;
        }
        return  max(number, divider);
    }
    return  1;
}
/************************************************************************
 * function name: heroToZero *
 * The Input: a number, the count that is in the beginning equal
 to zero *
 * The Output: the minimum counter for reducing the number to 0 *
 * The Function operation: the function will reduce in tree method
 each time the number or by 1 or equal to the maximum divider
 when the number reach 0 return the smaller moves to do it *
 *************************************************************************/
int heroToZero(int myNumb, int countNumb)
{
    // condition to stop the reucursion when the number equal to 0
    if (myNumb == 0)
    {
        return countNumb;
    }
    /*
     check if the number is prime (if max function return 1)
     and if so the only move is to reduce it by one
     else there is two move possible so we have
     to check which is the better
     */
    if (max(myNumb, myNumb) == 1)
    {
        return heroToZero(myNumb - 1, ++countNumb);
    }
    else
    {
        /*
         initialisation of way1 to be equal to the maximum divider
         and way2 to decrease the number by one
         */
        int way1 = heroToZero(max(myNumb, myNumb), countNumb);
        int way2 = heroToZero(myNumb - 1, countNumb);
        /*
         Each variable check the number of move for each numbers.
         if the number of move of the first is smaller than the
         second it will return the first move to the function
         else the second move.
         */
        if (way1 > way2)
        {
            return heroToZero(myNumb - 1, ++countNumb);
        }
        else
        {
            return  heroToZero(max(myNumb, myNumb), ++countNumb);
        }
    }
}
/************************************************************************
 * function name: printNumb *
 * The Input: a number*
 * The Output: print the moves *
 * The Function operation: it will print all of the moves with
 smaller counter it is a void function so each  move are only
 print and not return  *
 *************************************************************************/
void printNumb(int printMyNumb)
{
    /*
     initialisation of four variables :
     divid for the maximum divider, wayFirst and waySec to call
     heroToZero function with the 2 two different moves
     and counterFlag to be the counter of heroToZero function
     */
    int divid, wayFirst, waySec;
    int counterFlag = 0;
    // condition to stop the reucursion when the number equal to 0
    if (printMyNumb == 0)
    {
        return;
    }
    //if number not equal to zero divid be equal to the maximum divider
    divid = max(printMyNumb, printMyNumb);
    /*
     divid will help us to check if the number is prime (and return 1)
     by calling the function max
     */
    if (divid != 1)
    {
        /*
         if the number is not a prime number we have two option
         each time or to take the max divider or to decrease by one
         wayFirt will be the counter return by the heroToZero
         of the move -1.
         waySec will be the counter return by the heroToZero
         of the move maximum divider of the number.
         */
        wayFirst = heroToZero(printMyNumb - 1, counterFlag);
        waySec = heroToZero(divid, counterFlag);
        /*
         if the counter of the first number is smaller than the second
         number it will print the number with the good move to do
         and return the first number else same thing for the
         second number
         */
        if (wayFirst < waySec)
        {
            printf("%d\n", printMyNumb - 1);
            printNumb(printMyNumb - 1);
        }
        else
        {
            printf("%d\n", divid);
            printNumb(divid);
        }
        return;
    } // en if divd != 1
    /*
     Else it will print the number -1 and return it
     because it is a prime number
     */
    printf("%d\n", printMyNumb - 1);
    printNumb(printMyNumb - 1);
}
/************************************************************************
 * function name: Mission 3 *
 * The Input: a number *
 * The Output: printf each number that work for the given exerice*
 * The Function operation: Print all the values of a
 (in an ascending order)
 satisfying the conditions aNumber xor mynumber  > mynumber.
 For aNumber < mynumber *
 *************************************************************************/
void Mission3()
{
    // initialisation of number the user will input
    unsigned long int myXNumber;
    printf("Please enter the number:\n");
    scanf("%lu", &myXNumber);
    printf("The numbers are:\n");
    // call the function xor
    xor (myXNumber, 1, 0);
}
/************************************************************************
 * function name: xor *
 * The Input: a number, a helper increase by one each time,
 also countNum that will work as a counter or each
 number satisfying the condition*
 * The Output: print the numbers that work with the condition *
 * The Function operation: Print all the values of a
 (in an ascending order)
 satisfying the conditions aNumber xor mynumber > mynumber .
 For aNumber < mynumber *
 *************************************************************************/
int xor(int myNumber, int helper, int countNum)
{
    /*
     condition to print the final result sentence
     and stop the recursion when the helper > myNumber
     */
    if (helper >= myNumber)
    {
        printf("A total of %d numbers\n", countNum);
        return 0;
    }
    /*
     condition if
     helper xor mynumber  > mynumber
     also  increase the counter by one
     to the final sentence
     */
    if ((helper ^ myNumber) > myNumber)
    {
        printf("%d\n", helper);
        ++countNum;
    }
    // return the function xor to continue the loop
    return xor (myNumber, ++helper, countNum);
}
/************************************************************************
 * function name: Mission 4 *
 * The Input: two value one the shape of alice and the shape of bob
 the counter for how many game they will pay *
 * The Output: printf  games with the winner counter time *
 * The Function operation: the function takes two integer
 from 0 to 4 that are each a specify shape of the game
 Rock, PAPER, SCISSORS, LIZARD, SPOCK
 and also take the counter of time the game is played and return
 all of the game with each alice and bob way to play.*
 *************************************************************************/
void Mission4()
{
    /*
     initialisation of variable for the function
     aliceshape and bobshape for they initial shape
     round for each round played
     countWinner to return specific value if someone win
     countPlayer for each player action
     currentAliceShape and currentBobShape is the current shape
     each move.
     j for the for loop
     bobWin aliceWin and exAequo for the counter of each winner game
     */
    // initialisation of enum for
    enum shapes aliceShape;
    enum shapes bobShape;
    int round;
    int countWinner = 0;
    int countPlayer = 0;
    int currentAliceShape;
    int currentBobShape;
    int j;
    int bobWin = 0;
    int aliceWin = 0;
    int exAequo = 0;
    printf("Please enter the shape Alice chose:\n");
    scanf("%d", &aliceShape);
    printf("Please enter the shape Bob chose:\n");
    scanf("%d", &bobShape);
    printf("Please enter the number of rounds:\n");
    scanf("%d", &round);
    // call the function winner to print the first round
    countPlayer = winner(bobShape, aliceShape, countWinner, 1);
    //check who win and add to the good counter
    if (countPlayer == 1)
    {
        bobWin++;
    }
    else if (countPlayer == 31)
    {
        aliceWin++;
    }
    else
    {
        exAequo++;
    }
    // for loop to play each round
    for (j = 1; j < round; j++)
    {
        // function to determne the next aliceShape
        currentAliceShape = aliceFunc(bobShape, aliceShape, countPlayer);
        // function to determne the next bobShape
        currentBobShape = bobFunc(bobShape, countPlayer);
        // play the winner function with the new shapes
        countPlayer = winner(currentBobShape, currentAliceShape, countWinner, 1);
        // update the shapes of each player for the next move
        bobShape = currentBobShape;
        aliceShape = currentAliceShape;
        //check who win and add to the good counter
        if (countPlayer == 1)
        {
            bobWin++;
        }
        else if (countPlayer == 31)
        {
            aliceWin++;
        }
        else
        {
            exAequo++;
        }
    } // for end
    // at the end three option to display, who win or they tied
    if (bobWin == aliceWin)
    {
        printf("Alice and Bob tie, each winning %d game(s) and tying %d game(s)\n", aliceWin, exAequo);
    }
    else if (bobWin < aliceWin)
    {
        printf("Alice wins, by winning %d game(s) and tying %d game(s)\n", aliceWin, exAequo);
    }
    else
    {
        printf("Bob wins, by winning %d game(s) and tying %d game(s)\n", bobWin, exAequo);
    }
}
/************************************************************************
 * function name: bobFunc *
 * The Input: bobShape and his counter *
 * The Output: his next shape*
 * The Function operation: Given specific conditions
 the function will determine the next bob shape *
 *************************************************************************/
int bobFunc(int bobShape, int bobCounter)
{
    /*
     here nothing more than if of the prvious shapes
     of bob and wich it will reurn
     */
    if (bobShape == SPOCK)
    {
        // if the bob counter = 1 bob win the previous move
        if (bobCounter == 1)
        {
            return ROCK;
        }
        // if the counter = 31 alice win the previous move
        else if (bobCounter == 31)
        {
            return PAPER;
        }
        // if the counter = 100 bob and alice tied
        else if (bobCounter == 100)
        {
            return LIZARD;
        }
    }
    // if the previous shape was not SPOCK
    else
    {
        return SPOCK;
    }
}
/************************************************************************
 * function name: aliceFunc *
 * The Input: aliceShape,bobShape and her counter *
 * The Output: her next shape*
 * The Function operation: Given specific conditions
 the function will determine the next alice shape *
 *************************************************************************/
int aliceFunc(int bobShape, int aliceShape, int aliceCounter)
{
    // if the counter = 31 alice win the previous move
    if (aliceCounter == 31)
    {
        // it wiill return the same previous shape
        return aliceShape;
    }
    // if the counter = 100 alice and bob tied the previous move
    else if (aliceCounter == 100)
    {
        /*
         initialisation of two variables to be equal
         to the two shape that will beat her current shape
         */
        int help = 0;
        int addition = 0;
        /*
         In the for we are checking 5 time with 5 different shape
         which two shape will beat her current shape
         */
        for (bobShape = 0; bobShape < 5; bobShape++)
        {
            if (winner(bobShape, aliceShape, 0, 0) == 1) {
                help += bobShape;
                addition = bobShape;
            }
        }
        /*
         We have now the two shape that beat her current shape
         the first is equal to addition the second to help-addition
         now we have to check which beat the other shape
         if shape1 beat shape2 return shape1 else return shape2
         */
        if (winner(addition, help - addition, 0, 0) == 1)
        {
            return addition;
        }
        else
        {
            return help - addition;
        }
    }
    // if the counter = 1 bob win the previous move
    else if (aliceCounter == 1)
    {
        /*
         initialisation of two variables to be equal
         to the two shape that will beat bob current shape
         */
        int myhelper = 0;
        int myaddition = 0;
        /*
         In the for we are checking 5 time with 5 different shape
         which two shape will beat bob current shape
         */
        for (aliceShape = 0; aliceShape < 5; aliceShape++)
        {
            if (winner(bobShape, aliceShape, 0, 0) == 31) {
                myhelper += aliceShape;
                myaddition = aliceShape;
            }
        }
        /*
         We have now the two shape that beat her current shape
         the first is equal to myaddition the second to
         myhelp-myaddition.
         now we have to check which beat the other shape
         if shape1 beat shape2 return shape1 else return shape2
         */
        if (winner(myaddition, myhelper - myaddition, 0, 0) == 1)
        {
            return myaddition;
        }
        else
        {
            return myhelper - myaddition;
        }
    }
}
/************************************************************************
 * function name: winner *
 * The Input: aliceShape,bobShape, a counter, and also a printme var
 if the printMe equal to 1 print else just execute the winner func *
 * The Output: the round game *
 * The Function operation: the function will print the current game
 winner with his shape and the oppponent shape but also
 return the current counter if counter=1 bob win if counter=31 Alice win
 if counter = 100 they tied*
 *************************************************************************/
int winner(int bobShape, int aliceShape, int counter, int printMe)
{
    // if the shape are the same simply return 100 to say tied
    if (bobShape == aliceShape)
    {
        /*
         print the result only if printMe equal to one
         bobfunc and alice func use this function to check
         the counter but in that check we do not want to print
         something and the printme = 0
         */
        if (printMe == 1)
        {
            shapeToStr(aliceShape);
            printf(" = ");
            shapeToStr(bobShape);
            printf("\n");
        }
        return counter = 100;
    }
    // if bob win counter = 1 if alice wins counter =31
    if ((bobShape == SCISSORS && aliceShape == PAPER) ||
        (bobShape == PAPER && aliceShape == ROCK) ||
        (bobShape == ROCK && aliceShape == LIZARD) ||
        (bobShape == LIZARD && aliceShape == SPOCK) ||
        (bobShape == SPOCK && aliceShape == SCISSORS) ||
        (bobShape == SCISSORS && aliceShape == LIZARD) ||
        (bobShape == LIZARD && aliceShape == PAPER) ||
        (bobShape == PAPER && aliceShape == SPOCK) ||
        (bobShape == SPOCK && aliceShape == ROCK) ||
        (bobShape == ROCK && aliceShape == SCISSORS))
    {
        //increase counter by one
        counter++;
        // if bob win and printMe = 1 print the result
        if (counter == 1 && printMe == 1) {
            shapeToStr(aliceShape);
            printf(" < ");
            shapeToStr(bobShape);
            printf("\n");
        }
        // if alice win and printMe = 1 print the result
        else if (counter == 31 && printMe == 1)
        {
            shapeToStr(bobShape);
            printf(" > ");
            shapeToStr(aliceShape);
            printf("\n");
        }
        //return the last counter
        return counter;
    }
    /*
     if counter = 0 that mean only that alice win so it will return
     the winner function and change the aliceShape and bobShape
     so that it will print her shape or return it or both
     */
    if (counter == 0) {
        counter += 30;
        // printMe equal 0 when calling the winner function in bobFun or aliceFunc
        if (printMe == 0)
        {
            return winner(aliceShape, bobShape, counter, 0);
        }
        else
        {
            return winner(aliceShape, bobShape, counter, 1);
        }
    }
}
/************************************************************************
 * function name: shapeToStr *
 * The Input: the player shape *
 * The Output: onl *
 * The Function operation: the function will print the current game
 winner with his shape and the oppponent shape but also
 return the current counter if counter=1 bob win if counter=31 Alice win
 if counter = 100 they tied*
 *************************************************************************/
void shapeToStr(int shapeOfPlayer)
{
    switch (shapeOfPlayer)
    {
        case 0: printf(ROCK_STR);
            break;
        case 1: printf(PAPER_STR);
            break;
        case 2: printf(SCISSORS_STR);
            break;
        case 3: printf(LIZARD_STR);
            break;
        case 4: printf(SPOCK_STR);
            break;
        default:
            break;
    }
}
