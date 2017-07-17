//Doubly linked list Insertion at end
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head;
void insert(int x)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	if(head==NULL)
	{
		temp->prev=head;
		head=temp;
	}
	else
	{
		struct node *temp1=head;
		while(temp1->next!=NULL)
		{temp1=temp1->next;}
		temp->prev=temp1;
		temp1->next=temp;
	}
}

void print()
{
	struct node *temp=head;
	struct node *last;
	printf("Forward List is: ");
	while(temp!=NULL)
	{
		printf(" %d",temp->data);
		last=temp;
		temp=temp->next;
	}printf("\n");
	printf("Reverse List is: ");
	while(last!=NULL)
	{
		printf(" %d",last->data);
		last=last->prev;
	}printf("\n");
}

int main()
{
	head=NULL;
	insert(1);
	print();
	insert(2);
	print();
	insert(3);
	print();
	insert(4);
	print();
	insert(5);
	print();
	return 0;
}
