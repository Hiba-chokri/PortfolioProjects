#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Items
{
	char items[20];
	float price;
	int qty;
};
typedef struct Orders
{
	char customer[50];
	char date[50];
	int numOfItems;
	struct Items itm[50];
}orders;
//Generate the bill header function
void generateBillHeader(char name[50],char date[30])
{
	printf("\n\n");
	printf("\t  CHOKRI. Restaurant");
	printf("\n\t Date:%s",date);
	printf("\n");
	printf("----------------------------------\n");
	printf("items\t\t");
	printf("Total\t\t");
	printf("Price\t\t");
	printf("----------------------------------\n");
	printf("\n\n");
}
void generateBillBody(char item[30],int qty,float price)
{
	printf("%s\t\t",item);
	printf("%d\t\t",qty);
	printf("%.2f\t\t",qty*price);
	printf("\n");
}
void generateBillFooter(float total)
{
	printf("\n");
	float dis= 0.1*total;
	float netTotal=total-dis;
	float cgst=0.09*netTotal;
	float grandTotal=netTotal + 2*cgst;
	printf("----------------------------------\n");
	printf("sub Total\t\t\t%.2f",total);
	printf("\nDiscount @1@%s\t\t\t%.2f","%",dis);
	printf("\n\t\t\t\t------");
	printf("\nNet Total\t\t\t\t%.2f",netTotal);
	printf("\nSGST @9%s\t\t\t\t%.2f","%",cgst);
	printf("\n----------------------------------");
	printf("\nGrand Total\t\t\t\t%.2f",grandTotal);
	printf("\n----------------------------------");
}
int main()
{
	int opt;
	orders ord;
	int n;
	int i;
	char saveBill = 'y',contFlag='y';
	FILE *fp;
	char name[50];
	//dashboard
	while(contFlag=='y')
	{
		float total=0;
		int invoiceFound=0;
		printf("\t==============CHOKRI.Restaurant==============");
		printf("\n1.Generate Invoice");
		printf("\n2.Show all Invoices");
		printf("\n3.Searh Invoice");
		printf("\n4.Exit");
		printf("\n\n");
		printf("Please select your operation :\t");
		scanf("%d",&opt);
		fgetc(stdin);
		switch(opt)
		{
			case 1:
				printf("\nPlease enter the name of the customer:\t");
				fgets(ord.customer,50,stdin);
				ord.customer[strlen(ord.customer)-1] = 0;
				strcpy(ord.date,__DATE__);// we will get the current date
				printf("\nPlease enter the number of items :\t");
				scanf("%d",&n);
				ord.numOfItems = n;
				for(i=0;i<n;i++)
				{
					fgetc(stdin);
					printf("\n\n");
					printf("Please enter the item %d:\t",i+1);
					fgets(ord.itm[i].items,20,stdin);
					ord.itm[i].items[strlen(ord.itm[i].items)-1]=0;
					printf("\nPlease enter the quantity:\t");
					scanf("%d",&ord.itm[i].qty);
					printf("\nPlease enter the unit price :\t");
					scanf("%f",&ord.itm[i].price);
					total+= ord.itm[i].qty*ord.itm[i].price;
				}
				generateBillHeader(ord.customer,ord.date);
				for(i=0;i<ord.numOfItems;i++)
				{
					generateBillBody(ord.itm[i].items,ord.itm[i].qty,ord.itm[i].price);
				}
				generateBillFooter(total);
				printf("\nDo you want to save the Invoice[y/n]:\t");
				scanf("%s",&saveBill);
				if(saveBill=='y')
				{
					fp=fopen("RestaurantBill.pdf","a+");
					fwrite(&ord,1,sizeof(orders),fp);
					if(fwrite!=0)
					{
						printf("\nSuccefully saved");
					}
					else
					 	printf("\nError saving");
					fclose(fp);
				}
				break;
			case 2:
				fp=fopen("RestaurantBill.pdf","r");
				printf("\n*****Your Invoices****\n");
				while(fread (&ord,sizeof(orders),1,fp))
				{
					float tot;
					generateBillHeader(ord.customer,ord.date);
					for(i=0;i<ord.numOfItems;i++){
						generateBillBody(ord.itm[i].items,ord.itm[i].qty,ord.itm[i].price);
						tot+= ord.itm[i].qty*ord.itm[i].price;
					}
					generateBillFooter(tot);
				}
				fclose(fp);
				break;
			case 3:
				printf("\nPlease enter the name of customer:\t");
				//fgetc(stdin);
				fgets(name,50,stdin);
				name[strlen(name)-1]=0;
				fp=fopen("RestaurantBill.pdf","r");
				printf("\n*****Invoice Of The Customer:****\n");
				while(fread (&ord,sizeof(orders),1,fp))
				{
					if(!strcmp(ord.customer,name))
					{
						generateBillHeader(ord.customer,ord.date);
						for(i=0;i<ord.numOfItems;i++){
							generateBillBody(ord.itm[i].items,ord.itm[i].qty,ord.itm[i].price);
							total+= ord.itm[i].qty*ord.itm[i].price;
						}
						generateBillFooter(total);
						invoiceFound=1;
					}
				}
				if(!invoiceFound)
					printf("Sorry the Invoice for %s doesn't exist",name);
				fclose(fp);
				break;
			case 4:
				printf("\n\t\tTake Care :)");
				exit(0);
				break;
			default:
				printf("Sorry invalid option");
				break;
		}
		printf("\nDo you want to perform another operation?[y/n]:\t");
		scanf("%s",&contFlag);
	}
	return 0;
}