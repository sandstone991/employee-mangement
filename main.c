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
void reset();

//QUEUE FUNCTIONS DECLARATION SECTION END

//******

//FILE FUNCTIONS DECLARATION START
void newRecord(FILE *fPtr);
void readFromRecord(FILE *fPtr);
void displayRecordContent(FILE *fPtr);
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
  
    int choice1;
    //Changes the console's color to green
    system("color 0a");
    //FILE stuff
    FILE *cfPtr;
    if ((cfPtr = fopen("employees.txt", "a")) == NULL)
    {
        puts("ERROR");
        puts("File could not be opened.");
    }
    FILE *rfPtr;
    if ((rfPtr = fopen("employees.txt", "r")) == NULL)
    {
        puts("ERROR");
        puts("File could not be opened.");
    }

    {
        //for quitting the while loop underneath
        bool flag = 1;
        while (flag == 1)
        {
            int flag1 = 1;
            displayMenu();
            int ch, val;
            printf("\n Enter your choice: ");
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                enqueue();

                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;

            case 4:
                reset();
                break;
            case 5:

                while (flag1)
                {
                    fileDisplayMenu();
                    scanf("%d", &choice1);
                    switch (choice1)
                    {
                    case 1:
                        newRecord(cfPtr);
                        break;
                    case 2:
                        readFromRecord(rfPtr);
                        break;
                    case 3:
                        clearFile();
                        break;
                    case 4:
                        flag1 = 0;
                        break;
                    default:
                        puts("\n Enter a vaild number");
                        break;
                    }
                }
                break;
            case 6:
                printf("thank you for using our program :)");
                flag = 0;
                break;

            default:
                printf("\n error choose a correct number \n");
            }
        }
        return 0;
    }
}
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
void reset()
{
    //basically repeat the dequeue function till empty
    while (1)
    {
        if (isEmpty())
        {
            break;
        }

        else if (rear == front)
        {
            struct Node *placeHolder = rear;
            front = rear = NULL;
            free(placeHolder);
        }
        else
        {
            struct Node *placeHolder = front;
            front = front->nextPtr;
            free(placeHolder);
        }
    }
    //Clears the screen from any printed text
    system("cls");
}
//QUEUE FUNCTIONS DEFINTION END

//****************

//MISC FUNCTIONS DEFINTION START
void displayMenu()
{
    printf("\n Press 1 to add an empolyee ");
    printf("\n press 2 to delete an emplyee");
    printf("\n press 3 to display employee data");
    printf("\n press 4 to rest the employee data");
    printf("\n press 5 to open the records menu");
    printf("\n press 6 to Exit");
}

//MISC FUNCTIONS DEFINITION END

//****************

//FILE FUNCTIONS DEFINTION START
void fileDisplayMenu()
{
    puts("");
    printf("\n Press 1 to Write from queue to file");
    printf("\n press 2 to to read queue from file");
    printf("\n press 3 to delete file's contents");
    printf("\n press 4 to return to previous menu");
    puts("");
}
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
void readFromRecord(FILE *fPtr)
{
    rewind(fPtr);
    while (1)
    {
        counter++;
        struct Node *newNode = malloc(sizeof(struct Node));
        newNode->nextPtr = NULL;
        fscanf(fPtr, "%s%s%d%d%d%s", &newNode->firstName, &newNode->lastName, &newNode->id, &newNode->age, &newNode->salary, &newNode->phone);
        if (isEmpty())
        {
            front = rear = newNode;
        }

        else
        {
            rear->nextPtr = newNode;
            rear = newNode;
        }
        if (!feof(fPtr))
        {
            break;
        }
    }
}
/*void displayRecordContent(FILE *fPtr){
    rewind(fPtr);
    printf("%-20s%-20s%-3s%-5s%-10s%-13s\n", "First Name", "Last Name", "ID", "Age", "Salary", "Phone Number");
    while (1)
    {struct Node dis;
    char firstname[30];
    char lastname[30];
    char phone[30];
    int id;
    int age;
    int salary;
        fscanf(fPtr,"%s%s%d%d%d%s",firstname, lastname, &id, &age, &salary, phone);
        printf("%-20s%-20s%-3s%-5s%-10s%-13s\n",firstname, lastname, id, age, salary, phone);
        if (!feof(fPtr))
        {
            break;
        }
    }
}*/
//last function not working somewhy
//will work on a fix later

//FILE FUNCTIONS DEFINITON END

//****************




