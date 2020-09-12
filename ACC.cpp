#include<iostream.h>
#include<conio.h>
class Account
{
private:
	int accno;
	char name[10];
	float accbal;
public:
	void accept()
	{
		cout<<"ENTER ACC NO,NAME,BALANC";
		cin>>accno>>name>>accbal;
	}
	void display()
	{
		cout<<"\n\tACC NO\t\t : "<<accno;
		cout<<"\n\tCust Name\t\t : "<<name;
		cout<<"\n\tACC BAL\t\t : "<<accbal;
	}
};
void main()
{
	clrscr();
	Account a;
	a.accept();
	a.display();
	getch();
}

