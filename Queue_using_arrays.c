
#include<stdio.h>
#define MAX_SIZE 10
int queue[MAX_SIZE];
int front=-1,rear=-1;
int queueisFull(void);
int queueisEmpty(void);
void enqueue(int);
int dequeue(void);
void printQueue(void);

int queueisFull(void)
{
    if(rear==MAX_SIZE-1)
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
    if(front==rear || rear == -1)
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
    int return_value=0;
    if(queueisEmpty()==0)
    {
        return_value=queue[front++];
        if(front==MAX_SIZE-1)
        {
            front=-1;
            rear=-1;
        }
    }
    return return_value;
}

void printQueue(void)
{
    int initial=front;
    while(initial<=rear)
    {
        printf("%d\t",queue[initial]);
        initial++;
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
