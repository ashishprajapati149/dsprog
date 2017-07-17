//Print and reverse using recursion
#include<stdlib.h>
#include<stdio.h>

struct node{
	int data;
	struct node *next;
}node;

struct node *head;

void insert(int x)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	struct node *temp1=head;
	temp->data=x;
	temp->next=NULL;
	if(temp1==NULL)
	{
		head=temp;
		return;
	}
	
	
	while(temp1->next != NULL)
	{
		temp1=temp1->next;
	}
	temp1->next=temp;
	return;	
}

void print(struct node *temp)
{
	if(temp==NULL)
		exit;
	else
	{
		printf(" %d",temp->data);
		print(temp->next);
	}

}

void reverse(struct node *temp)
{
	if(temp->next == NULL)
	{
		head=temp;
		exit;
	}
	else
	{
		reverse(temp->next);
		struct node *temp2=temp->next;
		temp2->next=temp;
		temp->next=NULL;
	}
}

int main()
{	head=NULL;
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	printf("List is: ");
	print(head);
	printf("\n");
	printf("Rev List is: ");
	reverse(head);
	print(head);
	printf("\n");
	return 0;
}
