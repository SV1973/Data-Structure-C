/**
 * Intermediate Commit.
 * 
 * The Program Demonstrates the Stack Operations.
 * 
 * 1. Initialize the stack as empty.
 * 2. Push Elements in the Stack.
 * 3. Pop Elements form the Stack.
 * 4. Check Whether the Stack is Full.
 * 5. Check Whether the Stack is Empty.
 *  
***/


/**
 * 
 *                          -----                         ----- 
 *                          |                                 |
 *                          |            -----------------    |
 *                          |  s -> top  |       87      |    |
 *                          |            |               |    |
 *                          |  s -> top  |       90      |    |
 *                          |            |               |    |
 *      s -> data (stack)   |  s -> top  |       65      |    |
 *                          |            |               |    |
 *                          |  s -> top  |       45      |    |
 *                          |            |               |    |
 *                          |  s -> top  |       77      |    |
 *                          |            |_______________|    |
 *                          |                                 |
 *                          |                                 |
 *                          ----                           ----
 *                                                   
 * 
***/                 


// ------------------------------------ HEADER FILES -------------------------------------

#include"stdio.h"
#include"stdlib.h"
#define MAX 5


// --------------------------- DEFINING THE STRUCTURE OF STACK ---------------------------

typedef struct stack {
    int data[MAX];
    int top;

} stack ;


// ------------------------------- FUNCTION DECLARAATION ---------------------------------

void init(stack *);
int check_Full(stack *);
int check_Empty(stack *);
void push_Element(stack *, int);
void pop_Element(stack *, int);
void show_Stack(stack *);


// ------------------------------------ MAIN FUNCTION ------------------------------------

int main() {

    int x, choice;
    stack s;

    init(&s);

    while (1) {
        
        printf("\n---------------------------------------\n");
        printf("\n1. Push the Element.");
        printf("\n2. Pop the Element.");
        printf("\n3. Check whether Stack is Full.");
        printf("\n4. Check Whether Stack id Empty.");
        printf("\n5. Display the Stack.");
        printf("\n6. Exit");
        printf("\n\n---------------------------------------\n");

        printf("\nEnter your Choice :- ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\nEnter the Element you want to push in the Stack :- ");
                scanf("%d", &x);
                push_Element(&s, x);
                break;

            case 2:
                pop_Element(&s, x);
                break;

            case 3:
                if(check_Full(&s))
                    printf("\nStack is Full.\n");
                else 
                    printf("\nStack is Not Full.\n");
                break;

            case 4: 
                if(check_Empty(&s))
                    printf("\nStack is Empty.\n");
                else 
                    printf("\nStack is Not Empty.\n");
                break;

            case 5:
                show_Stack(&s);
                break;

            case 6:
                printf("\nTERMINATING THE PROGRAM...\n\n\n");
                exit(0);

            default:
                printf("\nYour Choice is Invalid! Please revisit the Menu.");
                break;
        }
    }

    return 0;
}



// -------------------------------- FUNCTION DEFINITION ----------------------------------

void init(stack *s) {

    s->top = -1;
}


void push_Element(stack *s, int x) {

    if(check_Full(s))
        printf("\nStack is Already Full.");

    else {

        s->top = s->top+1;
        s->data[s->top] = x;
        printf("\nPush Operation Successful.\n");
    }
}

void pop_Element(stack *s, int x) {
    if(check_Empty(s))
        printf("Stack is Already Empty.");

    else {

        x = s->data[s->top];
        s->top = s->top-1;
        printf("\nPop Operation Successful.\n");
    }
}

int check_Full(stack *s) {

    if(s->top == (MAX-1))
        return 1;
    
    else 
        return 0;
}

int check_Empty(stack *s) {

    if(s->top == -1)
        return 1;

    else 
        return 0;
}

void show_Stack(stack *s) {

    int i = s->top;

    while (i>=0) {

        printf("\n%d\n", s->data[i]);
        i--;
    }
}




