/* Bank Management System */

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

/*
The Bank Management System Will Have The Following Operations:

1. Add a Customer to the Bank Server or Open Account for Customer
2. Deposit Money to the Bank Account
3. Withdraw Money from the Bank Account
4. Display Amount of Money Present in Bank Account
5. Remove a Customer from the Bank Server or Close Account for Customer

Note: The Bank Can Accommodate Only 10000 Customers
Note: When A Person Opens A Account Then Set The Password
Note: Whenever A Person Withdraws Money From The Bank Increment The Principal By 7%
*/

int customer_number = 0;

class Bank
{
    int ID;
    string name;
    char type;
    int password;
    float balance = 0;

public:
    void open_account();
    void deposit_money();
    void withdraw_money();
    void display_balance();
    void close_account();
};

void Bank :: open_account()
{
    cout << endl;

    if(customer_number == 10000)
    {
        cout << "Maximum Customer Amount Reached" << endl << endl;
        cout << "Thank You!" << endl << endl;
    }

    ID = customer_number;
    cout << "Your Customer ID is: " << ID << endl;

    cout << "Enter your Name: ";
    cin >> name;

    cout << "Enter your Account Type (C/S): ";
    cin >> type;

    cout << "Set your 4 Digit Password: ";
    cin >> password;

    cout << endl;
}

void Bank :: deposit_money()
{
    cout << endl;

    int check;
    cout << "Enter your Password: ";
    cin >> check;
    if(check == password)
    {
        float deposit;
        cout << "Enter Amount of Money You Would Like to Deposit: ";
        cin >> deposit;
        balance += deposit;
    }
    else{ cout << "Invalid Password Entered" << endl; }

    cout << endl;
}

void Bank :: withdraw_money()
{
    cout << endl;

    int check;
    cout << "Enter your Password: ";
    cin >> check;
    if(check == password)
    {
        balance += 0.07*balance;
        float withdraw;
        cout << "Enter Amount of Money You Would Like to Withdraw: ";
        cin >> withdraw;

        if(withdraw > balance){ cout << "Insufficient Balance" << endl; return; }

        balance -= withdraw;
    }
    else{ cout << "Invalid Password Entered" << endl; }

    cout << endl;
}

void Bank :: display_balance()
{
    cout << endl;

    int check;
    cout << "Enter your Password: ";
    cin >> check;
    if(check == password)
    {
        cout << "Balance: " << balance << endl;
    }
    else{ cout << "Invalid Password Entered" << endl; }

    cout << endl;
}

void Bank :: close_account()
{
    cout << endl;

    int check;
    cout << "Enter your Password: ";
    cin >> check;
    if(check == password)
    {
        // Restore Details to Default Settings
        name = "abc";
        type = 'N';
        password = 0;
        balance = 0;
    }
    else{ cout << "Invalid Password Entered" << endl; }

    cout << endl;
}

using namespace std;

int main()
{
    cout << "/* Bank Management System */" << endl << endl;
    const int N = 10001;
    Bank Customers[N];
    bool flag = true;
    while(flag)
    {
        cout << "Service Available: " << endl;
        cout << "1. Open Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Display Balance" << endl;
        cout << "5. Close Account" << endl;

        int option;

        cout << endl << "Enter Service Option: ";
        cin >> option;

        switch(option)
        {
            int id;
        case 1:
            Customers[customer_number].open_account();
            ++customer_number;
            break;
        case 2:
            cout << "Enter your ID: ";
            cin >> id;
            if(id > customer_number){ cout << "Invalid ID Entered" << endl; break; }
            Customers[id].deposit_money();
            break;
        case 3:
            cout << "Enter your ID: ";
            cin >> id;
            if(id > customer_number){ cout << "Invalid ID Entered" << endl; break; }
            Customers[id].withdraw_money();
            break;
        case 4:
            cout << "Enter your ID: ";
            cin >> id;
            if(id > customer_number){ cout << "Invalid ID Entered" << endl; break; }
            Customers[id].display_balance();
            break;
        case 5:
            cout << "Enter your ID: ";
            cin >> id;
            if(id > customer_number){ cout << "Invalid ID Entered" << endl; break; }
            Customers[id].close_account();
            break;
        default:
            cout << "Invalid Option Entered" << endl;
        }

        char decision;

        cout << endl;
        cout << "Would you like to Continue? (Y/N): ";
        cin >> decision;

        if(decision == 'Y'){ system("cls"); cout << "/* Bank Management System */" << endl << endl; }

        else{ flag = false; cout << endl << "Thank You!" << endl; }
    }
    return 0;
}
