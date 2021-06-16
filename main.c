#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
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
struct Node* searchingNode=NULL;
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
bool searchByIdInQueue(int ID);
bool isAlreadyInQueue(int ID);
int bringMeTheEmployee(int ID);
void modifyEmployee();
bool DeleteByIdInQueue(int ID);
//QUEUE FUNCTIONS DECLARATION SECTION END

//******

//FILE FUNCTIONS DECLARATION START
void fileDisplayMenu();
void newRecord(FILE *fPtr);
void readFromRecord(FILE *fPtr);
void displayRecordContent();
void clearFile();


//FILE FUNCTIONS DECLARATION END

//******

//MISC FUNCTION DECLARATION START
void displayMenu();
//MISC FUNCTION DECLARATION END
//CHECK IS INTEGER FUNCTIONS DECLARATION START
int getIntegerOnly(int *px);
//CHECK IS INTEGER FUNCTIONS DECLARATION END
//******

/***********************************************************************************************************************/
//Main funtion

int main()
{

    int choice1;
    //Changes the console's color to green
    system("color 0a");
    //FILE stuff
     FILE *cfPtr;
     FILE  *rfPtr;
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
                enqueue(cfPtr);

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
                printf("Enter the Id :\n");
                int ID;
                scanf("%d" , &ID);
                searchByIdInQueue(ID);
                break;
            case 6:
                modifyEmployee();
                break;
            case 7:

            printf("\n Enter the Id :");

             scanf("%d" , &ID);
            DeleteByIdInQueue(ID);
            break;
            case 8:

                while (flag1)
                {
                    fileDisplayMenu();
                    printf(" Your choice: ");
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
                        displayRecordContent();
                        break;
                     case 5:
                     flag1 = 0;
                        break;
                    default:
                        puts("\n Enter a vaild number");
                        break;
                    }
                }
                break;
            case 9:
                printf("thank you for using our program :)");
                flag = 0;
                break;
            default:
                printf("\n error choose a correct number \n");
            }
        }
        return 0;

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
    int i=0;
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->nextPtr = NULL;
    printf("Enter Employee (%d) data :-\n", counter);

    printf("First name: ");
    scanf("%19s", &newNode->firstName);
    puts("");
    printf("Last name: ");
    scanf("%19s", &newNode->lastName);
    puts("");
    do{
        printf("ID: ");
        getIntegerOnly(&newNode->id);
        fflush(stdin);
    }
    while(isAlreadyInQueue(newNode->id));
    puts("");
    printf("Age: ");
        getIntegerOnly(&newNode->age);
        fflush(stdin);
    puts("");
    printf("Phone number: ");
    scanf("%12s", &newNode->phone);
    puts("");
    printf("Salary: ");
        getIntegerOnly(&newNode->salary);
        fflush(stdin);
    puts("");


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
    counter=0;
    system("cls");
}
bool searchByIdInQueue(int ID){
    struct Node *search = front;
    while ( search != NULL ){

        if ( search->id == ID )
        {
            printf("\nEmployee Found.\n");
            printf("\n\t\t-------------------\n");
            printf("\n First name: %s", search->firstName);
            printf("\n last Name: %s", search->lastName);
            printf("\n ID: %d", search->id);
            printf("\n age: %d", search->age);
            printf("\n Phone number: %s", search->phone);
            printf("\n Salary: %d", search->salary);
            printf("\n\t\t-------------------\n");
            return true;
        }
        else
        {
            search = search->nextPtr;
        }
    }
    printf("Id could not be found in the queue");
    return false;
}
bool isAlreadyInQueue(int ID){
    struct Node *search = front;
     while ( search != NULL ){

        if ( search->id == ID ){
                printf("\nThis ID has already been used please choose another one\n");
                return true;
        }
        else
        {search = search->nextPtr;}
     }
     return false;
}
void modifyEmployee(){
    printf("\nPlease enter the employee's ID");
    printf("\nID: ");
    int id;
        getIntegerOnly(&id);
        fflush(stdin);
    if(searchByIdInQueue(id))
    {   
        bringMeTheEmployee(id);
        printf("\n What do you want to modify\n");
        int flag=1;
        while(flag){
        int choice=1;
        printf("\n Press 1 to modify first name");
        printf("\n Press 2 to modify last name");
        printf("\n Press 3 to modify Salary");
        printf("\n Press 4 to modify Phone Number");
        printf("\n Press 5 to modify Age");
        printf("\n Press 6 to Exit to the previous menu");
        printf("\n Your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nFirst name: ");
                scanf("%19s", &searchingNode->firstName);
                puts("");

                    break;
                case 2:
                printf("\nLast name: ");
                scanf("%19s", &searchingNode->lastName);
                puts("");
                    break;
                case 3:
                printf("\nSalary: ");
                getIntegerOnly(&searchingNode->salary);
                fflush(stdin);
                puts("");
                    break;
                case 4:
                printf("\nPhone number: ");
                scanf("%12s", &searchingNode->phone);
                puts("");
                    break;
                case 5:
                printf("\nAge: ");
                    getIntegerOnly(&searchingNode->age);
                    fflush(stdin);
                    break;
                case 6:
                    flag=0;
                    break;
                default:
                    printf("\nPlease enter a valid number");
                    break;}}}
                else
                {
                    return;
                }
    }
