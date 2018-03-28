#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***********************************************************
 *      
 *  This prog use the strategy last in first out (lifo),
 *  In this case, stack have 10 positions [0...9],
 *  Insert the intiger value in the header stack with the method Push() if the header is less than 10 (full),
 *  Remove the last stack value with the method Pop() until the header until it's 0 (empty).
 *
 * *************/

// global vars
int array[10];
int with = 10;
int header = 0;

// Read value to insert
int readValue()
{
    int value;

    printf("\nInsert value: ");
    scanf("%d", &value);

    return value;
}

// insert value
void push()
{    
    int value;
    
    // if stack full
    if (header >= with)
        printf("\n\n * The stack is full!!!\n\n");        
    else
    {
        value = readValue();
        array[header] = value;
        header++;
    }
}

// Remove value from the stack header
void pop()
{
    // if header is more than 0 (not empty)
    if (header > 0)
    {
        header--;
        printf("\n\n * Deleted value of the stack header!!!\n\n"); 
    }        
    else
       printf("\n\n * The stack is empty!!!\n\n"); 
}

// show the stack values
void showStack()
{
    printf("\n\n[ ");
    for (int i = 0; i < header; i++)
    {
        printf("  %d  ", array[i]);
    }
    printf(" ]\n\n");
}

// Show menu options
int showMenu()
{
    int option;

    printf("Insert num(1) to insert new value\n");
    printf("Insert num(2) to delete value\n");
    printf("Insert num(3) to show the stack values\n");   
    printf("Insert another num exit\n");       
    printf("option: ");                     
    scanf("%d", &option);

    return option;
}

// switch the user options
int controllerOptions()
{
    int option;

    option = showMenu();

    switch(option)
    {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            showStack();
            break;
        }
        default:
        {
            option = 0;
            break;
        }
    }

    return option;
}

int main ()
{
    // option positive to first interation
    int option = 1;

    // welcome message
    printf("\nWelcome to Stack Tester\n\n");

    while (option > 0)
    {
        // call controller options
        option = controllerOptions();
    }
   
    return 0;
}
