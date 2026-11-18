#include <iostream>

using namespace std;

string names[3] = {"Thabo","Lerato","Sipho"};
int accountNumbers[3] = {1008, 1025, 1003};
int pins[3] = {2190, 3333, 1088};
double balances[3] = {500, 1000, 250};

void displayMenu()
{
    cout<<"====GCC Bank===="<<endl;
    cout<<"1. Deposit"<<endl;
    cout<<"2. Withdraw"<<endl;
    cout<<"3. Send cash"<<endl;
    cout<<"4. Check Balance"<<endl;
    cout<<"5.Exit"<<endl;
    cout<<"Enter choice:"<<endl;
}

void depsoit(int userIndex)
{
    double amount;
    cout<<"Enter amount to deposit:R"<<endl;
    cin>>amount;

    if(amount > 0)
    {
        balances[userIndex] = balances[userIndex] + amount;
        cout<<"Deposit successful! New balance: R"<<balances[userIndex]<<endl;
    }
    else
    {
        cout<<"Invalid! Amount must be more than 0."<<endl;
    }
}

void withdraw(int userIndex)
{
    double amount;
    cout<<"Enter amount to withdraw: R"<<endl;
    cin>>amount;

    if(amount <= 0)
    {
        cout<<"Invalid! Amount must be more than 0."<<endl;
    }
    else if(amount > balances[userIndex])
    {
        cout<<"Not enough money! Your balance is R"<<balances[userIndex]<<endl;
    }
    else
    {
        balances[userIndex] = balances[userIndex] - amount;
        cout<<"Withdraw successful! New balance: R"<<balances[userIndex]<<endl;
    }
}

void sendCash(int userIndex)
{
    int targetAcc;
    int foundIndex = -1;
    double amount;

    cout<<"Enter account number to send to:"<<endl;
    cin>>targetAcc;

    cout<<"Enter amount to send: R"<<endl;
    cin>>amount;

    for(int i = 0; i < 3; i++)
    {
        if(accountNumbers[i] == targetAcc)
        {
            foundIndex = i;
        }
    }

    if(foundIndex == -1)
    {
        cout<<"Invalid account number. The account does not exist."<<endl;
    }
    else if(amount <= 0)
    {
        cout<<"Invalid! Amount must be more than 0."<<endl;
    }
    else if(amount > balances[userIndex])
    {
        cout<<"Not enough money! Your balance is R"<<balances[userIndex]<<endl;
    }
    else
    {
        balances[userIndex] = balances[userIndex] - amount;
        balances[foundIndex] = balances[foundIndex] + amount;

        cout<<"Sent R"<<amount<<" to "<<names[foundIndex]<<endl;
        cout<<"Your new balance: R"<<balances[userIndex]<<endl;
    }
}

void checkBalance(int userIndex)
{
    cout<<"Hello "<<names[userIndex]<<", your balance is: R"<<balances[userIndex]<<endl;
}

int main()
{
    int acc, pin;
    cout<<"Welcome to GCC Bank"<<endl;
    cout<<"Enter account number:"<<endl;
    cin>>acc;

    cout<<"Enter PIN:"<<endl;
    cin>>pin;

    int userIndex = -1;

    for(int i = 0; i < 3; i++)
    {
        if(accountNumbers[i] == acc && pins[i] == pin)
        {
            userIndex = i;
        }
    }

    if(userIndex == -1)
    {
        cout<<"Wrong account number or PIN. Goodbye!"<<endl;
        return 0;
    }

    cout<<"Welcome, "<<names[userIndex]<<"!"<<endl;

    int choice;

    do
    {
        displayMenu();
        cin>>choice;

        if(choice == 1)
        {
            depsoit(userIndex);
        }
        else if(choice == 2)
        {
            withdraw(userIndex);
        }
        else if(choice == 3)
        {
            sendCash(userIndex);
        }
        else if(choice == 4)
        {
            checkBalance(userIndex);
        }
        else if(choice == 5)
        {
            cout<<"Thank you for banking with us. Goodbye!"<<endl;
        }
        else
        {
            cout<<"Invalid choice! Please enter 1 to 5."<<endl;
        }

    }
    while(choice != 5);

    return 0;
}
