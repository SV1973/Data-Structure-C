/*
 *
 * Beginners Commit.
 * 
 * The Program Demonstrates the methods of sorting.
 * 1. Bubble Sort.
 * 2. Selection Sort.
 * 3. Insertion Sort.
 * 
***/

// ------------------------------------ HEADER FILES -------------------------------------

#include"stdio.h"

// ------------------------------- FUNCTION DECLARATION ----------------------------------

void accept_Elements(int[], int);
void display_Elements(int[], int);
void bubble_Sort(int[], int);
void selection_Sort(int[], int);
void insertion_Sort(int[], int);


// --------------------------------- MAIN FUNCTION ---------------------------------------

int main() {
    int array[15], i, n, choice;

    while (1) {
        printf("\n---------------------------------------\n");
        printf("\n1. Accept Elements of Array.");
        printf("\n2. Display the Elements of Array.");
        printf("\n3. Apply Bubble Sort.");
        printf("\n4. Selection Sort.");
        printf("\n5. Insertion Sort.");
        printf("\n6. Exit.");
        printf("\n\n---------------------------------------\n");

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
                bubble_Sort(array, n);
                break;

            case 4:
                selection_Sort(array, n);
                break;

            case 5:
                insertion_Sort(array, n);
                break;
        
            default:
                printf("\nYour Choice is Invalid! Please revisit the Menu.");
                break;

        }

    }

}


// --------------------------------- FUNCTION DEFINITIONS --------------------------------

void accept_Elements(int array[], int n) {
    printf("\n");
    int i;

    for(i=0; i<n; i++) {

        printf("\nEnter Array[%d]: ",i);
        scanf("%d", &array[i]);
    }

    printf("\nElements Added Successfully!\n");
}

void display_Elements(int array[], int n) {
    printf("\n");
    int i;

    for(i=0; i<n; i++) 
        printf("\nArray[%d]: %d", i, array[i]);

    printf("\n\nElements Displayed Successfully!\n");

}

void bubble_Sort(int array[], int n) {
    printf("\n");
    int i, j, temp;

    for(i=1; i<n; i++) {

        for(j=0; j<n-1; j++) {

            if(array[j] > array[j+1]) {

                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    printf("\nBubble Sort Successful!\n");
    
}

void selection_Sort(int array[], int n) {
    printf("\n");
    int i, j, temp;

    for(i=0; i<n-1; i++) {

        for(j=i+1; j<n; j++) {

            if(array[i]>array[j]) {

                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    printf("\nSelection Sort Successful!\n");
}

void insertion_Sort(int array[], int n) {
    printf("\n");
    int i, j, temp;

    for(i=1; i<n; i++) {

        temp = array[i];
        for(j=i-1; j>=0 && array[j]>temp; j--) {

            array[j+1]=array[j];
        }
        array[j+1] = temp;
    }

    printf("\nInsertion Sort Successful!\n");
}

