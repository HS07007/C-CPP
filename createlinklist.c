//4.3.2.A)  Write a Program in C to Create a Linked List by Accepting Numbers from User and Display it

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void create(int num);
void display();
struct node
{
	int data;
	struct node *addr_next;
}*start,*q,*tmp;

void main()
{
	int n;
	char choice='y';
	start=NULL;
	clrscr();
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
Output for the Program Given in 4.3.2.A

Enter a number : 91

| 91 | 0 |  -->

									Continue ? y

Enter a number : 92

| 91 | 1924 |  --> | 92 | 0 |  -->

									Continue ? y

Enter a number : 93

| 91 | 1924 |  -->  | 92 | 1932 |  -->  | 93 | 0 |  -->

									Continue ? y

Enter a number : 94

| 91 | 1924 |  -->  | 92 | 1932 |  -->  | 93 | 1940 |  -->  | 94 | 0 |  -->

									Continue ? n

*/