//Doubly Linked List all Functions
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head;
int counter=0;
struct node *createnewnode(int data)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	counter++;
	return newnode;
}

void InsertatBeg(int data)
{
	struct node *newnode=createnewnode(data);
	struct node *temp=head;
	newnode->prev=NULL;
	newnode->next=head;
	if(temp!=NULL)
	{temp->prev=newnode;}
	head=newnode;
}
void InsertatEnd(int data)
{
	if(head==NULL)
	{InsertatBeg(data);return;}
	struct node *newnode=createnewnode(data);
	struct node *temp=head;
	newnode->next=NULL;
	while(temp->next!=NULL){temp=temp->next;}
	newnode->prev=temp;
	temp->next=newnode;
}
void InsertatN(int data,int n)
{
	if(head==NULL || n==1)
	{InsertatBeg(data);return;}
	if(n==(counter+1))
	{InsertatEnd(data);return;}
	if(n>=(counter+2))
	{printf("\nInvalid Position Entered Please enter position less or equal to%d\n",(counter+1));return;}
	int i;
	struct node *temp=head;
	for(i=0;i<(n-1);i++)
	{temp=temp->next;}
	struct node *newnode=createnewnode(data);
	newnode->next=temp;
	newnode->prev=temp->prev;
	(temp->prev)->next=newnode;
	temp->prev=newnode;
}

void print()
{
	struct node *temp=head;
	struct node *last;
	printf("\nForward List is:- ");
	while(temp!=NULL)
	{
		printf(" %d",temp->data);
		last=temp;
		temp=temp->next;
	}
	printf("\nReverse List is:- ");
	while(last!=NULL)
	{
		printf(" %d",last->data);
		last=last->prev;
	}printf("\n");
}


void delete(int n)
{
	if(head==NULL)
	{printf("\nList is Empty, Please Insert some data First\n");return;}
	if(n>=(counter+1)){printf("\nInvalid Position,Please Insert less or equal to: %d",counter);return;}
	struct node *temp=head;
	if(n==1)
	{
		if(temp->next!=NULL){(temp->next)->prev=NULL;}
		head=temp->next;
		free(temp);
	}
	else
	{
	int i;
	for(i=0;i<(n-1);i++)
	{temp=temp->next;}
	if(temp->next!=NULL){(temp->next)->prev=temp->prev;}
	(temp->prev)->next=temp->next;
	free(temp);
	}
counter--;
}

int main()
{
	head=NULL;
	printf("#######################DOUBLY Linked List Implementaion########################");
while(1)
{
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
}
	
	return 0;
}

