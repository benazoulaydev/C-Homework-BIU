/******************************************
 *Student name: ben azoulay
 *Student ID: 330485269
 *Submit Info: azoualb1
 *Exercise name: ex6
 ******************************************/
#define MAX 500
#define NBOFFIELD 9
#define NUMB_0 48
#define NUMB_9 57
#define CHAR_A_BIG 65
#define CHAR_Z_BIG 90
#define CHAR_A_SMALL 97
#define CHAR_Z_SMALL 122
#define ID_SIZE 9
#define MAX_NAME 15
#define MAX_DESCRIPTION 211
#define MAX_PASSWORD 15
#define MIN_PASSWORD 3
#define MAX_USERNAME 10
#define MIN_USERNAME 3
#define CHAR_F_BIG 70
#define CHAR_M_BIG 77
#define MAX_AGE 100
#define MIN_AGE 18
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    char id[10];
    char age[3];
    char *firstName;
    char *lastName;
    char gender[1];
    char *user;
    char *password;
    char *description;
    char hobbies[8];
    struct Node* nxtuser; // A pointer to the next user
}Node;
// functions declarations
void updateNode(Node** node, char* name);
Node** insertToDynamicArr(Node** head, int* size, char* name);
Node** deleteNodeByIndexFromArr(Node** head, int* size, int index);
void delimiterToVar(Node** node, char* name);
int* sizeOfVar(Node** node, char* name);
void registerInput(Node*** node, Node** firstuserw, int* sizeM);
int genderChecker(char* name);
void logIn(int* sizeM, Node*** head, Node** firstuserw);
void mainMenu(int* sizeM, Node** head, Node** firstuserw, Node* currentuser, int indexMen, int indexWomen);
void deleteAllNode(Node** head, int* sizeM);
void printLoveMatch(Node *head, Node* currentuser, int ageMin, int ageMax);
void databaseToBuffer(Node** head, Node* firstuser, int sizeM);
void hobbiesBinaryToOriginal(Node* head, char* buffer);
Node* FindPlace(char *newLastName, Node* head);           // Find a place in the list to insert new user
Node** AddUser(char* bufferWomen, Node** head);     // Add a new struct to the linked list
void deleteNodeW(Node** head, int indexWomen);
void deleteAllWomenNode(Node* firstuserw);
void searchLove(int* sizeM, Node** head, Node** firstuserw, Node* currentuser, int indexMen, int indexWomen);

enum hobbies {
    BASEBALL = 1, BASKETBALL, BICYCLE, BOOKS,
    DRAWING, GYM, MOVIES, POETRY
};
enum user {
    ID, FIRSTNAME, LASTNAME, AGE,
    GENDER, USERNAME, PASSWORD, HOBBIES, DESCRIPTION
};
/************************************************************************
 * Function name : searchLove                                            *
 * The Input : - head, firstuserw : the heads of the men and women        *
 database                                                *
 - Node* currentuser : the pointer for the struct            *
 of the current user                                        *
 *             -int indexMen, int indexWomen: to know if the current user*
 is a men or women                                        *
 -int* sizeM : to know the size of the men array            *
 * The output : ---                                                        *
 * The Function operation :it link to other function and display the        *
 * actual women/men that are answering specific think (age, hobbies)        *
 *************************************************************************/
void searchLove(int* sizeM, Node** head, Node** firstuserw, Node* currentuser, int indexMen, int indexWomen)
{
    int ageMin, ageMax; // variables initialisation
    printf("Please choose ages range:\n");
    scanf("%d %d", &ageMin, &ageMax);
    if (indexWomen == -1)//search for women
    {
        Node *headWTmpSize = *firstuserw; // make a copy of womens head
        while (headWTmpSize != NULL)
        {
            // call the func that will print the matches
            printLoveMatch(headWTmpSize, currentuser, ageMin, ageMax);
            headWTmpSize = headWTmpSize->nxtuser;//go to next user
        }
    }
    else
    {//search for men
        int i;
        for (i=0; i< *sizeM; i++)
        {
            // make a copy of the head to not alter the original
            Node *headMTmpSize = head[i];
            // call the func that will print the matches
            printLoveMatch(headMTmpSize, currentuser, ageMin, ageMax);
        }
    }
}
/************************************************************************
 * Function name : printLoveMatch                                        *
 * The Input : - head the heads of the men or the women    database        *
 - Node* currentuser : the pointer for the struct            *
 of the current user                                        *
 *             -int ageMin, int ageMax: the age of the matches that the
 user seek                                                *
 *
 * The output : ---                                                        *
 * The Function operation : it print the user matches name, description    *
 * hobbies, age                                                            *
 ************************************************************************/
