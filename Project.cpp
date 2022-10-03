#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <cstring>
#include <sstream>

using namespace std;

class Account
{
	protected:
		
		int account_number;
		int pin_number;
		double available_balance;
		string name;
		string branch_name;
		
	public:
		
		Account()
		{
			account_number = 0;
			pin_number = 0;
			available_balance = 0;
			name = " ";
			branch_name = " ";
		}
		
		Account(int a_number, int pin, double a_balance, string n, string b_name)
		{
			account_number = a_number;
			pin_number = pin;
			available_balance = a_balance;
			name = n;
			branch_name = b_name;
		}
		
		void set_name(string n) 
		{
			this->name = n;
		}
		
		string get_name()
		{
			return name;
		}
		
		void set_branch_name(string b_name) 
		{
			this->branch_name = b_name;
		}
		
		string get_branch_name()
		{
			return branch_name;
		}
		
		void set_account_number(int a_number) 
		{
			this->account_number = a_number;
		}
		
		int get_account_number()
		{
			return account_number;
		}
		
		void set_available_balance(double a_balance) 
		{
			this->available_balance = a_balance;
		}
		
		double get_available_balance()
		{
			return available_balance;
		}
		

		
		void Execute(int x);
		

};
				

class BalanceInquiry: public Account
{
	private:
		
		Account a;
	
	public:
		
		BalanceInquiry()
		{
			
		}
		
		void Execute(int pin)
		{
			
			string name, branch, account_number, p_n, balance;
			bool found_data = 0;
			fstream fin;
			fin.open("Project.txt", ios::in);
			if (fin.fail())
			{
				cout << "File not open" << endl;
			}
			
			else
			{
				while (!fin.eof() && !found_data)
				{
					getline(fin, name, ' ');
					getline(fin, branch, ' ');
					getline(fin, account_number, ' ');
					getline(fin, p_n, ' ');
					getline(fin, balance, '\n');

					stringstream ss(p_n);
					int p = 0;
					ss >> p;

					if (p == pin)
					{
						cout << "Name: " << name << endl;
						cout << "Branch: " << branch << endl;
						cout << "Account number: " << account_number << endl;
						cout << "Balance: " << balance << endl;
						
						found_data = 1;
					}
				}
			}
		
			fin.close();
			
			if (!found_data)
			{
				cout << "Pin is not correct" << endl;
				cout << "Please try again by inserting the card." << endl;
				exit(1);
			}
			
			cout << endl;
		}
		
};

class Withdrawal: public Account
{
	private:
		
		Account a;
	
	public:
		
		Withdrawal()
		{
			
		}
		
		void Execute(int balance)
		{
			double amount;
			int option;
  
			cout << " Withdrawal Menu " << endl;
			cout << " 1 - $20 4 - $100 " << endl;
			cout << " 2 - $40 5 - $200 " << endl;
			cout << " 3 - $60 6 - Cancel Transaction" << endl;
			cout << " Choose a withdrawal option (1 - 6): ";
			cin >> option;
  
			switch(option)
			{
				case 1:
				{
					amount = 20;
					break;
				}
				
				case 2:
				{
					amount = 40;
					break;
				}
		
				case 3:
				{
					amount = 60;
					break;
				}
			
				case 4:
				{
					amount = 100;
					break;
				}
		
				case 5:
				{
					amount = 200;
					break;
				}
		
				case 6:
				{
					cout << "Cancelling the Transaction" << endl;	
					break;
				}	
  
				default:
				{
					cout << "Invalid Choice !!! " << endl;
				}
		
			}
			
			cout << endl;
			
	        a.set_available_balance(balance);
	        
			double x = a.get_available_balance();
  			double y = balance - amount;
  			
			if(y >= 0)
			{
				cout << "Available Balance After Withdrawal: " << fixed << setprecision(2) << y << endl;
				fstream read_From_File;
				read_From_File.open("I191771.txt", ios::in | ios::app);
				read_From_File >> y;
			}
	
			else
			{
				cout << "Insufficient Fund !!!" << endl;
			}
			
			cout << endl;
		}
};

class Deposit: public Account
{
	private:
		
		Account a;
		
	public:
		
		Deposit()
		{
			
		}
		
		void Execute(int balance)
		{
			int x;
			double y;
			double z;
			double xx;
			double yy;
		
			cout << " Enter the amount in: " << endl;
			cout << " 1- DOLLAR" << endl;
			cout << " 2-CENTS" << endl;
			cout << " Enter an option (1-2): ";
			cin >> x;
			
			cout << endl;
		
			cout << "Enter the total amount: ";
			cin >> y;
			
			cout << endl;
			
			a.set_available_balance(balance);
					
			xx = a.get_available_balance();
			
			switch(x)
			{
				case 1:
					
  					yy = balance + y;
  					
					cout << "Available Balance After Deposit: " << fixed << setprecision(2) << yy << endl;	
									
			  		break;
									
				case 2:
					
					z = (y / 100);
					yy = balance + z;
					
					cout << "Available Balance After Deposit: " << fixed << setprecision(2) << yy << endl;
					
					break;
				
				default:
					
					cout << "Invalid choice!!!!!!!" << endl;
			}
			
			cout << endl;
		}
	
};


int main()
{

	Account a;
	BalanceInquiry b;
	Withdrawal w;
	Deposit d;
	int choice;
	int pin;
	
	cout << "Enter the pin: ";
	cin >> pin;
	
	string name, branch, account_number, p_n, balance;
	bool found_data = 0;
	fstream fin;
	
	fin.open("I191771.txt", ios::in);
	
	if (fin.fail())
	{
		cout << "File not open" << endl;
	}
			
	else
	{
		while (!fin.eof() && !found_data)
		{
			getline(fin, name, ' ');
			getline(fin, branch, ' ');
			getline(fin, account_number, ' ');
			getline(fin, p_n, ' ');
			getline(fin, balance, '\n');

			stringstream ss(p_n);
			
			int p = 0;
			ss >> p;

			if (p == pin)
			{
				found_data = 1;
			
			}
			
			

		}
	}
	
	fin.close();

	if (!found_data)
	{
		cout << "Pin is not correct" << endl;
		exit(1);
	}
	
	bool run = 1;
	stringstream ss(balance);
			
	int x = 0;
	ss >> x;
			
	cout << endl;

	while (run)
	{
		cout << endl << "----------------------------" << endl;
    	cout << endl << "      OOP PROJECT   " << endl;
    	cout << endl << "      ***********   " << endl;
   		cout << endl << "       ATM MENU   " << endl <<endl<<endl;
   		cout << endl << "----------------------------" << endl;
   		
   		cout << endl;
   		
		cout << "Main Menu Options: " << endl;
		cout << "1 - View my balance" << endl;
		cout << "2 - Withdraw Cash" << endl;
		cout << "3 - Deposit Cash" << endl;
		cout << "4 - Exit" << endl;
		cout << "Enter a choice: ";
		cin >> choice;
		
		cout << endl;

		switch (choice)
		{
			case 1:
				
				b.Execute(pin);
		
				system("pause");
				system("CLS");

				break;

			case 2:

				w.Execute(x);
				
				system("pause");
				system("CLS");

				break;

			case 3:

				d.Execute(x);
		
				system("pause");
				system("CLS");

				break;

			case 4:
				
				run=0;
				exit(0);

			default:

				cout << "Invalid Choice!!!!!!!" << endl;
				cout << endl;
				
				system("pause");
				system("CLS");
		}
	}
	
	
}