int bringMeTheEmployee(int ID){
searchingNode = front;
     while ( searchingNode != NULL ){

        if ( searchingNode->id == ID ){
                return 1;
        }
          else
        {searchingNode = searchingNode->nextPtr;}
        }
searchingNode=NULL;
    return 0;
     }

bool DeleteByIdInQueue(int ID){
    struct Node *index = front;
    struct Node *before=NULL;
    struct Node *after=NULL;
    struct Node *temp=NULL;

    if(isEmpty()){
        printf("There is no data found");
        return 0;
    }
    if(bringMeTheEmployee(ID)){

    while ( index != NULL )
        {
            if(front->id==ID)
            {
                dequeue();
                return 1;
            }
        if(rear->id==ID){
                for(int i=0;i<counter-2;i++){
                    index=index->nextPtr;
                }
                temp=rear;
                rear=index;
                free(temp);
                index->nextPtr=NULL;
                counter--;
                return 1;

        }

        if ( index->nextPtr->id== ID )
        {
           before=index;
           after=before->nextPtr->nextPtr;
           temp=before->nextPtr;
           before->nextPtr=after;
           free(temp);
           counter--;
           return 1;
        }
        else
        {
            index = index->nextPtr;
        }
    }
    }
    printf("Id could not be found in the queue");
    return 0;
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
    printf("\n press 5 to search in queue by ID");
    printf("\n press 6 to Modify an employee's data");
    printf("\n press 7 to Delete employee by ID");
    printf("\n press 8 to open the records menu");
    printf("\n press 9 to Exit");
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
    printf("\n press 4 to print file's contents on the screen");
    printf("\n press 5 to return to previous menu");
    puts("");
}
void newRecord(FILE *fPtr)
{   
    // fopen() opens files "employees.txt". Exit program if unable to create/open file
    //takes two parameters the first one is the name of the file and the second is the type of operation on the file
    // in this case its "a" meaning Open or create a file for writing at the end of the file—i.e., write operations append data to the file.
    //refer to "c how to program by dietel p480 for a refresher"
    if ((fPtr = fopen("employees.txt", "a")) == NULL)
    {
        puts("ERROR");
        puts("File could not be opened.");
    }
    //this file pointer is used for reading unlike the previous one which was used for writing


    //use the front of the queue to loop through the whole queue
    struct Node *current = front;
    int c2 = 0;
    //stop when you reach NULL aka the end of the queue
      if (NULL != fPtr) {
    fseek (fPtr, 0, SEEK_END);
    int size = ftell(fPtr);

    if (0 == size) {
            if(current!=NULL){
                 fprintf(fPtr, "%-20s%-20s%3d%5d%10d%13s", current->firstName, current->lastName, current->id, current->age, current->salary, current->phone);
                  current = current->nextPtr;
                   c2++;
            }
    }
}
    while (current != NULL)
    {
        //for every node inside the queue print into the file these things
        fprintf(fPtr, "\n%-20s%-20s%3d%5d%10d%13s", current->firstName, current->lastName, current->id, current->age, current->salary, current->phone);
        //refer to the next node
        current = current->nextPtr;
        //increment counter by 1
        //note that the counter isn't essential for the functions its just for aesthetic
        c2++;
    }
    //use the counter to tell the user how many employees they've recorded into the file
    printf("\nA total of %d was recorded into the file", c2);
    fclose(fPtr);
}
void clearFile()
{
    //create a new pointer used to just point at the "emoloyee's.txt" file
    FILE *dfPtr;
    //the idea of how this function work is just the paramater of fopen()
    //"w" deletes any data that was in the file when the pointer is used to point at the file
    //and as simple as that the file is cleared from any previous data
    if ((dfPtr = fopen("employees.txt", "w")) == NULL)
    {
        //and just like before if for any reason the pointer can't reach the file
        //print an error msg for the user
        puts("ERROR");
        puts("File could not be opened.");
    }
        else{
        puts("File cleared successfully.");
    }
    fclose(dfPtr);
}
void readFromRecord(FILE *fPtr)
{
        // fopen() opens files "employees.txt". Exit program if unable to open/access file
    if ((fPtr = fopen("employees.txt", "r")) == NULL)
    {
        puts("ERROR");
        puts("File could not be opened.");
    }

    //rewind function makes sure the pointer to the file is at the start of the file
    //rewind function makes sure the pointer to the file is at the start of the file
    rewind(fPtr);
    int counter1=0;
    while (!feof(fPtr))
    {   //this function reads the file contents and adds them to the current queue on the memory

        //this is the basically the enqueue function modified a little to fit in the file code synatx

        counter++;
        counter1++;
        struct Node *newNode = malloc(sizeof(struct Node));
        newNode->nextPtr = NULL;
        fscanf(fPtr, "%s%s%d%d%d%s", &newNode->firstName, &newNode->lastName, &newNode->id, &newNode->age, &newNode->salary, &newNode->phone);
           //Check whether the queue is empty or not
        if (isEmpty())
        {
             //Make the front pointer and rear pointer point to the newly added element
        //which happens to be the FIRST ELEMENT
            front = rear = newNode;
        }
        //if not
    //Check if it's the last element in the queue
        else
        {
         //assign the (next pointer) of the last element(previously last) of the queue to
        //the newly added element of the queue
            rear->nextPtr = newNode;
          //Make the rear point to that new element
            rear = newNode;
        }

    }
      printf("\nA total of %d Employees was copied from the file to the memory\n",counter1);
        fclose(fPtr);
}
void displayRecordContent(){
    //this function takes a whole line from the employee's text document and prints it on the screen
      FILE *rfrPtr;
    if ((rfrPtr = fopen("employees.txt", "r")) == NULL)
    {
        puts("ERROR");
        puts("File could not be opened.");
    }
    //A string with a size > 72. meaning that the number 80 is just an arbitrary bigger than 72
    //note that 72 is the line length in a text document
    char str[80];
    printf("\n----------------------------------------------------------------------------\n");
    printf("%-20s%-20s%3s%5s%10s%13s\n", "First Name", "Last Name", "ID", "Age", "Salary", "Phone Number");
    while( (fgets(str, 72, rfrPtr)) != NULL )
  {
    printf("%s", str);
  }
  printf("\n----------------------------------------------------------------------------\n");
    fclose(rfrPtr);
}

//FILE FUNCTIONS DEFINITON END
//getIntegerOnly FUNCTIONS DEFINITON START
int getIntegerOnly(int *px){
char userInput[64];
    fgets((char *)px,1,stdin);
    while (1){
      if(!scanf("%d",px)&& !isspace(*px)&& fgets(userInput,63,stdin) != "\n"){
          printf("Please enter an integer value:");
      } 
      else{
        break;
    }
  }
}
//getIntegerOnly FUNCTIONS DEFINITON END