void printLoveMatch(Node *head, Node* currentuser, int ageMin, int ageMax)
{
    // variables initialisation
    int i;
    int hobbies;
    int hobbiesCompare;
    int sumByte = 0;
    int counter = 0;
    int numberToBinary;
    int counterHobbies = 0;
    hobbies = atoi((head)->hobbies); // string to int casting
    // string to int casting
    hobbiesCompare = atoi((head)->hobbies) & atoi(currentuser->hobbies);
    for (i = 0; i < 8; i++)
    {
        // sumbyte will help u to know the common hobbies bitwise
        sumByte += (hobbiesCompare >> i) & 1;
    }
    /*
     string to int casting
     if the age upper the min age asked and
     under than the max age and the shared
     hobbies are equal or greater tham 2
     print the found matche
     */
    if ((atoi((head)->age) >= ageMin) &&
        (atoi((head)->age) <= ageMax) &&
        (sumByte >= 2))
    {
        printf("Name: %s %s ", (head)->firstName, (head)->lastName);
        printf("Age: %s ", (head)->age);
        printf("Hobbies: ");
        /*
         here we are translating the decimal hobbies variable
         to binary to then print the good hobbies defined by
         enum
         */
        for (i = 0; i < 8; i++)
        {
            numberToBinary = (hobbies >> i) & 1;
            counterHobbies++;
            /*
             if it is equal to 0 it means that the hobbie is not
             shared for both of them so continue and do not print
             */
            if (numberToBinary == 0)
            {
                continue;
            }
            // switch to print the good hobbie depending on the number
            switch (counterHobbies)
            {
                case BASEBALL:
                    printf("Baseball");
                    break;
                case BASKETBALL:
                    printf("Basketball");
                    break;
                case BICYCLE:
                    printf("Bicycle");
                    break;
                case BOOKS:
                    printf("Books");
                    break;
                case DRAWING:
                    printf("Drawing");
                    break;
                case GYM:
                    printf("Gym");
                    break;
                case MOVIES:
                    printf("Movies");
                    break;
                case POETRY:
                    printf("Poetry");
                    break;
                default:
                    break;
            }
            counter++;
            // here for the first 3 we are print with , and space
            if (counter < 4)
            {
                printf(", ");
            }
        }//end for
        //print the description and a enter
        printf(" Description: %s\n", (head)->description);
        printf("\n");
    }
    //reinitializing vars for the next call
    sumByte = 0;
    counter = 0;
}
/************************************************************************
 * Function name : mainMenu                                                *
 * The Input : - head, firstuserw : the heads of the men and women        *
 database                                                *
 - Node* currentuser : the pointer for the struct            *
 of the current user                                        *
 *             -int indexMen, int indexWomen: to know if the current user*
 is a men or women                                        *
 -int* sizeM : to know the size of the men array            *
 * The output : ---                                                        *
 * The Function operation :this function display the main menu where we     *
 * can search for love delete our account permanently or simply logout    *
 * by calling  other functions                                            *
 *************************************************************************/
void mainMenu(int* sizeM, Node** head, Node** firstuserw, Node* currentuser, int indexMen, int indexWomen)
{
    int SndMenu; // variable initialisation for switch
    do
    {
        printf("Please choose an option:\n");
        printf("1. Find a match\n2. I found love, DELETE me\n3. Log out\n");
        scanf("%d", &SndMenu);
        // switch for the menu action
        switch (SndMenu)
        {
            case 1:
            {
                // call the func that will search for matches
                searchLove(sizeM, head, firstuserw, currentuser, indexMen, indexWomen);
                continue;
            }
                break;
            case 2:
            {
                // indexmen = -1 : women actually logged in
                if (indexMen == -1)
                {
                    //delete permanently the actual women account
                    deleteNodeW(firstuserw, indexWomen);
                }
                else
                {
                    //delete permanently the actual men account
                    deleteNodeByIndexFromArr(head, sizeM, indexMen);
                }
                return;
            }
                break;
            case 3:
            {
                return;
            }
                break;
            default: printf("Bad choice, please try again\n");
                return;
        }
    } while (SndMenu <= 3 && SndMenu>= 1);// number != 1,2,3: entry menu
}
/************************************************************************
 * Function name : logIn                                                    *
 * The Input : - head, firstuserw : the pointer of the heads of
 the men and women    database                            *
 -int* sizeM : to know the size of the men array            *
 * The output : ---                                                        *
 * The Function operation : this function will log registered user        *
 * asking for user and password    and checking if it is in the database   *
 * otherwise return to entry menu                                        *
 *************************************************************************/
void logIn(int* sizeM, Node*** headmen, Node** firstuserw)
{
    // variables initialisation
    int i, h;
    char tmp[MAX];
    int counterUser = 0;
    printf("Please enter your username: \n");
    /*
     here the user can make only one mistake
     for the username and after that if the username is
     not in the database return to main menu
     */
    for (h = 0; h < 1; h++)
    {
        scanf("%s", tmp);
        for (i = 0; i < *sizeM; i++)
        {
            /*
             here we are checking if the actual username
             database of the men if it match we are searching
             for the good password
             */
            if (strcmp(tmp, (*headmen)[i]->user) == 0)
            {
                printf("Please enter your password:\n");
                scanf("%s", tmp);
                if (strcmp(tmp, (*headmen)[i]->password) == 0)
                {
                    /*
                     if the password is in the database say hello
                     and then go to main menu
                     */
                    printf("Hello %s!\n", (*headmen)[i]->firstName);
                    mainMenu(sizeM, *headmen, firstuserw, (*headmen)[i], i, -1);
                    return;
                }
                else
                {
                    // wrong password
                    printf("Wrong password\n");
                    return;
                }
            }
        }
        // making copy of women head pointer
        Node *headWTmp = *firstuserw;
        Node *headWTmpSize = *firstuserw;
        //initialzing variables
        int sizeW = 0;
        int counterHelper = 0;
        // checking for the size of women registered
        while (headWTmpSize != NULL)
        {
            sizeW++;
            headWTmpSize = headWTmpSize->nxtuser;
        }
        //for every women in database
        for (i = 0; i < sizeW; i++)
        {
            /*
             here we are checking if the actual username
             database of the women if it match we are searching
             for the good password
             */
            if (strcmp(tmp, headWTmp->user) == 0)
            {
                printf("Please enter your password:\n");
                scanf("%s", tmp);
                if (strcmp(tmp, headWTmp->password) == 0)
                {
                    /*
                     if the password is in the database say hello
                     and then go to main menu
                     */
                    printf("Hello %s!\n", headWTmp->firstName);
                    mainMenu(sizeM, *headmen, firstuserw, headWTmp, -1, i);
                    //call func search love
                    return;
                }
                else
                {
                    // wrong password
                    printf("Wrong password \n");
                    return;
                }
            }// end if for username check
            else
            {
                //counter check for username attemps
                counterHelper++;
            }
            //go to next women in database
            headWTmp = headWTmp->nxtuser;
        }
        // here we enter if we didnot pass the username pass check
        if (counterHelper == i)
        {
            counterUser++;
            //if only one attempt we can redo it only one
            if (counterUser == 1)
            {
                printf("User do not exist in the system, please try again\n");
                printf("Please enter your username: \n");
                h = -1;
                continue;
            }
            else if (counterUser == 2)
            {
                //more than one attempt go to entry menu
                return;
            }
        }
    }
}
/************************************************************************
 * Function name : main                                                    *
 * The Input :    a number                                                *
 * The output : ---                                                        *
 * The Function operation : the entry menu will one time only at the        *
 * begining of the program take database info from the input.txt            *
 * register all of the men in dynamic array    and the women in linked list*
 * then will appear the entry menu for user to login, create an account  *
 * or exit the program, at exit time the program will take all of the    *
 * database and enter each user int output txt file, first will write    *
 * the men in the order of their account subscription and women in ABC    *
 * order                                                                    *
 *************************************************************************/
