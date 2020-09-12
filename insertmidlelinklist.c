//4.3.3.2.A)  Write a Program in C to Insert a node at the Specified Position of the list

# include <stdio.h>
#include<conio.h>
# include <malloc.h>

void create(int num);
void display();
void insert_middle(int num,int mid);

struct node
{
	int data;
	struct node *addr_next;
}*start,*q,*tmp;

void main()
{
	int action,n,middle,i;
	char choice='y';
	start=NULL;
	clrscr();
	while(1)
	{


		printf("1) Create Linked List\n");
		printf("2) Insert at Specified Position\n");
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
				printf("\nEnter a number :  ");
				scanf("%d",&n);
				printf("Enter the position : ");
				scanf("%d",&middle);
				insert_middle(n,middle);
				printf("\n");
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

void insert_middle(int num,int mid)
{
	int i;
	q=start;
	for(i=0;i<mid-2;i++)
	{
		q=q->addr_next;
		if(q==NULL)
		{
			printf("Invalid Position");
			return;
		}
	}

	tmp=malloc(sizeof(struct node) );
	tmp->addr_next=q->addr_next;
	tmp->data=num;
	q->addr_next=tmp;
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
Output for the Program Given in 4.3.3.2.A

1) Create Linked List
2) Insert at Specified Position
3) Display
4) Exit
Enter your choice : 1

Enter a number : 91

| 91 | 0 |  -->

								Continue ? y

Enter a number : 92

| 91 | 2116 |  --> | 92 | 0 |  -->

								Continue ? y

Enter a number : 93

| 91 | 2116 |  -->  | 92 | 2124 |  -->  | 93 | 0 |  -->

								Continue ? n

1) Create Linked List
2) Insert at Specified Position
3) Display
4) Exit
Enter your choice : 2

Enter a number : 45
Enter the position : 2

| 91 | 2132 |  -->  | 45 | 2116 | -->  | 92 | 2124 |  -->  | 93 | 0 |  -->

								Continue ? n

1) Create Linked List
2) Insert at Specified Position
3) Display
4) Exit
Enter your choice : 4

*/