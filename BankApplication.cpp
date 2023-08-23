#include "pch.h"
#include<iostream>
#include"Function.h"
#include"Account.h"


using namespace std;
using namespace System;
using namespace Data;
using namespace Data::Sql;
using namespace Data::SqlClient;
using namespace Data::SqlTypes;
using namespace System::Data;


void MarshalString(String^ s, string& os) {
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    os = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));
}

void user_create(Function^ connecter = gcnew Function())
{
    string a;
    string pass;
    std::cout << "Enter your nicnName: ";
    cin >> a;
    std::cout << "Create you password: ";
    cin >> pass;
    String^ b = gcnew String(a.c_str());
    String^ pass1 = gcnew String(pass.c_str());
    Account^ account = gcnew Account(b, 100, 0, 0, pass1);
    connecter->Insert(account->nameOfCreditCard,account->name,account->balance,account->depositBalance,
      account->creditBalance  ,account->password);
    
    int number2 = 0;
    string name, password1;
    MarshalString(account->name, name);
    MarshalString(account->password, password1);


    do {

        system("cls");
        cout << "ID: " << account->nameOfCreditCard << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << account->balance << endl;
        cout << "Deposit: " << account->depositBalance << endl;
        cout << "Credit: " << account->creditBalance << endl;
        cout << "Password: " << password1 << endl;

        printf("\nEnter '0' to exit\n");
        printf("Enter '1' to send a money\n");
        printf("Enter '2' take money from deposit\n");
        printf("Enter '3' to take credit\n");
        printf("Enter '4' to pay for credit\n");
        printf("Enter '5' to expand deposit\n");
        printf("Please Enter number: ");
        cin >> number2;

        if (number2 == 1)
        {
            int credit = 0;
            printf("Enter creditId: ");
            cin >> credit;

            account->balance = connecter->sendMoney(credit, account->balance);
        }
        else if (number2 == 2)
        {
            account->TakeMoneyFromDeposit();
            connecter->DeleteFromDB(account->nameOfCreditCard);
            connecter->Insert(account->nameOfCreditCard,account->name,account->balance,account->depositBalance,account->creditBalance,
            account->password);
        }
        else if (number2 == 3)
        {
            account->takeMoneyFromCredit();
            connecter->DeleteFromDB(account->nameOfCreditCard);
            connecter->Insert(account->nameOfCreditCard, account->name, account->balance, account->depositBalance, account->creditBalance,
            account->password);
        }
        else if (number2 == 4)
        {
            account->payForCredit();
            connecter->DeleteFromDB(account->nameOfCreditCard);
            connecter->Insert(account->nameOfCreditCard, account->name, account->balance, account->depositBalance, account->creditBalance,
              account->password);
        }
        else if (number2 == 5)
        {
            account->giveMoneToDeposit();
            connecter->DeleteFromDB(account->nameOfCreditCard);
            connecter->Insert(account->nameOfCreditCard, account->name, account->balance, account->depositBalance, account->creditBalance,
                account->password);
        }

    } while (number2 != 0);
}

void loginUser(Function^ connecter = gcnew Function(), Account^ account = gcnew Account("", 0, 0, 0, ""))
{
    string name;
    string password;
    printf("Enter nickname:");
    cin >> name;
    printf("Enter password:");
    cin >> password;

    connecter->ConnectToDb();

    String^ cmdtext = "SELECT * FROM dbo.Account";
    SqlCommand^ command = gcnew SqlCommand(cmdtext, connecter->conn);

    connecter->conn->Open();

    SqlDataReader^ reader = command->ExecuteReader();

    bool isHailed = false;
    while (reader->Read())
    {
        String^ name1 = gcnew String(name.c_str());
        String^ passwrod2 = gcnew String(password.c_str());
        if (reader["Name"]->ToString() == name1 && reader["password"]->ToString() == passwrod2)
        {
            account->name = reader["Name"]->ToString();
            account->balance = Convert::ToInt32(reader["Balance"]);
            account->depositBalance = Convert::ToInt32(reader["Deposit"]);
            account->creditBalance = Convert::ToInt32(reader["Credit"]);
            account->nameOfCreditCard = Convert::ToInt32(reader["creditId"]);
            account->password = reader["password"]->ToString();
            isHailed = true;
            printf("Succefully enter", account->name, "\n\n");
        }
    }

    if (isHailed == true)
    {
        int number = 0;
        string name2 = " ";
        string password1;
        MarshalString(account->name, name2);
        MarshalString(account->password, password1);

        do {
            system("cls");
            cout << "ID: " << account->nameOfCreditCard << endl;
            cout << "Name: " << name2 << endl;
            cout << "Balance: " << account->balance << endl;
            cout << "Deposit: " << account->depositBalance << endl;
            cout << "Credit: " << account->creditBalance << endl;
            cout << "Password: " << password1 << endl;


            printf("\nEnter '0' to exit\n");
            printf("Enter '1' to send a money\n");
            printf("Enter '2' take money from deposit\n");
            printf("Enter '3' to take credit\n");
            printf("Enter '4' to pay for credit\n");
            printf("Enter '5' to give money for deposit\n");
            printf("Please Enter number: ");
            cin >> number;

            if (number == 1)
            {
                int id = 0;
                printf("Enter id: ");
                cin >> id;

               account->balance= connecter->sendMoney(id, account->balance);
               connecter->DeleteFromDB(account->nameOfCreditCard);
               connecter->Insert(account->nameOfCreditCard, account->name, account->balance, account->depositBalance, account->creditBalance, account->password);

            }
            else if (number == 2)
            {
                account->TakeMoneyFromDeposit();
                connecter->DeleteFromDB(account->nameOfCreditCard);
                connecter->Insert(account->nameOfCreditCard, account->name, account->balance, account->depositBalance, account->creditBalance,
                    account->password);
            }
            else if (number == 3)
            {
                account->takeMoneyFromCredit();
                connecter->DeleteFromDB(account->nameOfCreditCard);
                connecter->Insert(account->nameOfCreditCard, account->name, account->balance, account->depositBalance, account->creditBalance,
                    account->password);
            }
            else if (number == 4)
            {
                account->payForCredit();
                connecter->DeleteFromDB(account->nameOfCreditCard);
                connecter->Insert(account->nameOfCreditCard, account->name, account->balance, account->depositBalance, account->creditBalance,
                    account->password);
            }
            else if (number == 5)
            {
                account->giveMoneToDeposit();
                connecter->DeleteFromDB(account->nameOfCreditCard);
                connecter->Insert(account->nameOfCreditCard, account->name, account->balance, account->depositBalance, account->creditBalance,
                    account->password);
            }


        } while (number != 0);
    }
    else {
        printf("Cant find user!!!\n");
        return;
    }

}

int main()
{
    Function^ connecter = gcnew Function();
    Account^ account1 = gcnew Account("",0,0,0,"");

    int number = 0;
    do {

        printf("Enter '0' to exit\n");
        printf("Enter '1' create a user\n");
        printf("Enter '2' to login user\n");
        printf("Enter number: ");
        cin >> number;

        if (number == 1)
        {
            user_create(connecter);
        }
        else if (number == 2)
        {
            loginUser(connecter, account1);
        }
        
    } while (number != 0);
    

    

    return 0;
}
