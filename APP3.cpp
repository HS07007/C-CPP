#include<iostream.h>
#include<conio.h>
class Account
{
private:
	int accNo;
	char custName;
	float accBal;
public:
	int getAccNo()
	{
		return accNo;
	}
	float getAccBal()
	{
		return accBal;
	}
	void setAccBal(float ab)
	{
 		accBal=aB;	
	}
	void acceptData()
	{
		cout<<"\nEnter Acc No";
		cin>>accNo;
		cout<<"\nEnter Customer Name";
		cin>>custName;
		cout<<"\nEnter Account Bal";
		cin>>accBal;
	}
	void display();
};
void Account::displayData()
{
	cout<<"\n\tAccount No\t\t :"<<accNo;
	cout<<"\n\tCust Name\t\t :"<<custName;
	cout<<"\n\tAcc Bal\t\t :"<<accBal;
}

void main()
{
	int i,ch,ano,amt;
	float bal;
	Account arr[3];
	clrscr();
	for(i=0;i<3;i++)
	{
		arr[i].acceptData();
	}
	for(i=0;i<3;i++)
	{
cout<<"\n--------ACCOUNT "<<i+1<<" Details-----";
		arr[i].displayData();
	}
cout<<"DO you want to Performed 
Trasaction Press 1";
	cin>>ch;	
	if(ch==1)
	{
	cout<<"\n\tEnter Account No ";
		cin>>ano;//103
		for(i=0;i<3;i++)
		{
		if(ano==arr[i].getAccNo())
		{
			flag=1;
		break;
		}			}
		}
	}
if(flag==1)
{
	cout<<"\n1-Deposit\n2-With";
cout<<"\n\tEnter your Choice...Press 1";
	cin>>ch;
	if(ch==1)
	{
	cout<<"\nEnter Amount to Deposit";
	cin>>amt;//1000
	bal=arr[i]	.getAccBal();//3000
	bal=bal+amt;//3000+1000=4000		
	arr[i].setAccBal(bal);
cout<<"\n---After Trasaction Account Details is ";
	arr[i].displayData();
	}
	}
	getch();
}
















