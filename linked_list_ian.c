//Insertiion at nth position
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head;

void insert(int x,int n)
{	int i;
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	if(n==1)
	{
	temp->next=head;
	head=temp;
	return;}
	else
	{
		struct node *temp1=head;
		for(i=0;i<(n-2);i++)
		{
			temp1=temp1->next;
		}
		temp->next=temp1->next;
		temp1->next=temp;
	}
}
int print()
{	int counter=0;
       struct node *temp=head;
       printf("List is:-");
	while(temp!=NULL)
 	{
	printf(" %d",temp->data);
	temp=temp->next;
	counter++;	
	}printf("\n");
return counter;}

int main()
{
	head=NULL;
	insert(1,1);
	insert(2,1);
	insert(3,1);
	insert(5,2);
	insert(6,2);
	insert(8,1);
	insert(4,5);
	insert(7,6);
	int y=print();
	printf("\n\nNodes=%d",y);
	return 0;
}

