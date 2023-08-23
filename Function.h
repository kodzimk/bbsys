#pragma once
#include<iostream>
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
        printf("Succefully connected!!!\n");
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
            
            printf("Succefully added!!!\n");
            conn->Close();
            
        }
        else
            printf("Failed adding!!!\n");


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

            printf("Succefully deleted!!!\n");
            conn->Close();

        }
        else
            printf("Failed deleting!!!\n");
    }


};

