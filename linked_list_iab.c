//Insertion at Beginning
//#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}node;
struct node *head;

void insert(int x)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=head;
	head=temp;
}

void print()
{
	struct node *temp=head;
	printf("\nList is:-");
	while(temp != NULL)
	{
		printf(" %d",temp->data);
		temp=temp->next;
	}printf("\n");
}

int main(){
	head= NULL;
	int n,i,x;
	printf("How many nos?");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		insert(x);
		print(x);
	}
	return 0;
}
