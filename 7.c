//4.3.4.3.A)  Write a Program in C to Delete a node from the Specified Position of the list

#include <stdio.h>
#include<conio.h>
#include <malloc.h>
void create(int num);
void display();
void del_end(int end);
int count();
struct node
{
	int data;
	struct node *addr_next;
}*start,*q,*tmp;

void main()
{
	int end,action,n,m,position,i;
	char choice='y';
	start=NULL;
	clrscr();
	while(1)

	{
		printf("1) Create Linked List\n");
		printf("2) Delete at End\n");
		printf("3) Display\n");
		printf("4) Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&action);
		switch(action)
		{
		case 1:
			choice='y';
			while(choice=='y'||choice=='Y')
			{
				printf("\nEnter a number :  ");
				scanf("%d",&n);
				create(n);
				printf("\n");
				display();
				printf("\t\t\t\t\t\t\t\tContinue ? ");
				scanf(" %c",&choice);
			}
			getch();
		break;

		case 2:
			choice='y';
			while(choice=='y'||choice=='Y')
			{
				if(start==NULL)
				{
					printf("List is empty\n");
					continue;
				}
				printf("\n");
				end=count();
				del_end(end);
				printf("\n");
				display();
				if(end==1)
				{
					printf("Cannot delete as only one element exists in the 							list\n");
				}
				printf("\t\t\t\t\t\t\t\tContinue ? ");
				scanf(" %c",&choice);

			}
			getch();
		break;
		case 3:
			display();
			break;
		case 4:
			exit();
		}
	}
}

void create(int num)
{
	tmp=malloc(sizeof(struct node));
	tmp->data=num;
	tmp->addr_next=NULL;

	if(start==NULL) 		//check if 1st element
	{
		start=tmp;  		//point start at tmp
	}
	else   				//not 1st element
	{
		q=start;                //point q at start
		while(q->addr_next!=NULL)   //go to end of linked list
		{
			q=q->addr_next;
		}
		q->addr_next=tmp;		//store address
	}
}
int count()
{
	struct node *q=start;
	int cnt=0;
	while(q!=NULL)
	{
		q=q->addr_next;
		cnt++;
	}
	return cnt;
}
void del_end(int end)
{
	int i,cnt=1;
	q=start;
	for(i=0;i<end-2;i++)
	{
		cnt++;
		q=q->addr_next;
	}
	tmp=q->addr_next;
	free(tmp);
	printf("Last element is deleted\n");
	q->addr_next=NULL;
}

void display()
{
	if(start == NULL)     			//linked list is empty
	{
		printf("List is empty\n");
	}
	else
	{
		q=start;                 	//point q at start
		while(q!=NULL)                  //go to end of linked list
		{
			printf("| %d | %d | -->  ", q->data,q->addr_next);
			q=q->addr_next;
		}
		printf("\n\n");
	}
}


/*
Output for the Program Given in 4.3.4.3.A

1) Create Linked List
2) Delete at End
3) Display
4) Exit
Enter your choice : 1

Enter a number : 91


| 91 | 0 |  -->

								Continue ? y

Enter a number : 92

| 91 | 2122 |  --> | 92 | 0 |  -->

								Continue ? y

Enter a number : 93

| 91 | 2122 |  -->  | 92 | 2130 |  -->  | 93 | 0 |  -->

								Continue ? y

Enter a number : 94

| 91 | 2122 |  -->  | 92 | 2130 |  -->  | 93 | 2138 |  -->   | 94 | 0 |  -->

								Continue ? n

1) Create Linked List
2) Delete at End
3) Display
4) Exit
Enter your choice : 2

Last element is deleted

| 91 | 2122 |  -->  | 92 | 2130 |  -->  | 93 | 0 |  -->

								Continue ? y

Last element is deleted

| 91 | 2122 |  -->  | 92 | 0 |  -->

								Continue ? y

Last element is deleted

| 91 | 0 |  -->

								Continue ? y

Last element is deleted

| 91 | 0 |  -->

Cannot delete as only one element exists in the list

								Continue ? n

1) Create Linked List
2) Insert at Beginning
3) Display
4) Exit
Enter your choice : 4

*/