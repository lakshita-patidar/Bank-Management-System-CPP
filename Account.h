# include <iostream>
# include <string>

using namespace std;

class Account
{
     private:
     string name;
     long long mobileNumber;
     int accountNumber;
     int enteredAccountNumber;
     int pin;
     int enteredPin;
     int confirmPin;
     double balance;
     double depositedBalance;
     double withdrawalBalance;
     int newPin;
     int confirmNewPin;

     public:
     void CreateAccount();
     void DepositMoney();
     void WithdrawMoney();
     void CheckBalance();
     void DisplayAccountDetails();
     void ChangePIN();

};
