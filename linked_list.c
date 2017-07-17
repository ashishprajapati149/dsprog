//Linked_List
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head;
int c=0;

void InsertatBeg(int data)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=head;
	head=newnode;
	c++;
}
void InsertatEnd(int data)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	struct node *temp=head;
	if(temp==NULL)
	{
		head=newnode;
		c++;
	}
	else
	{
		while(temp->next!=NULL){temp=temp->next;}
		temp->next=newnode;
		c++;
	}
}
void InsertatN(int data,int n)
{
	if(n<=(c+1))
	{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	struct node *temp=head;
	if(n==1)
	{
		newnode->next=head;
		head=newnode;
		c++;
	}
	else
	{
		int i;
		for(i=0;i<(n-2);i++){temp=temp->next;}
		newnode->next=temp->next;
		temp->next=newnode;
		c++;
	}
	}
	else
	{
		printf("\nInvalid Position Entered");
	}

}

void print()
{
	struct node *temp=head;
	printf("\n\nList is:- ");
	while(temp!=NULL)
	{
		printf(" %d",temp->data);
		temp=temp->next;
	}
}

void delete(int n)
{
	struct node *temp=head;
	if(head==NULL || n>c) 
	{printf("\nInvalid node or list is empty");}
	else
	{
		if(n==1)
		{
			head=temp->next;
			free(temp);
		}
		else
		{
			int i;
			for(i=0;i<(n-2);i++){temp=temp->next;}
			struct node *temp2=temp->next;
			temp->next=temp2->next;
			free(temp2);
		}
	}

}



int main()
{
	head=NULL;
	printf("#######################Linked List Implementaion########################");
start:
	printf("\n\nPress 1 for Insertion at Beginning");
	printf("\nPress 2 for Insertion at End");
	printf("\nPress 3 for Insertion at Any position");
	printf("\nPress 4 for Delete at Any position");
	printf("\nPress 5 for exit");
	int c;
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			{
				printf("\nEnter Data-");
				int data;
				scanf("%d",&data);
				InsertatBeg(data);
				print();
				break;
			}
		case 2:
			{
				printf("\nEnter Data-");
				int data;
				scanf("%d",&data);
				InsertatEnd(data);
				print();
				break;
			}
		case 3:
			{
				printf("\nEnter Data and position-");
				int data;
				int pos;
				scanf("%d%d",&data,&pos);
				InsertatN(data,pos);
				print();
				break;
			}
		case 4:
			{
				printf("\nEnter node to be deleted:-");
				int n;
				scanf("%d",&n);
				delete(n);
				print();
				break;
			}
		case 5:
			{
				exit;
				return 0;
			}

		default:{printf("\nInvalid Choice");}
	}
	goto start;
	return 0;
}



