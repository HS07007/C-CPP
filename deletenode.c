//4.3.4.1.A)  Write a Program in C to Delete the First node of the list

# include <stdio.h>
#include<conio.h>
# include <malloc.h>
void create(int num);
void display();
void del_begin();
struct node
{
	int data;
	struct node *addr_next;
}*start,*q,*tmp;

void main()
{
	int action,n,m,position,i;
	char choice='y';
	start=NULL;
	clrscr();
	while(1)
	{
		printf("1) Create Linked List\n");
		printf("2) Delete at Beginning\n");
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
				del_begin();
				printf("\n\n");
				display();
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
void del_begin()
{
	tmp=start;
	start=start->addr_next;  //First element deleted
	free(tmp);
	printf("First element is deleted");
	return;
}

void display()
{
	if(start == NULL)     			//linked list is empty
	{
		printf("List is empty\n");
		return;
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
Output for the Program Given in 4.3.4.1.A

1) Create Linked List
2) Delete at Beginning
3) Display
4) Exit
Enter your choice : 1

Enter a number : 91

| 91 | 0 |  -->

								Continue ? y

Enter a number : 92

| 91 | 2082 |  --> | 92 | 0 |  -->

								Continue ? y

Enter a number : 93

| 91 | 2082 |  -->  | 92 | 2090 |  -->  | 93 | 0 |  -->

								Continue ? y

Enter a number : 94

| 91 | 2082 |  -->  | 92 | 2090 |  -->  | 93 | 2098 |  -->   | 94 | 0 |  -->

								Continue ? n



1) Create Linked List
2) Insert at Beginning
3) Display
4) Exit
Enter your choice : 2

First element is deleted

| 92 | 2090 |  -->  | 93 | 2098 |  -->   | 94 | 0 |  -->


								Continue ? y

First element is deleted

| 93 | 2098 |  -->   | 94 | 0 |  -->

								Continue ? y

First element is deleted

| 94 | 0 |  -->

								Continue ? y

First element is deleted

List is empty

								Continue ? n

1) Create Linked List
2) Insert at Beginning
3) Display
4) Exit
Enter your choice : 4


*/