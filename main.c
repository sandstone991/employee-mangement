#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>
#define SIZE 20
/***********************************************************************************************************************/
//Node struct
struct Node
{
    //**********************************************************************************************************************************************************
    //DATA SECTION START
    char firstName[20];
    char lastName[20];
    int id;
    int age;
    int salary;
    char phone[13];
    //It's possible that I may add more data later so Remeber to change the arguments
    //of the functions that takes in the data
    //DATA SECTION END
    //**********************************************************************************************************************************************************
    //LINKED LIST QUEUE STUFF START
    struct Node *nextPtr;
    //LINKED LIST QUEUE STUFF END
};

/***********************************************************************************************************************/
//Declare gloabal variables 
//Intializing two global pointer to a struct of type Node to act as out front and rear because they'll be used thoroughly
struct Node *front = NULL;
struct Node *rear = NULL;
//counter for counting employees throughout the program
int counter = 0;

/***********************************************************************************************************************/
//Declare functions

//*****

//QUEUE FUNCTIONS DECLARATION SECTION START
void enqueue();
int isEmpty();

//QUEUE FUNCTIONS DECLARATION SECTION END

//******

//FILE FUNCTIONS DECLARATION START
void newRecord(FILE *fPtr);

//FILE FUNCTIONS DECLARATION END

//******

//MISC FUNCTION DECLARATION START

//MISC FUNCTION DECLARATION END

//******

/***********************************************************************************************************************/
//Main funtion

main()
{
  
}
/***********************************************************************************************************************/
//Functions definition

//****************

//QUEUE FUNCTIONS DEFINTION START

int isEmpty()
{
    if (front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue()
{
    counter++;
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->nextPtr = NULL;
    printf("Enter Employee (%d) data :-\n", counter);

    printf("First name: ");
    scanf("%19s", &newNode->firstName);
    puts("");
    printf("Last name: ");
    scanf("%19s", &newNode->lastName);
    puts("");
    printf("ID: ");
    scanf("%d", &newNode->id);
    puts("");
    printf("Age: ");
    scanf("%d", &newNode->age);
    puts("");
    printf("Phone number: ");
    scanf("%12s", &newNode->phone);
    puts("");
    printf("Salary: ");
    scanf("%d", &newNode->salary);
    puts("");

    //we'll add the rest of data later for now lets work on the queue part
    //PLEASE REMOVE THESE COMMENTS
    //Check whether the queue is empty or not
    if (isEmpty())
    {
        //Make the front pointer and rear pointer point to the newly added element
        //which happens to be the FIRST ELEMENT
        front = rear = newNode;
    }

    else
    {
        //assign the (next pointer) of the last element(previously last) of the queue to
        //the newly added element of the queue
        rear->nextPtr = newNode;
        //Make the rear point to that new element
        rear = newNode;
    }
}

//QUEUE FUNCTIONS DEFINTION END

//****************

//MISC FUNCTIONS DEFINTION START

//MISC FUNCTIONS DEFINITION END

//****************

//FILE FUNCTIONS DEFINTION START
void newRecord(FILE *fPtr)
{
    struct Node *current = front;
    int c2 = 1;
    //fprintf(fPtr,"%-20s%-20s%3s%5s%10s%13s\n","First Name","Last Name","ID","Age","Salary","Phone Number");
    while (current != NULL)
    {
        fprintf(fPtr, "%-20s%-20s%3d%5d%10d%13s\n", current->firstName, current->lastName, current->id, current->age, current->salary, current->phone);
        current = current->nextPtr;
        c2++;
    }
    printf("\nA total of %d was recorded into the file", c2);
}

//FILE FUNCTIONS DEFINITON END

//****************




