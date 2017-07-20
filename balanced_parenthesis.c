//Check for balanced parenthesis using stack

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char a[50];
int top=-1;

void push(char x)
{
	a[++top]=x;
}

void pop()
{
	--top;
}


int isEmpty()
{
	if(top==-1)
	{return 1;}
	else
	{return 0;}
}

int arepair(char t)
{
	if(a[top]=='(' && t==')'){return 1;}
	else if(a[top]=='{' && t=='}'){return 1;}
	else if(a[top]=='[' && t==']'){return 1;}
	else {return 0;}
}	

int arebalanced(char b[50])
{
	int i;
	for(i=0;i<strlen(b);i++)
	{
		if(b[i]=='(' || b[i]=='{' || b[i]=='[')
		{push(b[i]);}
		else if(b[i]==')' || b[i]=='}' || b[i]==']')
		{
			if(isEmpty() || !arepair(b[i]))
			{return 0;}
			else
			{pop();}
		}
	}
	return isEmpty() ? 1:0;
}

int main()
{
	char c[50];
	printf("Enter series of parenthesis:- ");
	scanf("%[^\n]s",&c);
	printf("\nEntered String is: %s\n",c);
	if(arebalanced(c))
	{printf("\nBalanced\n");}
	else
	{printf("\nNot Balanced\n");}
	return 0;
}

