//Deletion at nth position
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head;

void insert(int x)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	if(head==NULL)
	{
		temp->next=head;
		head=temp;
	}
	else
	{	struct node *temp1=head;
		while(temp1->next!=NULL)
		{
			temp1=temp1->next;
		}
		temp1->next=temp;
		temp->next=NULL;
	}
}
void print()
{
	struct node *temp=head;
	printf("List is:- ");
	while(temp!=NULL)
	{
		printf(" %d",temp->data);
		temp=temp->next;
	}printf("\n");
}

void delete(int n)
{	struct node *temp1=head;
	if(n==1)
	{
		head=temp1->next;
		free(temp1);
	}
	else
	{
		int i;
		for(i=0;i<(n-2);i++)
		{
			temp1=temp1->next;
		}
		struct node *temp2=temp1->next;
		temp1->next=temp2->next;
		free(temp2);
	}
}


int main()
{
	head=NULL;
	insert(2);
	insert(4);
	insert(6);
	insert(8);
	insert(10);//list is: 2 4 6 8 10
	print();
	int n;
	printf("\nEnter position to delete");
	scanf("%d",&n);
	delete(n);
	print();
	return 0;
}

