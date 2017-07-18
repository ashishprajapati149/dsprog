//Implementation of stack using array

#include<stdio.h>
#include<stdlib.h>

#define MAX 101

int A[MAX];
int top=-1;

void push(int x)
{
	if(top>(MAX-1)){printf("\nError! Stack OverFlow");return;}
	A[++top]=x;
}



int isEmpty()
{
	if(top==-1)
	{return 1;}
	else
	{return 0;}
}

void pop()
{
	if(isEmpty()){printf("\nError! Empty Stack,Insert some data first");return;}
	top--;
}

int topvalue()
{
	if(isEmpty()){printf("\nEmpty Stack");return 0;}
	return A[top];
}
void print()
{
	int i;
	printf("\nStack is: ");
	for(i=0;i<=top;i++)
	{printf(" %d",A[i]);}
	printf("\n");
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
				printf("\nThe value at top is %d",topvalue());
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
				
