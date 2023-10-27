//Project -1 on cpp Creation of login page//
#include<bits/stdc++.h>
using namespace std;
void login();
void registration();
void forgot();

int main()
{
	int c;
	cout<<"\t\t\t******************************************************************************\n";
	cout<<"\t\t\t                          WELCOME TO LOGIN PAGE                      \n";
	cout<<"\t\t\t******************************************************************************\n\n\n"<<endl;
	cout<<"\t\t\t__________________________________MENU _______________________________________\n"<<endl;
	cout<<"\t\t\t |Press 1 to LOGIN                    |"<<endl;
	cout<<"\t\t\t |Press 2 to Register                 |"<<endl;
	cout<<"\t\t\t |Press 3 to if forgot your PASSWORD  |"<<endl;
	cout<<"\t\t\t |Press 4 to EXIT                     |"<<endl;
	cout<<"\n\t\t\t Please enter your choice :";
	cin>>c;
	cout<<endl;
	switch(c)
	{
		case 1:
			login();
			break;
		case 2:
			registration();
			break;
		case 3:
			forgot();
			break;
		case 4:
			cout<<"\t\t\t Thank you !! \n"<<endl;
			break;
		default :
			system("cls");
			cout<<"\t\t\tPlease Select from the options give above\n\n"<<endl;
			main();
			
	}
}
void login()
{
	int count;
	string uid,password,id,pass;
	system("cls");
	cout<<"\t\t\t Please Enter the user name and password: "<<endl;
	cout<<"\t\t\t USERNAME:";
	cin>>uid;
	cout<<"\t\t\t PASSWORD:";
	cin>>password;
	ifstream input("records.txt");
	while(input>>id>>pass)
	{
		if(id==uid && pass==password)
		{
			count=1;
			system("cls");
		}
	}
	input.close();
	if(count==1)
	{
		cout<<"\t\t\t"<<uid<<"\n\t\t\tYOUR LOGIN IS SUCCESSFULL \n\t\t\tThanks for logging in !\n";
		main();
		
	}
	else
	{
		cout<<"\n\t\t\t Login Error Please check your user name\n";
		main();
	}
}
void registration()
{
	string  ruserid,rpassword,rid,rpass;
	system("cls");
	cout<<"\t\t\tEnter username : ";
	cin>>ruserid;
	cout<<"\t\t\tEnter Password :  ";
	cin>>rpassword;
	ofstream f1("records.txt",ios::app);
	f1<<ruserid<<' '<<rpassword<<endl;
	cout<<"\t\t\tRegistration is Successful!! \n";
	main();
	
}
void forgot()
{
	int opt;
	system("cls");
	cout<<"\t\t\tYou Forget the password No worries \n";
	cout<<"\t\t\t\tPress 1 to search your id by username "<<endl;
	cout<<"\t\t\t\tPress 2 to go back to main menu "<<endl;
	cout<<"\t\t\tEnter your choice : ";
	cin>>opt;
	switch(opt)
	{
		case 1:
			{
				int c=0;
				string suserid,sid,spass;
				cout<<"\t\t\tEnter username which you remembered :";
				cin>>suserid;
				ifstream f2("records.txt");
				while(f2>>sid>>spass)
				{
					if(sid==suserid)
					{
						c=1;
					}
					
				}
				f2.close();
				if(c==1)
				{
					cout<<"\n\t\tYour Account is found ";
					cout<<"\n\t\tYour Password is : "<<spass;
				}
				else
				{
					cout<<"Sorry Your Account is not found! \n";
					main();
				}
				break;
				
				
			}
			case 2:
				{
					main();
					
				}
			default :
				cout<<"\t\t\tWrong Choice Plss Try again"<<endl;
				forgot();
	}
	
	
}

