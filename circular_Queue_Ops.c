/**
 * Intermediate Commit.
 * 
 * The Programm demonstrates the Circular Queue Opearations.
 * 1. Initialize the queue as empty.
 * 2. Enqueue Element in the Queue.
 * 3. Dequeue Element in the Queue.
 * 4. Check Whether the Queue is Full. 
 * 5. Check Whether the Queue is Empty.
 * 6. Didplay the Linear Queue.
 * 
**/

/**
 *               ____                                                       ____
 *              |                                                               |
 *              |    _____________________________________________________      |
 *              |   |        |        |        |        |        |        |     |
 *  q -> data   |   |  98    |        |        |   87   |   54   |   47   |     |
 *              |   |________|________|________|________|________|________|     |
 *              |                                                               |
 *              |                                                               |
 *              |     q -> r                      q -> f                        |
 *              |                                                               |
 *              |                               flow --->                       |
 *              |                                                               |
 *              |____                                                       ____|
 *
 * 
**/

// ---------------------------- HEADER FILES AND PRE-PROCESSORS --------------------------

#include"stdio.h"
#include"stdlib.h"
#define MAX 5


// ------------------------- DEFINING THE STRUCTURE OF QUEUE -----------------------------

typedef struct queue {
    int data[MAX];
    int f, r;

}queue;


// --------------------------------- FUNCTION DECLARATION --------------------------------
void init(queue *);
int check_Full(queue *);
int check_Empty(queue *);
void enqueue_Op(queue *, int x);
int dequeue_Op(queue *);
void display_Queue(queue *);


// ------------------------------------ MAIN FUNCTION ------------------------------------

int main() {

    queue q;
    int x, choice;

    init(&q);

    while (1) {

        printf("\n------------------------------------\n");
        printf("\n1. Enqueue the Element.");
        printf("\n2. Dequeue the Element.");
        printf("\n3. Check whether the queue is Full.");
        printf("\n4. Check whether the queue is Empty.");
        printf("\n5. Display the Queue.");
        printf("\n6. Termiate the Program.");
        printf("\n\n------------------------------------\n");

        printf("\nEnter your Choice :- ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\nEnter the Element you want to Enqueue :- ");
                scanf("%d", &x);
                enqueue_Op(&q,x);
                break;

            case 2: 
                x = dequeue_Op(&q);
                if(x!=-1)
                    printf("\nEnqueue Operation Successful.\n");
                else 
                    printf("\nQueue is Empty.\n");
                break;

            case 3:
                if(check_Full(&q))
                    printf("\nThe Queue is Full.\n");
                else 
                    printf("\nThe Queue is Not Full.\n");
                break;

            case 4:
                if(check_Empty(&q))
                    printf("\nThe Queue is Empty.\n");
                else 
                    printf("\nThe Queue is Not Empty.\n");
                break;

            case 5:
                display_Queue(&q);
                break;

            case 6: 
                exit(0);


            default:
                printf("\nYour Choice is Invalid! Please revisit the Menu.");
                break;
        }
    }
}


// -------------------------------- FUNCTION DEFINITIONS ---------------------------------

void init(queue *q) {

    q -> f = -1;
    q -> r = -1;
}

int check_Full(queue *q) {

    if((q->f==0 && q->r==MAX-1) || (q->f == q->r+1))
        return 1;
    return 0;
}

int check_Empty(queue *q) {

    if(q->f == -1)
        return 1;
    return 0;
}

void enqueue_Op(queue *q, int x) {

    if(check_Full(q))
        printf("\nThe Queue is Full.\n");

    else {
        if (q->f==-1)
            q->f = 0;
        q->r = (q->r+1) % MAX;
        q->data[q->r] = x;
        printf("\nEnqueue Opearation Successful.\n");
    }

}

int dequeue_Op(queue *q) {
    int x;

    if(check_Empty(q))
        return -1;

    else {
        x = q->data[q->f];

        if(q->f == q->r) {
            x = q->data[q->f];
            init(q);

        } else {
            q->f = (q->f+1) % MAX;

        }

    }
}

void display_Queue(queue *q) {

    if(check_Empty(q))
        printf("\nThe Queue is Empty.\n");

    else {
        int i;

        printf("\n");
        for(i=q->f ; i!=q->r; i = (i+1)%MAX){
            printf("%d\t", q->data[i]);
        }
        printf("\n");
    }
}

