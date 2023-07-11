#include<stdio.h>
int main()
{
	// declaration of the variables we will be using;
	char card;
	int a,b,i;
	int diff;
	int n;
	int p;
	char cad;
	printf("Welcome To The ATM \n ");
	printf("Please insert your card : ");
	scanf("%c",&card);
	if(card == 'H')
	{
		printf("Hello Hiba chokri \n");
		printf("Press 1 to withdrawl the money from your account:  \n");
		printf("Press 2 to see the balance : ");
		b = 5000;
		scanf("%d",&n);
		if(n==1)
		{
			printf("Please enter the 4 digit pin : ");
			scanf("%d",&p);
			if(p==1234)
			{
				printf("Please enter the amount to withdrawl : ");
				scanf("%d",&a);
				if( a > b)
				{
					printf("the amount you entered is insufficient");
				}
				else{
					printf("Collect the money \n");
					diff = b - a;
					printf("your bank balance is %d: ",diff);
				}
			}
			else 
			{
				printf("incorrect pin \n");
				printf("Please try again : \n");
				scanf("%d",&p);
				if(p==1234)
				{
					printf("Please enter the amount to withdrawl : \n");
					scanf("%d",&a);
					if( a > b)
					{
						printf("the amount you entered is insufficient");
					}
					else{
						printf("Collect the money \n");
						diff = b - a;
						printf("your bank balance is %d: ",diff);
					}
				}
				else 
				{
					printf("Your request has been blocked now \n");
					printf("Please try again :\n");
				}
			}
		}
		else if(n==2)
		{
			printf("Please enter your 4-digit pin :\n");
			scanf("%d",&p);
			if(p!=1234)
			{
				printf("Please try again :\n");
				scanf("%d",&p);
				if(p!=1234)
				{
					printf("Your request has been blocked \n");
					printf("Please try again :\n");
				}
				else
				{
					printf("Your bank account is %d",b);
				}
			}
			else
			{
				printf("Your bank account is %d",b);
			}
		}
	}
	return(0);
}