void main()
{
    // variables initialisation
    int entryMenu;
    int sizeM = 0;
    char buffer[MAX];
    int counter = 0;
    // struct type node initialisation pointer to NULL
    Node** head = NULL;
    Node* firstuserw = NULL;
    // file pointer
    FILE* fp;
    //here we are opening the iput txt file and only reading
    fp = fopen("input.txt", "r");
    // if not succeed opening exit the program
    if (fp == NULL)
        exit(1);
    //read the line after line from a file and insert to arr
    while (fgets(buffer, MAX, fp) != NULL)
    {
        //remove the \n in the end of the line
        if (buffer[strlen(buffer) - 1] == '\n')
        {
            buffer[strlen(buffer) - 1] = 0;
        }
        if (genderChecker(buffer) == 0)//if it is a women
        {
            //go to linked list add func for women
            AddUser(buffer, &firstuserw);
            continue;
        }
        //go to dynamic array add func for men
        head = insertToDynamicArr(head, &sizeM, buffer);
    }
    //close the file
    fclose(fp);
    do {
        printf("Welcome! please choose an option\n");
        printf("1 - Log in\n2 - New member\n3 - Exit\n");
        scanf("%d", &entryMenu);
        // switch of the entry menu for user type
        switch (entryMenu)
        {
            case 1:
            {
                //call the login func
                logIn(&sizeM,  &head, &firstuserw);
            }
                break;
            case 2:
            {
                //call the registering func
                registerInput(&head, &firstuserw, &sizeM);
            }
                break;
            case 3:
            {
                //export all two databases to output.txt
                databaseToBuffer(head, firstuserw, sizeM);
                // delete all men dynamic array free
                deleteAllNode(head, &sizeM);
                // delete all women linked list free
                deleteAllWomenNode(firstuserw);
                //exit
                exit(1);
            }
                break;
            default:
            {
                printf("Bad choice, please try again\n");
                continue;
            }
                break;
        }
    } while (1);// infinite loop for main menu
}
/************************************************************************
 * Function name : databaseToBuffer                                        *
 * The Input : - head, firstuserw :  the heads of the men and            *
 women    database                                        *
 -int sizeM : to know the size of the men array            *
 * The output : ---                                                        *
 * The Function operation : this function will export all of the two     *
 * database to an output file and at the same time make the database        *
 * exported  the same listing type  as the input.txt                        *
 *************************************************************************/
void databaseToBuffer(Node** head, Node* firstuser, int sizeM)
{
    // variables initialisation
    Node *headWomen = firstuser;
    FILE *fp;
    //here we are opening the output txt file and only writing
    fp = fopen("output.txt", "w");// write only
    // if not succeed opening exit the program
    if (fp == NULL)
    {
        printf("Error\n");
        exit(1);
    }
    // variables initialisation
    char buffer[MAX];
    char hobbies[8];
    int i;
    /*
     here we are copying each variable a buffer
     each var are copied then as the input
     txt file format we add semicolons
     to a buffer  and then copy it to
     the actual folder at the end
     */
    for (i = 0; i < sizeM; i++)
    {
        //men database to add
        strcpy(buffer, head[i]->id);
        strcat(buffer, ";");
        strcat(buffer, head[i]->firstName);
        strcat(buffer, ";");
        strcat(buffer, head[i]->lastName);
        strcat(buffer, ";");
        strcat(buffer, head[i]->age);
        strcat(buffer, ";");
        strcat(buffer, head[i]->gender);
        strcat(buffer, ";");
        strcat(buffer, head[i]->user);
        strcat(buffer, ";");
        strcat(buffer, head[i]->password);
        strcat(buffer, ";");
        /*
         here because the hobbies are in binary format
         we have to rechange them to the decimal format
         and then add it to the buffer
         the hobbiesBinaryToOriginal func will do the trick
         */
        hobbiesBinaryToOriginal(head[i], buffer);
        strcat(buffer, ";");
        strcat(buffer, head[i]->description);
        //at the end we are adding the \n for the next line
        strcat(buffer, "\n");
        //add the buffer line to the output file
        fputs(buffer, fp);
    }
    while (headWomen != NULL) {
        //women database to add
        strcpy(buffer, headWomen->id);
        strcat(buffer, ";");
        strcat(buffer, headWomen->firstName);
        strcat(buffer, ";");
        strcat(buffer, headWomen->lastName);
        strcat(buffer, ";");
        strcat(buffer, headWomen->age);
        strcat(buffer, ";");
        strcat(buffer, headWomen->gender);
        strcat(buffer, ";");
        strcat(buffer, headWomen->user);
        strcat(buffer, ";");
        strcat(buffer, headWomen->password);
        strcat(buffer, ";");
        /*
         here because the hobbies are in binary format
         we have to rechange them to the decimal format
         and then add it to the buffer
         the hobbiesBinaryToOriginal func will do the trick
         */
        hobbiesBinaryToOriginal(headWomen, buffer);
        strcat(buffer, ";");
        strcat(buffer, headWomen->description);
        //at the end we are adding the \n for the next line
        strcat(buffer, "\n");
        //add the buffer line to the output file
        fputs(buffer, fp);
        //go to the next head
        headWomen = headWomen->nxtuser;
    }
    fclose(fp);
}
/************************************************************************
 * Function name : hobbiesBinaryToOriginal                                *
 * The Input : - head: the head of the men or women  database             *
 - char* buffer : the buffer                                *
 * The output : ---                                                        *
 * The Function operation :here we are changing the binary value of      *
 * hobbies to add to the buffer                                            *
 *************************************************************************/
