#pragma once
#include<iostream>
#include"Account.h"
#include"Login.h"
#include<string>

using namespace std;
using namespace System;
using namespace Data;
using namespace Data::Sql;
using namespace Data::SqlClient;
using namespace Data::SqlTypes;
using namespace System::Data;


ref class Function
{
public:
    SqlConnection^ conn;
    SqlConnectionStringBuilder^ connStringBuilder;

    void ConnectToDb()
    {
        connStringBuilder = gcnew SqlConnectionStringBuilder();
        connStringBuilder->DataSource = "LAPTOP-VK8D2UTK";
        connStringBuilder->InitialCatalog = "Bank";
        connStringBuilder->IntegratedSecurity = true;

        conn = gcnew SqlConnection(Convert::ToString(connStringBuilder));
    }
public:
    void Insert(int creditCard,String^ name,int balance,int deposit,int credit,String^ password)
    {
        ConnectToDb();

        String^ cmdText1 = "INSERT INTO dbo.Account(creditId,Balance,Name,Deposit,Credit,password) VALUES(@I,@N,@ID,@D,@C,@P)";
        SqlCommand^ command1 = gcnew SqlCommand(cmdText1, conn);
        command1->Parameters->AddWithValue("@I", creditCard);
        command1->Parameters->AddWithValue("@ID", name);
        command1->Parameters->AddWithValue("@N", balance);
        command1->Parameters->AddWithValue("@D", deposit);
        command1->Parameters->AddWithValue("@C", credit);
        command1->Parameters->AddWithValue("@P", password);
        
        conn->Open();
        command1->ExecuteNonQuery();

        if (conn != nullptr)
        {          
              conn->Close();           
        }    

    }

    void DeleteFromDB(int creditCard)
    {
        ConnectToDb();

        String^ cmdText1 = "DELETE FROM dbo.Account WHERE creditId =@N";

        SqlCommand^ command1 = gcnew SqlCommand(cmdText1, conn);

        command1->Parameters->AddWithValue("@N", creditCard);
        conn->Open();
        command1->ExecuteNonQuery();

        if (conn != nullptr)
        {

       
            conn->Close();

        }

    }

    int sendMoney(int creditid,int money)
    {
        ConnectToDb();

        String^ cmdText = "SELECT * FROM dbo.Account";
        SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
        conn->Open();
        SqlDataReader^ reader = cmd->ExecuteReader();
        bool isFind = false;

        while (reader->Read()) {

            if (creditid == Convert::ToInt32(reader["creditId"]))
            {
                int amount = 0;
                printf("Enter amount of money: ");
                cin >> amount;
                isFind = true;
                if (amount <= money)
                {
                    money -= amount;
                    Account account(" ", 0, 0, 0, " ");
                    account.name = reader["Name"]->ToString();
                    account.balance = Convert::ToInt32(reader["Balance"]);
                    account.creditBalance = Convert::ToInt32(reader["Credit"]);
                    account.depositBalance = Convert::ToInt32(reader["Deposit"]);
                    account.nameOfCreditCard = Convert::ToInt32(reader["creditId"]);
                    account.balance += amount;
                    account.password = reader["password"]->ToString();
                    DeleteFromDB(creditid);
                    Insert(account.nameOfCreditCard,account.name,account.balance,account.depositBalance,account.creditBalance,account.password);

                }
                else {
                    printf("Dont have enoguh money!!!\n");
                    break;
                }
            }
        }
        if (isFind == false)
        {
            printf("Cant find person");
            return money;
        }
        else
        {
            return money;
        }
        conn->Close();
    }


};

