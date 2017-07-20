//Implementation of queue using aray
#include<stdio.h>
#include<stdlib.h>

#define n 10
int queue[n];
int front=-1,rear=-1;

int isEmpty()
{
	if(front==-1 && rear==-1)
	{return 1;}
	else
	{return 0;}
}

void enqueue(int data)
{
	if((rear+1)%n == front)
	{printf("\n Sorry! Queue is Full");return;}
	else if(isEmpty())
	{
		front=0;rear=0;
	}
	else
	{
		rear=(rear+1)%n;
	}
	queue[rear]=data;
}

void dequeue()
{
	if(isEmpty())
	{printf("\nNo element to delete");}
	else if(front==rear)
	{
		front=-1;rear=-1;
	}
	else
	{
		front=(front+1)%n;
	}
}

void print()
{
	if(isEmpty())
	{printf("\nQueue is empty");return;}
	int i;
	printf("\nQueue is:- ");
	if(rear >=front)
	{
		for(i=front;i<=rear;i++)
		{printf(" %d",queue[i]);}
	}
	else
	{
		for(i=front;i<n;i++)
		{printf(" %d",queue[i]);}
		for(i=0;i<=rear;i++)
		{printf(" %d",queue[i]);}
	}	
	printf("\n");
	
}

int main()
{
	printf("Queue Implementation using circular array");
while(1)
{	
	printf("\n\nPress 1 to Insert an element:\nPress 2 to delete an element:\nPress 3 to check whether queue is Empty or not:\nPress 0 to exit: \n ");
	int c,x;
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			{
				printf("\nEnter element to be inserted: ");
				scanf("%d",&x);
				enqueue(x);
				print();
				break;
			}
		case 2:
			{
				dequeue();
				print();
				break;
			}
		case 3:
			{
				if(isEmpty())
				{printf("\nQueue is Empty");}
				else
				{printf("\nNO, its not Empty");}
				break;
			}
		case 0:
			{
				return 0;
			}
		default:{printf("\nInvalid choice");}
	}
}
}