void hobbiesBinaryToOriginal(Node* head, char* buffer)
{
    // variables initialisation
    int j;
    int binaryNumb;
    int counterTmp = 0;
    int counter = 0;
    for (j = 0; j < 8; j++)
    {
        // string to int casting
        binaryNumb = (atoi((head)->hobbies) >> j) & 1;
        counterTmp++;
        /*
         if the hobbies are equal to 0 they are
         not the user hobbies so continue
         */
        if (binaryNumb == 0)
        {
            continue;
        }
        //switch to add the good value to the buffer
        switch (counterTmp)
        {
            case BASEBALL:
                strcat(buffer, "1");
                break;
            case BASKETBALL:
                strcat(buffer, "2");
                break;
            case BICYCLE:
                strcat(buffer, "3");
                break;
            case BOOKS:
                strcat(buffer, "4");
                break;
            case DRAWING:
                strcat(buffer, "5");
                break;
            case GYM:
                strcat(buffer, "6");
                break;
            case MOVIES:
                strcat(buffer, "7");
                break;
            case POETRY:
                strcat(buffer, "8");
                break;
            default:
                break;
        }
        counter++;
        //add colon for the first 3 hobbies
        if (counter < 4)
        {
            strcat(buffer, ",");
        }
    }
    return;
}
/************************************************************************
 * Function name : hobbiesBinaryToOriginal                                *
 * The Input : - head: the head of the men  database                        *
 - int* sizeM : size of men dynamic array                    *
 * The output : ---                                                        *
 * The Function operation :here we are deleting and freeing all the men     *
 * database                                                                *
 *************************************************************************/
void deleteAllNode(Node** head, int* sizeM)
{
    // variable initialisation
    int g;
    //free all the pointer in the array
    for (g = 0; g < *sizeM; g++)
    {
        free(head[g]->firstName);
        free(head[g]->lastName);
        free(head[g]->user);
        free(head[g]->password);
        free(head[g]->description);
        free(head[g]);
    }
    //free the head
    free(head);
}
/************************************************************************
 * Function name : deleteNodeByIndexFromArr                                *
 * The Input : head=pointer to the array,sizeM=pointer to the array sizeM, *
 index= the location to remove                                *
 * The output : the head of the array                                    *
 * The Function operation : remove the node in the given index             *
 * The array is sorted!                                                    *
 *************************************************************************/
Node** deleteNodeByIndexFromArr(Node** head, int* sizeM, int index)
{
    // variable initialisation
    int i;
    //if we are trying to free place not in the array print error
    if (index >= *sizeM)
    {
        printf("Error\n");
        return head;
    }
    //free the head struct pointer
    free(head[index]->firstName);
    free(head[index]->lastName);
    free(head[index]->user);
    free(head[index]->password);
    free(head[index]->description);
    //if there are values after this node
    if (index != *sizeM - 1)
    {
        /*
         here we free the head with the specific index
         and then we do a loop to copy all of the values
         of the after array to the before until the end
         */
        for(i=0; (index + i + 1) < *sizeM; i++)
        {
            //copy the after array to the current
            head[index + i]->firstName = head[index + i + 1]->firstName;
            head[index + i]->lastName = head[index + i + 1]->lastName;
            head[index + i]->user = head[index + i + 1]->user;
            head[index + i]->password = head[index + i + 1]->password;
            head[index + i]->description = head[index + i + 1]->description;
            //copy the non dynamic values of the array
            strcpy(head[index + i]->id, head[index + i + 1]->id);
            strcpy(head[index + i]->hobbies, head[index + i + 1]->hobbies);
            strcpy(head[index + i]->age, head[index + i + 1]->age);
            strcpy(head[index + i]->gender, head[index + i + 1]->gender);
        }
        //here we are asssigning null for no error when free the last value
        head[index + i]->firstName = NULL;
        head[index + i]->lastName = NULL;
        head[index + i]->user = NULL;
        head[index + i]->password = NULL;
        head[index + i]->description = NULL;
        //remove the last node head
        free(head[index + i]->firstName);
        free(head[index + i]->lastName);
        free(head[index + i]->user);
        free(head[index + i]->password);
        free(head[index + i]->description);
    }//end if
    //here we free the pointer to the last array head
    free(head[*sizeM - 1]);
    /*
     after freeing if head null it must be if the
     size =1 otherwise exit
     */
    if (head == NULL)
        if (*sizeM != 1)
            exit(1);
    //reduce the sizeM by one
    *sizeM -= 1;
    return head;
}
/************************************************************************
 * Function name : registerInput                                            *
 * The Input : -head=pointer to the array of the men, firstuserw pointer *
 to the array of the women                                *
 -sizeM=pointer to the array sizeM                            *
 * The output : ---------------------                                    *
 * The Function operation : the function is for the user registration    *
 * create exactly like the input file the same line format with semicolon*
 *and then call differents functions to register men(dynamic array)      *
 *and women(list linking) then log the user to the main menu                *
 *************************************************************************/
