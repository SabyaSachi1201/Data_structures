/*
Basic implementation of Linear Queues with Arrays.
Read Comment Lines for clearer understanding.
*/


#include<stdio.h>
#define MAX_SIZE 10
int queue[MAX_SIZE];

int front=-1,rear=-1; // In Queues, we use 2 variables to keep track of the number of elements in queue. Empty, uninitialised queue means front and rear both are equal to -1.

int queueisFull(void);
int queueisEmpty(void);
void enqueue(int);
int dequeue(void);
void printQueue(void);

int queueisFull(void) 
{
    if(rear==MAX_SIZE-1) //Since, everytime I enqueue an element, my rear keeps on incrementing, if my rear is equal to the MAXIMUM-1 index in array, it means I have reached the end of queue. 
    {
        printf("Queue is Full\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

int queueisEmpty(void)
{
    if(front==-1 && rear == -1) //Not a single element is present in the queue , so it checks out my initial front and rear conditions.
    {
        printf("Queue is Empty\n");
        return 1;
    }  
    else
    {
        return 0;
    }
}

void enqueue(int number)
{
    if(queueisFull()==0)
    {
        if(front==-1) //check if input is for the first time
        {
            front++; //increment my front
        }
        rear++;
        queue[rear]=number; 
    }
}

int dequeue(void)
{
    int return_value=-1;
    if(queueisEmpty()==0)
    {
        return_value=queue[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front++;
        }
    }
    return return_value;
}

void printQueue(void)
{
    if(queueisEmpty()==1)
    {
        printf("\nCan't print an empty queue");
    }
    else 
    {
        int initial=front;
        while(initial<=rear)
        {
            printf("%d\t",queue[initial]);
            initial++;
        }
    }
}
void main()
{
    int number=0;
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printQueue();
    number=dequeue();
    printf("\n%d is the Dequeued Element!",number);


}
