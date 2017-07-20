//reverse a no. using recursion
#include<stdio.h>
#include<math.h>
//int num1,limit;
int reverse(int num,int limit)
{
	if(limit==1){return num;}
	else
	{
		return(((num%10) * pow(10,limit-1))+reverse(num/10,--limit));
	}
}
int main()
{
	int num,temp;
	int length=0;
	printf("Enter a no to reverse it");
	scanf("%d",&num);
	temp=num;
	while(temp!=0)
	{temp=temp/10;length++;}
	printf("Reverse of %d is %d\n",num,reverse(num,length));
	return 0;
}
	