void registerInput(Node*** node, Node** firstuserw, int* sizeM)
{
    // variable initialisation
    char bufferInput[MAX];
    char bufferLine[MAX];
    char dummy[1];
    int i, j, k ;
    int womenSize = 0;
    int counterror = 0;
    Node *recordTemp = *firstuserw;
    Node *headWomenTmp = *firstuserw;
    Node *current = *firstuserw;
    Node *previous = NULL;
    char womenUsername[11];
    char hobbie1[2], hobbie2[2], hobbie3[2], hobbie4[2];
    //here we are looping to access each time to the switch case
    for (i = 0; i < NBOFFIELD; i++)
    {
        switch (i)
        {
            case ID:
            {
                printf("Please enter your ID:\n");
                scanf("%s", bufferInput);
                //if size of the id is not 9 return to entry menu
                if (strlen(bufferInput) != 9)
                {
                    return;
                }
                //check for each char if it is number if not return
                for (k = 0; k < ID_SIZE; k++)
                {
                    if (bufferInput[k] < NUMB_0 || bufferInput[k] > NUMB_9)
                    {
                        return;
                    }
                }
                //check if the id is already registered in the database of men
                for (j = 0; j < *sizeM; j++)
                {
                    if (strcmp(bufferInput, (*node)[j]->id) == 0)
                    {
                        printf("Error: User already exists\n");
                        counterror++;
                        return;
                    }
                }
                //check if the id is already registered in the database of women
                while (recordTemp != NULL)
                {
                    if (strcmp(bufferInput, recordTemp->id) == 0)
                    {
                        printf("Error: User already exists\n");
                        counterror++;
                        return;
                    }
                    //go to next user
                    recordTemp = recordTemp->nxtuser;
                }
                //copy to bufferline for future registration and add semicolon
                strcpy(bufferLine, bufferInput);
                strcat(bufferLine, ";");
            }
                break;
            case FIRSTNAME:
            {
                printf("Please enter your first name:\n");
                scanf("%s", bufferInput);
                //if superior than max size go back to entry menu
                if (strlen(bufferInput) > MAX_NAME)
                {
                    return;
                }
                for (k = 0; k < strlen(bufferInput); k++)
                {
                    //if each character are not in the abcd ABCD return to entry menu
                    if (bufferInput[k] < CHAR_A_BIG ||
                        (bufferInput[k] > CHAR_Z_BIG && bufferInput[k] < CHAR_A_SMALL)||
                        bufferInput[k] > CHAR_Z_SMALL)
                    {
                        return;
                    }
                }
                //copy to bufferline for future registration and add semicolon
                strcat(bufferLine, bufferInput);
                strcat(bufferLine, ";");
            }
                break;
            case LASTNAME:
            {
                printf("Please enter your last name:\n");
                scanf("%s", bufferInput);
                //if superior than max size go back to entry menu
                if (strlen(bufferInput) > MAX_NAME)
                {
                    return;
                }
                for (k = 0; k < strlen(bufferInput); k++)
                {
                    //if each character are not in the abcd ABCD return to entry menu
                    if (bufferInput[k] < CHAR_A_BIG ||
                        (bufferInput[k] > CHAR_Z_BIG && bufferInput[k] < CHAR_A_SMALL) ||
                        bufferInput[k] > CHAR_Z_SMALL)
                    {
                        return;
                    }
                }
                strcat(bufferLine, bufferInput);
                strcat(bufferLine, ";");
            }
                break;
            case AGE:
            {
                printf("Please enter your age (18 to 100):\n");
                scanf("%s", bufferInput);
                for (k = 0; k < strlen(bufferInput); k++)
                {
                    //check for each char if it is number if not return
                    if (bufferInput[k] < NUMB_0 || bufferInput[k] > NUMB_9)
                    {
                        return;
                    }
                }
                //if superior than max age or min than min age go back to entry menu
                if (atoi(bufferInput)> MAX_AGE || atoi(bufferInput) < MIN_AGE)
                {
                    return;
                }
                //copy to bufferline for future registration and add semicolon
                strcat(bufferLine, bufferInput);
                strcat(bufferLine, ";");
            }
                break;
            case GENDER:
            {
                printf("Please enter your gender (F-female, M-male):\n");
                scanf("%s", bufferInput);
                // if gender not F or M return to entry menu
                if (bufferInput[0] != CHAR_F_BIG && bufferInput[0] != CHAR_M_BIG)
                {
                    return;
                }
                //copy to bufferline for future registration and add semicolon
                strcat(bufferLine, bufferInput);
                strcat(bufferLine, ";");
            }
                break;
            case USERNAME:
            {
                printf("Choose a username (3-10 characters):\n");
                scanf("%s", bufferInput);
                //if user name not in the given range return to entry menu
                if (strlen(bufferInput) > MAX_USERNAME || strlen(bufferInput) < MIN_USERNAME)
                {
                    return;
                }
                //if each character are not in the abcd ABCD return to entry menu
                if (bufferInput[0] < CHAR_A_BIG ||
                    (bufferInput[0] >  CHAR_Z_BIG && bufferInput[0] < CHAR_A_SMALL) ||
                    bufferInput[0] > CHAR_Z_SMALL)
                {
                    return;
                }
                //check if the username exist in the database of men
                for (j = 0; j < *sizeM; j++)
                {
                    if (strcmp(bufferInput, (*node)[j]->user) == 0)
                    {
                        printf("Error: Username already exists\n");
                        counterror++;
                        return;
                    }
                }
                //make a copy of pointer of women head
                recordTemp = *firstuserw;
                //check if the username exist in the database of women
                while (recordTemp != NULL)
                {
                    if (strcmp(bufferInput, recordTemp->user) == 0)
                    {
                        printf("Error: Username already exists\n");
                        counterror++;
                        return;
                    }
                    //go to next user
                    recordTemp = recordTemp->nxtuser;
                }
                //copy the username to use it after
                strcpy(womenUsername, bufferInput);
                //copy to bufferline for future registration and add semicolon
                strcat(bufferLine, bufferInput);
                strcat(bufferLine, ";");
            }
                break;
            case PASSWORD:
                break;
            case HOBBIES:
            {
                /*
                 because we want to store the hobbies after the username
                 but we have to ask first for hobbies we are copying the
                 4 hobbies values and then ask for username
                 copy the username to the buffer and then copy the 4 hobbies
                 to the buffer
                 */
                printf("please choose 4 hobbies: Baseball=1, Basketball=2, Bicycle=3, Books=4, ");
                printf("Drawing=5, Gym=6, Movies=7, Poetry=8\n");
                scanf("%s %s %s %s", hobbie1, hobbie2, hobbie3, hobbie4);
                //ask for password
                printf("Choose a password (attention-minimum 3 characters):\n");
                scanf("%s", bufferInput);
                //if password is not in the given range return to main menu
                if (strlen(bufferInput) > MAX_PASSWORD || strlen(bufferInput) < MIN_PASSWORD)
                {
                    return;
                }
                //copy the password to buffer add semicolon
                strcat(bufferLine, bufferInput);
                strcat(bufferLine, ";");
                //copy each hobbies to buffer and add semicolon
                strcat(bufferLine, hobbie1);
                strcat(bufferLine, ",");
                strcat(bufferLine, hobbie2);
                strcat(bufferLine, ",");
                strcat(bufferLine, hobbie3);
                strcat(bufferLine, ",");
                strcat(bufferLine, hobbie4);
                strcat(bufferLine, ";");
            }
                break;
            case DESCRIPTION:
            {
                printf("Some words about yourself:\n");
                //use of dummy to capture the \n
                gets(dummy);
                gets(bufferInput);
                if (strlen(bufferInput) > MAX_DESCRIPTION)
                {
                    return;
                }
                //copy description to buffer and add semicolon
                strcat(bufferLine, bufferInput);
            }
                break;
            default:
                break;
        }//end switch
    }//end for
    //checking if it is a women or men by calling func
    if (genderChecker(bufferLine) == 1)
    {
        /*
         for the men we are adding the registered user to
         the dynamic array by passing the buffer to the func
         and then print something to after display the main menu
         */
        *node = insertToDynamicArr(*node, sizeM, bufferLine);
        printf("Hi %s, lets find love!\n", (*node)[*sizeM - 1]->firstName);
        mainMenu(sizeM, *node, firstuserw, (*node)[*sizeM - 1], *sizeM-1, -1);
    }
    else
    {
        //women call the adduser func to register to the linked list
        firstuserw = AddUser(bufferLine, firstuserw);
        //keep the head of the current user
        current = *firstuserw;
        previous = NULL;
        //here we are calculating  the women size linked list
        while (current != NULL) {
            previous = current;
            current = current->nxtuser;
            womenSize++;
        }
        previous = NULL;
        // make a copy of women head pointer
        headWomenTmp = *firstuserw;
        /*
         for the women we are adding the registered user to
         the linkedlist by passing the buffer to the func
         and then print something to after display the main menu
         */
        for (i = 0; i < womenSize; i++)
        {
            if (strcmp(womenUsername, headWomenTmp->user) == 0)
            {
                printf("Hi %s, lets find love!\n", headWomenTmp->firstName);
                //go to the main menu
                mainMenu(sizeM, *node, firstuserw, headWomenTmp, -1, i);
                return;
            }
            previous = headWomenTmp;
            //go to the next user in the next loop
            headWomenTmp = headWomenTmp->nxtuser;
        }
    }
}
/*****************************************************************************
 * Function name : updateNode                                                 *
 * The Input : pointer to the node we want update and the values to update     *
 * The output : ---                                                             *
 * The Function operation : allocate space to the name and copy all the values*
 ******************************************************************************/
