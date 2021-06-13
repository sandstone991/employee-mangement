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
void dequeue();
void display();

//QUEUE FUNCTIONS DECLARATION SECTION END

//******

//FILE FUNCTIONS DECLARATION START
void newRecord(FILE *fPtr);
void clearFile();


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
void dequeue()
{
    //Check if the queue is already empty
    if (isEmpty())
    {
        printf("There is no employees to remove\n");
    }
    //if not
    //Check if it's the last element in the queue
    else if (rear == front)
    {
        counter--;
        //make a placeholder pointer point to the node(the only node here)
        //we want to delete
        struct Node *placeHolder = rear;
        //make front and rear point to NULL aka empty the queue
        front = rear = NULL;
        //free the space placeHolder was pointer at
        free(placeHolder);
    }
    else
    {
        counter--;
        //the queue is not empty and its not the last node
        struct Node *placeHolder = front;
        //use a place holder to store the address of the node
        front = front->nextPtr;
        //make front point at the next node
        free(placeHolder);
        //free the space used in the deleted node
    }
}
void display()
{
    if (front == NULL)
    {
        printf("There are currently no registered employees\n");
    }
    else
    {
        struct Node *current = front;
        int c2 = 1;
        while (current != NULL)
        {
            printf("\n  Employee (%d) Data \n", c2);
            printf("\n First name: %s", current->firstName);
            printf("\n last Name: %s", current->lastName);
            printf("\n ID: %d", current->id);
            printf("\n age: %d", current->age);
            printf("\n Phone number: %s", current->phone);
            printf("\n Salary: %d", current->salary);
            printf("\n\t\t-------------------\n");
            current = current->nextPtr;

            c2++;
        }
        printf("\n");
        printf("\n");
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
void clearFile()
{
    FILE *dfPtr;
    if ((dfPtr = fopen("employees.txt", "w")) == NULL)
    {
        puts("ERROR");
        puts("File could not be opened.");
    }
}

//FILE FUNCTIONS DEFINITON END

//****************




