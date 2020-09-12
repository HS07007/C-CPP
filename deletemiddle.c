// Write a Program in C to Delete a node from the Specified Position of the list

#include <stdio.h>
#include<conio.h>
#include <malloc.h>
void create(int num);
void display();
void del_middle(int mid);
struct node
{
	int data;
	struct node *addr_next;
}*start,*q,*tmp;

void main()
{
	int action,n,mid,position,i;
	char choice='y';
	start=NULL;
	clrscr();
	while(1)
	{

		printf("1) Create Linked List\n");
		printf("2) Delete at Specified Position\n");
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
				printf("\nEnter the position : ");
				scanf("%d",&mid);
				if(mid==1)
				{
					printf("\nCannot delete element at 1st position\n\n");
				}
				else
				{
					printf("\n");
					del_middle(mid);
					printf("\n");
					display();
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

void del_middle(int mid)
{
	int i;
	q=start;
	for(i=0;i<mid-2;i++)
	{
		q=q->addr_next;
	}
	tmp=q->addr_next;
	q->addr_next=tmp->addr_next;
	free(tmp);
	printf("Element at position (%d) is deleted\n",mid);
	q=q->addr_next;
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
Output for the Program Given in 4.3.4.2.A

1) Create Linked List
2) Delete at Specified Position
3) Display
4) Exit
Enter your choice : 1

Enter a number : 91

| 91 | 0 |  -->

								Continue ? y

Enter a number : 92

| 91 | 2120 |  --> | 92 | 0 |  -->

								Continue ? y

Enter a number : 93

| 91 | 2120 |  -->  | 92 | 2128 |  -->  | 93 | 0 |  -->

								Continue ? y

Enter a number : 94

| 91 | 2120 |  -->  | 92 | 2128 |  -->  | 93 | 2136 |  -->   | 94 | 0 |  -->

								Continue ? n

1) Create Linked List
2) Delete at Specified Position
3) Display
4) Exit
Enter your choice : 2

Enter the position : 3

Element at position (3) is deleted

| 91 | 2120 |  -->  | 92 | 2136 |  -->  | 94 | 0 |  -->

								Continue ? y

Enter the position : 2

Element at position (2) is deleted

| 91 | 2136 |  -->  | 94 | 0 |  -->

								Continue ? n

1) Create Linked List
2) Delete at Specified Position
3) Display
4) Exit
Enter your choice : 4

*/