void updateNode(Node** node, char* name)
{
    *node = (Node*)malloc(sizeof(Node));
    // if malloc didnot succeed exit
    if ((*node) == NULL)
    {
        printf("error\n");
        exit(1);
    }
    //the +1  in the malloc is for the \0
    int *sizeUserM = NULL;
    sizeUserM = sizeOfVar(*(&node), name);
    (*node)->firstName = (char*)malloc((sizeUserM[1] + 1) * sizeof(char));
    (*node)->lastName = (char*)malloc((sizeUserM[2] + 1) * sizeof(char));
    (*node)->user = (char*)malloc((sizeUserM[5] + 1) * sizeof(char));
    (*node)->password = (char*)malloc((sizeUserM[6] + 1) * sizeof(char));
    (*node)->description = (char*)malloc((sizeUserM[8] + 1) * sizeof(char));
    //free the string array
    free(sizeUserM);
    // if malloc didnot succeed exit
    if (((*node)->firstName == NULL) ||
        ((*node)->lastName == NULL) ||
        ((*node)->user == NULL) ||
        ((*node)->password == NULL) ||
        ((*node)->description == NULL))
    {
        printf("error\n");
        exit(1);
    }
    //call func delimiterToVar to copy buffer into each value
    delimiterToVar(*(&node), name);
}
/*****************************************************************************
 * Function name : sizeOfVar                                                     *
 * The Input : pointer to the node we want update and the values to update     *
 *             buffer name for each value                                     *
 * The output : a int array of size value                                     *
 * The Function operation : calculate the size of each variables in the buffer*
 ******************************************************************************/
