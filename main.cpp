#include <iostream>
#include "Account.h"
using namespace std;

int main()
{
    int choice;

    cout <<"BANK MANAGEMENT SYSTEM"<< endl;

    cout <<"Welcome To Bank Management System!"<< endl;

    cout <<"Please Choose an Option:"<< endl;

    while(true)
    {

    cout <<"1. Create Account"<< endl;
    cout <<"2. Deposit Money"<< endl;
    cout <<"3. Withdraw Money"<< endl;
    cout <<"4. Check Balance"<< endl;
    cout <<"5. Display Account Details"<< endl;
    cout <<"6. Change PIN"<< endl;
    cout <<"7. Exit Program"<< endl;

    cout<<"Enter Your Choice";

    cin>>choice;

    Account acc;

    switch(choice)
    {
        case 1:
        acc.CreateAccount();
        break;

        case 2:
        acc.DepositMoney();
        break;

        case 3:
        acc.WithdrawMoney();
        break;

        case 4:
        acc.CheckBalance();
        break;

        case 5:
        acc.DisplayAccountDetails();
        break;

        case 6:
        acc.ChangePIN();
        break;

        case 7:
        cout<<"Thank You for using Bank Management System!."<<endl;
     return 0;

        default :
        cout<<"Invalid Choice!"<<endl;
     } 
    }
}
