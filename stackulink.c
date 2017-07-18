//Implementation of stack using Linked List(Insertion at Beginning)

#include<stdio.h>
#include<stdlib.h>

struct stack{
	int data;
	struct stack *next;
};

struct stack *top=NULL;

void push(int x)
{
	struct stack *newnode=(struct stack *)malloc(sizeof(struct stack));
	newnode->data=x;
	newnode->next=top;
	top=newnode;
}

int isEmpty()
{
	if(top==NULL){return 1;}
	else
	{return 0;}
}

void pop()
{
	if(isEmpty()){printf("\nEmpty Stack, please insert some data first");return;}
	struct stack *temp=top;
	top=temp->next;
	free(temp);
}

int topvalue()
{
	if(isEmpty()){printf("\nEmpty Stack");return 0;}
	return (top->data);
}
void print()
{
	struct stack *temp=top;
	printf("\nThe stack is: ");
	while(temp!=NULL)
	{
		printf(" %d",temp->data);
		temp=temp->next;
	}printf("\n");
}

int main()
{
while(1)
{
	printf("\n\nPress 1 for Push:\nPress 2 for Pop:\nPress 3 for getting the value at top:\nPress 4 to check whether stack is Empty or not:\nPress 0 for exit");
	int c;
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			{
				printf("\nEnter Data in stack:-");
				int x;
				scanf("%d",&x);
				push(x);
				print();
				break;
			}
		case 2:
			{
				pop();
				print();
				break;
			}
		case 3:
			{
				if(topvalue()!=0)
				{printf("\nThe value at top is %d",topvalue());}
				break;
			}
		case 4:
			{
				if(isEmpty())
				{printf("\nEmpty Stack");}
				else
				{printf("\nNot Empty,top=%d",topvalue());}
				break;
			}
		case 0:
			{
				return 0;
			}
		default:{printf("\nInvalid Choice,Enter(0-4)");}
		}
}
}
				