int* sizeOfVar(Node** node, char*name)
{
    // variables initialisation
    int countersize = 1;
    int i = 0;
    char bufferSizeTemp[MAX];
    int* sizeVar = malloc(NBOFFIELD * sizeof(int));
    //if malloc didnot succeed exit
    if ((sizeVar) == NULL)
    {
        printf("error\n");
        exit(1);
    }
    //copy the buffer into bufferSizeTemp
    strcpy(bufferSizeTemp, name);
    //function strtok to each time take the value after ";"
    char *tokensize = strtok(bufferSizeTemp, ";");
    //for each string in buffer calculate his size and store into array of int
    while (tokensize != NULL)
    {
        for (i = 0; i < NBOFFIELD; i++)
        {
            *(sizeVar + i) = strlen(tokensize);
            countersize++;
            //go to next buffer string
            tokensize = strtok(NULL, ";");
        }
        return sizeVar;
    }
}
/*****************************************************************************
 * Function name : delimiterToVar                                             *
 * The Input : pointer to the node we want update and the values to update     *
 *             buffer name for each value                                     *
 * The output :--------------------------                                     *
 * The Function operation : assign each string in buffer to struct pointer     *
 ******************************************************************************/
void delimiterToVar(Node** node, char*name)
{
    //initialize variables
    int counter = 0;
    char bufferTemp[MAX];
    //copy name to bufferTemp
    strcpy(bufferTemp, name);
    //function strtok to each time take the value after ";"
    char *token = strtok(bufferTemp, ";");
    //here we are copying the token (buffer string) to his case
    while (token != NULL)
    {
        switch (counter)
        {
            case ID:
            {
                strcpy((*node)->id, token);
                counter++;//add to counter for next loop
            }
                break;
            case FIRSTNAME:
            {
                strcpy((*node)->firstName, token);
                counter++;//add to counter for next loop
            }
                break;
            case LASTNAME:
            {
                strcpy((*node)->lastName, token);
                counter++;//add to counter for next loop
            }
                break;
            case AGE:
            {
                strcpy((*node)->age, token);
                counter++;//add to counter for next loop
            }
                break;
            case GENDER:
            {
                strcpy((*node)->gender, token);
                counter++;//add to counter for next loop
            }
                break;
            case USERNAME:
            {
                strcpy((*node)->user, token);
                counter++;//add to counter for next loop
            }
                break;
            case PASSWORD:
            {
                strcpy((*node)->password, token);
                counter++;//add to counter for next loop
            }
                break;
            case HOBBIES:
            {
                // casting decimal to binary for smarter storing
                int temp = 0;
                int i = 0;
                //for each char in hobbies token we light up a bit
                while (i < 7)
                {
                    //bitwise operation
                    temp = temp | (1 << (token[i] - 1 - '0'));
                    i += 2;//+2 because format 1,2,3,4
                }
                //copy the temp to hobbies struct
                sprintf((*node)->hobbies, "%d", temp);
                counter++;//add to counter for next loop
            }
                break;
            case DESCRIPTION:
            {
                strcpy((*node)->description, token);
                counter++;//add to counter for next loop
            }
                break;
            default:
                break;
        }
        //go to next buffer string
        token = strtok(NULL, ";");
    }
}
/****************************************************************************
 * Function name : insertToDynamicArr                                        *
 * The Input : head=pointer to the array,size=pointer to the array size,        *
 name                                                                *
 * The output : pointer to the array                                            *
 * The Function operation : realocate space to the new value,                *
 and update all the fields inside                *
 (allocate space to the name and copy name\id)    *
 *****************************************************************************/
Node** insertToDynamicArr(Node** head, int* sizeM, char* name)
{
    //if the array is empty malloc
    if (*sizeM == 0)
    {
        head = (Node**)malloc(sizeof(Node*));
    }
    else
    {
        //not empty realloc
        head = (Node**)realloc(head, (*sizeM + 1) * sizeof(Node*));
    }
    //if head malloc realloc didnot succeed exit
    if (head == NULL)
    {
        printf("error\n");
        exit(1);
    }
    //insert to new node, the function receives a pointer
    updateNode(&head[*sizeM], name);
    *sizeM += 1;
    return head;
}
/****************************************************************************
 * Function name : genderChecker                                                *
 * The Input : name buffer                                                    *
 * The output : 1 or 0 men or women                                            *
 * The Function operation : check if it is a men or a women                    *
 *****************************************************************************/
