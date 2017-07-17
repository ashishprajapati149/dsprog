//Insertion at nth position
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head;

void insert(int x,int n)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	struct node *temp1=head;
	temp->data=x;
	if(n==1)
	{
		temp->next=head;
		temp->prev=NULL;
		if(temp1 != NULL)
		{temp1->prev=temp;}
		head=temp;
	}
	else
	{
		struct node *temp1=head;
		int i;
		for(i=0;i<(n-2);i++)
		{temp1=temp1->next;}
		temp->prev=temp1;
		temp->next=temp1->next;
		if(temp1->next != NULL)
		{(temp1->next)->prev=temp;}
		temp1->next=temp;
	}
}

void print()
{
	struct node *temp=head;
	struct node *last;
	printf("Forward List is:- ");
	while(temp!=NULL)
	{
		printf(" %d",temp->data);
		last=temp;
		temp=temp->next;
	}printf("\n");
	printf("Reverse List is:- ");
	while(last!=NULL)
	{
		printf(" %d",last->data);
		last=last->prev;
	}printf("\n");
}


int main()
{
	head=NULL;
	insert(2,1);
	print();
	insert(1,1);
	print();
	insert(4,3);
	print();
	insert(3,3);
	print();
	insert(5,5);
	print();
	return 0;
}
