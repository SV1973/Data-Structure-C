/*
 * The Program demonstrates the methods of Searching.
 * 1. Linear Search.
 * 2. Binary Search.
 *  
***/

// ------------------------------------ HEADER FILES -------------------------------------

#include"stdio.h"

// ------------------------------- FUNCTION DECLARATION ----------------------------------

void accept_Elements(int[],int);
void display_Elements(int[],int);
void check_Ascendance(int[],int);
void selection_Sort(int[],int);
void declare_Result(int,int);

int linear_Search(int[],int,int);
int binary_Search(int[],int,int);


// --------------------------------- MAIN FUNCTION ---------------------------------------

int main() {

    int array[15], n, search, choice, index;

    while (1) {

        printf("\n------------------------------------\n");
        printf("\n1. Accept Elements of Array.");
        printf("\n2. Display Elements of Array.");
        printf("\n3. Search using Linear Search Method.");
        printf("\n4. Search using Binary Search Method.");
        printf("\n5. Exit");
        printf("\n\n----------------------------------\n");

        printf("\nEnter your Choice :- ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEhter the number of elements of you want in the Array :- ");
                scanf("%d", &n);
                accept_Elements(array, n);
                break;

            case 2:
                display_Elements(array, n);
                break;

            case 3:
                printf("\nEnter the Elelement you want to Search in the Array :- ");
                scanf("%d", &search);
                index = linear_Search(array, n, search);
                declare_Result(search, index);
                break;

            case 4:
                printf("\nEnter the Elelement you want to Search in the Array :- ");
                scanf("%d", &search);
                check_Ascendance(array, n);
                int index = binary_Search(array, n, search);
                declare_Result(search, index);

            case 5:
                // exit(0);

            default:
                break;
        }

    }

}


// --------------------------------- FUNCTION DEFINITIONS --------------------------------

void accept_Elements(int array[], int n) {

    printf("\n");
    int i;

    for(i=0; i<n; i++) {

        printf("\nEnter Array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    printf("\nElements Accepted Successfully.\n");
}

void display_Elements(int array[], int n) {

    printf("\n");
    int i;

    for(i=0; i<n; i++) 
        printf("\nArray[%d]: %d", i, array[i]);

    printf("\n\nElements Displayed SuccessFully.\n");
}

int linear_Search(int array[], int n, int search) {

    int i;

    for(i=0; i<n; i++) {

        if(array[i]==search) {

            return i;
        }
    }
    return -1;
}

int binary_Search(int array[], int n ,int search) {

    int i, j, mid; 

    i=0;
    j=n-1;

    while (i<=j) {

        mid = (i+j)/2;
        
        if (array[mid]==search)
            return mid;

        else if (array[mid]>search)
            j=mid-1;

        else
            i=mid+1; 
    }
    return -1;
}

void declare_Result(int search, int index) {

    if (index!=-1) {

        printf("\n%d is present in the array at index %d.\n", search, index);
    } else {

        printf("\n%d is not resent in the array.\n");
    }
}

void check_Ascendance(int array[], int n) {

    int i;

    for(i=0; i<n; i++) {

        if (array[i]>array[i+1]) {
            
            printf("\nThe Provided Array is not Sorted! \nBinary Search needsa sorted Array. Hence we'll sort the Array using Selction Sort Technique.");
            selection_Sort(array, n);
        }        
    }
}

void selection_Sort (int array[], int n) {

    int i,j,temp;

    for(i=0; i<n-1; i++) {

        for(j=i+1; j<n; j++){

            if(array[i]>array[j]){

                temp = array[i];
                array[i] = array[j];
                array[j]  = temp;
            }
        }
    }

    printf("\nSelection Sort Successful.\n");
}