int genderChecker(char* name)
{
    //initialize variables
    int counter = 0;
    char bufferTemp[MAX];
    //copy buffer  to bufferTemp
    strcpy(bufferTemp, name);
    //function strtok to each time take the value after ";"
    char *token = strtok(bufferTemp, ";");
    //check if in the buffer the value is M or F and return 1,0
    while (token != NULL)
    {
        //in the buffer the 4 place is the gender
        if (counter == 4)
        {
            if (strcmp(token, "M") == 0)
            {
                return 1; //it is a men
            }
            else
            {
                return 0; //it is a women
            }
        }
        counter++;
        //go to next buffer string
        token = strtok(NULL, ";");
    }
}
/****************************************************************************
 * Function:   FindPlace                                                        *
 * Action:        Find a place in the list to insert new user.                *
 * Input:        The new user's last name and the user of the first item        *
 *                in the list.                                                *
 * Returns:        A pointer to the struct which AFTER we'll insert the new  *
 *                    struct.      NULL if head of the linekd-list                *
 *****************************************************************************/
Node *FindPlace(char *newLastName, Node* head)
{
    //initialize variable
    Node *prev = NULL;
    Node *current = head;
    /*
     here we are checking where to past the
     user depending on abc order of the lastname
     */
    while (current != NULL) {
        if (strcmp(newLastName, current->lastName) < 0) {
            break;
        }
        //assigning the new place of the user in the node
        prev = current;
        current = current->nxtuser;
    }
    return prev;
}
/****************************************************************************
 * Function: AddUser                                                            *
 * Action:      Add a new struct to the linked list.                            *
 * Input:      The new user's details and the user of the listÕs head.        *
 * Returns:       None.                                                        *
 *****************************************************************************/
Node** AddUser(char  *bufferWomen, Node** head)
{
    //initialize variable
    Node *after;
    // create new entry
    Node *new_entry = (Node *)malloc(sizeof(Node));
    int *sizeUser = NULL;
    //checkink if malloc succeed if not exit
    if (NULL == new_entry)
    {
        printf("error\n");
        exit(1);
    }
    // we are copying the int array of variable length int sizeUser
    sizeUser = sizeOfVar((&new_entry), bufferWomen);
    //we are allocating memory with malloc and the size of each string +1 (\0)
    (new_entry)->firstName = (char*)malloc((sizeUser[1] + 1) * sizeof(char));
    (new_entry)->lastName = (char*)malloc((sizeUser[2] + 1) * sizeof(char));
    (new_entry)->user = (char*)malloc((sizeUser[5] + 1) * sizeof(char));
    (new_entry)->password = (char*)malloc((sizeUser[6] + 1) * sizeof(char));
    (new_entry)->description = (char*)malloc((sizeUser[8] + 1) * sizeof(char));
    //we no longer need the sizeUser so we free it
    free(sizeUser);
    //checkink if malloc succeed if not exit
    if (((new_entry)->firstName == NULL) ||
        ((new_entry)->lastName == NULL) ||
        ((new_entry)->user == NULL) ||
        ((new_entry)->password == NULL) ||
        ((new_entry)->description == NULL))
    {
        printf("error\n");
        exit(1);
    }
    /*
     we are calling the func delimiter to var for assigning
     the strings in the buffer that we previously malloc
     */
    delimiterToVar((&new_entry), bufferWomen);
    /*
     then we are searching for the place of the user in the
     linked list depend abc on the last name
     */
    after = FindPlace((new_entry)->lastName, *head);
    if (NULL == after) // a new head
    {
        if (NULL == *head)
        {
            //for adding the first item (when the head is NULL).
            new_entry->nxtuser = NULL;
        }
        else {
            new_entry->nxtuser = *head;
        }
        *head = new_entry;
    }
    else
    {   // add it in the middle
        new_entry->nxtuser = after->nxtuser;
        after->nxtuser = new_entry;
    }
    return head;
}
/****************************************************************************
 * Function:    DeleteWomenNode                                                *
 * Action:         Deletes  the linked list by specific index.                *
 * Input:         user of the first item in the list. the index                *
 * Returns:         None.                                                    *
 *****************************************************************************/
void deleteNodeW(Node** head, int indexWomen)
{
    // Store head node
    Node* currentuser = *head, prev;
    Node* previousUser = *head;
    Node* nextUser = *head;
    int i;
    // If linked list is empty
    if (*head == NULL)
        return;
    // If head needs to be removed
    if (indexWomen == 0)
    {
        *head = (currentuser)->nxtuser; // Change head
        free(currentuser->firstName);
        free(currentuser->lastName);
        free(currentuser->user);
        free(currentuser->password);
        free(currentuser->description);
        free(currentuser); // free old head
        return;
    }
    
    for (i = 0; i < indexWomen - 1 && previousUser != NULL; i++)
    {
        previousUser = previousUser->nxtuser;
    }
    // If position is more than number of ndoes
    if (previousUser == NULL || previousUser->nxtuser == NULL)
        return;
    //assigning the current value to the previous
    currentuser = previousUser->nxtuser;
    nextUser = (previousUser)->nxtuser;
    nextUser = nextUser->nxtuser;
    //free the current index values that we are no longer need
    free(currentuser->firstName);
    free(currentuser->lastName);
    free(currentuser->user);
    free(currentuser->password);
    free(currentuser->description);
    //assigning previoususer value to next user
    previousUser->nxtuser = nextUser;
    //remove the head
    free(currentuser);
}
/****************************************************************************
 * Function:    deleteAllWomenNode                                            *
 * Action:         Deletes all the linked list.                                *
 * Input:         user of the first item in the list.                        *
 * Returns:         None.                                                    *
 *****************************************************************************/
void deleteAllWomenNode(Node* firstuserw)
{
    while (NULL != firstuserw)
    {
        Node *next = firstuserw->nxtuser;
        free(firstuserw->firstName);
        free(firstuserw->lastName);
        free(firstuserw->user);
        free(firstuserw->password);
        free(firstuserw->description);
        free(firstuserw);
        firstuserw = next;
    }
}
