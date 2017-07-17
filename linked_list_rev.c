//Reverse a linked list using ITERATIVE methhod
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head;

void insert(int x,int n)
{	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	if(n==1)
	{
		temp->next=NULL;
		head=temp;
	}
	else
	{
		int i;
		struct node *temp1=head;
		for(i=0;i<(n-2);i++)
		{
			temp1=temp1->next;
		}
		temp->next=temp1->next;
		temp1->next=temp;
	}
}

void reverse()
{
	struct node *next,*prev,*curr;
	prev=NULL;
	curr=head;
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	head=prev;
}




void print()
{
	struct node *temp=head;
	printf("\nList is:-");
	while(temp!=NULL)
	{	printf(" %d",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int main()
{
	head=NULL;
	insert(2,1);
	insert(3,2);
	insert(5,3);
	insert(6,4);
	insert(4,3);
	print();
	reverse();
	print();
	return 0;
}

