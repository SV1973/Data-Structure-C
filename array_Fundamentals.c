/*
 * The Program Demonstrates the following basic operations performed on the array.
 * 1. Accept.
 * 2. Display.
 * 3. Insert.
 * 4. Delete.
 * 
***/


// --- HEADER FILE. ---

#include"stdio.h"

// --- FUNCTION DECLARATION. ---

void accept_Elements(int[], int);
void display_Elements(int[], int);
int insert_Elements(int[], int, int, int);
int delete_Elements(int[], int, int);

// MAIN FUNCTION.
int main () {

    int array[15], i, n, pos, value, choice;

    while (1) {
        
        printf("\n-----------------------------------------\n");
        printf("\n1. Accept Elements of Array.");
        printf("\n2. Display the elements in the Array.");
        printf("\n3. Insert an Element in the Array.");
        printf("\n4. Delete an Element in the Array.");
        printf("\n5. Exit the Program.");
        printf("\n-----------------------------------------\n");

        printf("\nEnter your Choice :- ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter the Number of Elements you want in the Array :- ");
                scanf("%d", &n);
                accept_Elements(array, n);
                break;

            case 2:
                display_Elements(array, n);
                break;

            case 3:
                printf("Enter the Position and Value of the Element to be Inserted :- ");
                scanf("%d %d", &pos, &value);
                insert_Elements(array, n, pos, value);
                break;

            case 4:
                printf("Enter the Position of the Element to be Deleted :- ");
                scanf("%d", &pos);
                delete_Elements(array, n, pos);
                break;

            case 5:
                // exit(0);
                break;
        
            default:
                printf("\nYour Choice is Invalid! Please revisit the Menu.");
                break;

        }

    }

    return 0;
    
}

// --- FUNCTION DEFINITIONS. ---

void accept_Elements(int array[], int n) {
    printf("\n");
    int i;

    for(i=0; i<n; i++) {
        printf("Enter Elelment[%d]: ", i);
        scanf("%d", &array[i]);

    }

}

void display_Elements(int array[],int n) {
    printf("\n");
    int i;

    for(int i=0; i<n; i++) {
        printf("\nArray[%d]: %d",i , array[i]);

    }

}

int insert_Elements(int array[], int n, int pos, int value) {
    printf("\n");
    int i;

    for(i=n-1; i>=pos-1; i--){
        array[i+1] = array[i];
    }

    array[pos-1] = value;
    return n+1;

}

int delete_Elements(int array[], int n, int pos) {
    printf("\n");
    int i;

    for(i=pos-1;  i<=n-1; i++) {
        array[i] = array[i+1];
    }

    return n-1;

}
