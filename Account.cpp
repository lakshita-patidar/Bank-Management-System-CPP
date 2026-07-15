#include <iostream>
#include<fstream>
#include "Account.h"

using namespace std;

static int nextAccountNumber = 1001;


   void Account::CreateAccount()
   {
      cin.ignore();
      cout<<"Enter Full Name : ";
      getline(cin,name);

      cout<<"Enter Mobile Number : ";
      cin>>mobileNumber;

      cout<<"Enter Initial Deposit Amount : ";
      cin>>balance;

      if(balance<500)
      {
         cout<<"Account cannot be Created. Minimum Initial Deposit is Rs.500"<<endl;
         return;
      }

      cout<<"Create a 4 Digit PIN : ";
      cin>>pin;

      if(pin<1000 ||pin>9999)
      {
         cout<<"PIN must be exactly 4 digits."<<endl;
         return;
      } 

      while(true)
      {
      cout<<"Confirm PIN : ";
      cin>>confirmPin;

      if(pin == confirmPin)
      {
         accountNumber = nextAccountNumber;
         nextAccountNumber++;
         string fileName = name;
         for(int i=0; i<fileName.length(); i++)
         {
            if(fileName[i]==' ')
            {
               fileName[i]='_';
            }
         }
         ofstream fout;
         fout.open("Account.txt", ios::app);
         fout<<accountNumber<<" "<<fileName<<" "<<mobileNumber<<" "<<balance<<" "<<pin<<endl;
         fout.close();

         cout<<"Generating Account Number...."<<endl;
         cout<<"Congratulations!"<<endl;
         cout<<"Your Account has been Created Successfully."<<endl;
         cout<<"Your Account Number is : "<<accountNumber<<endl;
         cout<<"Current Balance : "<<balance<<endl;

         break;

      }
         cout<<"PINs do not match."<<endl;
         cout<<"Please Try Again";
        }
    }
   
   void Account::DepositMoney()
   {
      cout<<"Enter Account Number: "<<endl;
      cin>>enteredAccountNumber;
      cout<<"Enter PIN: "<<endl;
      cin>>enteredPin;
      cout<<"Enter Amount to Deposit: "<<endl;
      cin>>depositedBalance;

      if(depositedBalance<=0)
      {
         cout<<"Invalid Amount!"<<endl;
         return;
      }

      ifstream fin;
      ofstream fout;
      fin.open("Account.txt");
      fout.open("Temp.txt");
      string fileName;
      bool found = false;
      while(fin>>accountNumber>>fileName>>mobileNumber>>balance>>pin)
      {

         if(accountNumber == enteredAccountNumber && pin == enteredPin)
         {
            balance+=depositedBalance;
            found = true;
         }
         fout<<accountNumber<<" "<<fileName<<" "<<mobileNumber<<" "<<balance<<" "<<pin<<endl;
      }
      fin.close();
      fout.close();
      remove("Account.txt");
      rename("Temp.txt","Account.txt");
      if(!found)
      {
         cout<<"Invalid Account Number or PIN."<<endl;
         return;
      }

      cout<<"Congratulation!"<<endl;
      cout<<"Rs. "<<depositedBalance<<"has been deposited successfully."<<endl;
      cout<<"Current Account Balance: "<<balance<<endl;

   }

   void Account::WithdrawMoney()
   {
      cout<<"Enter Account Number: "<<endl;
      cin>>enteredAccountNumber;
      cout<<"Enter PIN: "<<endl;
      cin>>enteredPin;

      cout<<"Enter Amount to Withdraw: "<<endl;
      cin>>withdrawalBalance;

      if(withdrawalBalance<=0)
      {
         cout<<"Invalid Amount!"<<endl;
         return;
      }

      ifstream fin;
      ofstream fout;
      fin.open("Account.txt");
      fout.open("Temp.txt");
      string fileName;
      bool found = false;
      while(fin>>accountNumber>>fileName>>mobileNumber>>balance>>pin)
      {
         if(accountNumber == enteredAccountNumber && pin == enteredPin)
         {
            found = true;
            if(withdrawalBalance>balance)
      {
         cout<<"Insufficient Balance!"<<endl;
         fin.close();
         fout.close();
         remove("Temp.txt");
         return;
      }
            balance-=withdrawalBalance;
         }
         fout<<accountNumber<<" "<<fileName<<" "<<mobileNumber<<" "<<balance<<" "<<pin<<endl;
      }
      fin.close();
      fout.close();
      if(!found)
      {
         remove("Temp.txt");
         cout<<"Invalid Account Number or PIN."<<endl;
         return;
      }
      remove("Account.txt");
      rename("Temp.txt","Account.txt");

      cout<<"Congratulation!"<<endl;
      cout<<"Rs. "<<withdrawalBalance<<"has been Withdrawn successfully."<<endl;
      cout<<"Current Account Balance: "<<balance<<endl;

   }

   void Account::CheckBalance()
   {
      cout<<"Enter Account Number: "<<endl;
      cin>>enteredAccountNumber;
      cout<<"Enter PIN: "<<endl;
      cin>>enteredPin;
      string fileName;
      bool found=false;
      ifstream fin;
      fin.open("Account.txt");
      while(fin>>accountNumber>>fileName>>mobileNumber>>balance>>pin)
      {
         if(accountNumber==enteredAccountNumber && pin==enteredPin)
         {
         found = true;
         break;
         }
      }
      fin.close();

      if(!found)
      {
         cout<<"Invalid Account Number or PIN."<<endl;
         return;
      }

      cout<<"ACCOUNT BALANCE"<<endl;
      cout<<"Account Number: "<<accountNumber<<endl;
      cout<<"Current Account Balance: "<<balance<<endl;

   }

   void Account::DisplayAccountDetails()
   {
      cout<<"Enter Account Number: "<<endl;
      cin>>enteredAccountNumber;
      cout<<"Enter PIN: "<<endl;
      cin>>enteredPin;

      string fileName;
      bool found =false;
      ifstream fin;
      fin.open("Account.txt");
      while(fin>>accountNumber>>fileName>>mobileNumber>>balance>>pin)
      {
         if(accountNumber==enteredAccountNumber && pin==enteredPin)
         {
            found=true;
            break;
         }
      }
      if(!found)
      {
         cout<<"Invalid Account Number or PIN."<<endl;
         fin.close();
         return;
      }
      fin.close();
      for(int i=0; i<fileName.length(); i++)
      {
         if(fileName[i] == '_')
         {
            fileName[i] = ' ';
         }
      }
      cout<<"Account Details"<<endl;
      cout<<"Account Holder Name: "<<fileName<<endl;
      cout<<"Account Number: "<<accountNumber<<endl;
      cout<<"Mobile Number: "<<mobileNumber<<endl;
      cout<<"Current Account Balance: "<<balance<<endl;

   }

   void Account::ChangePIN()
   {
      cout<<"Enter Account Number: "<<endl;
      cin>>enteredAccountNumber;
      cout<<"Enter Current PIN: "<<endl;
      cin>>enteredPin;
      cout<<"Enter New PIN: "<<endl;
      cin>>newPin;

      if(newPin<1000 ||newPin>9999)
      {
         cout<<"PIN must be exactly 4 digits."<<endl;
         return;
      } 

       cout<<"Confirm New PIN: "<<endl;
      cin>>confirmNewPin;
      if(newPin != confirmNewPin)
      {
         cout<<"PIN do not match"<<endl;
         cout<<"Try Again"<<endl;
         return;
      }
      ifstream fin;
      ofstream fout;
      fin.open("Account.txt");
      fout.open("Temp.txt");
      string fileName;
      bool found=false;
      while(fin>>accountNumber>>fileName>>mobileNumber>>balance>>pin)
      {
         if(accountNumber==enteredAccountNumber && pin==enteredPin)
         {
            pin=newPin;
            found = true;
         }
         fout<<accountNumber<<" "<<fileName<<" "<<mobileNumber<<" "<<balance<<" "<<pin<<endl;
      }
      fin.close();
      fout.close();
      if(!found)
      {
         remove("Temp.txt");
         cout<<"Invalid Account Number or PIN."<<endl;
         return;
      }
      remove("Account.txt");
      rename("Temp.txt","Account.txt");
         cout<<"Congratulations!"<<endl;
         cout<<"Your PIN has been Successfully Changed."<<endl;

   }

   
