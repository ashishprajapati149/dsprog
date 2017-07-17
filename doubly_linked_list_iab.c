//Doubly linked list Insertion at Beginning

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
}node;
struct node *head;

void insert(int x)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->prev=NULL;
	if(head==NULL)
	{
		temp->next=head;
		head=temp;
	}
	else
	{
		temp->next=head;
		head->prev=temp;
		head=temp;
	}
}

void print()
{
	struct node *temp = head;
	//struct node *temp1=temp->next;
	//printf("%d%d%d%d",temp->data,temp1->data,(temp1->next)->data,((temp1->next)->next)->data);
	printf("\nForward List is:- ");
	while(temp!=NULL)
	{
		printf(" %d",temp->data);
		temp=temp->next;
	}printf("\n");
}
void revprint()
{	struct node *temp=head;
	if(temp==NULL){printf("Empty");exit;}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		printf("Reverse List is:- ");
		while(temp!=NULL)
		{
			printf(" %d",temp->data);
			temp=temp->prev;
		}printf("\n");
	}
}


int main()
{	head=NULL;
	insert(5);
	print();revprint();
	insert(4);
	print();revprint();
	insert(3);
	print();revprint();
	insert(2);
	print();revprint();
	return 0;
}

