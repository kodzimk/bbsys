#pragma once
#include<iostream>
#include <stdlib.h>
#include "pch.h"
#include<string>
#include<time.h>

using namespace std;
using namespace System;
using namespace Data;
using namespace Data::Sql;
using namespace Data::SqlClient;
using namespace Data::SqlTypes;
using namespace System::Data;



ref class Account
{
public:
	System::String^ name;
	int balance = 0;
	int depositBalance = 0;
	int creditBalance = 0;
	int nameOfCreditCard;
	System::String^ password;

	Account(System::String^  name, int balance, int depositBalance, int creditBalance,System::String^ password) {

		srand(time(NULL));

		this->name = name;
		this->balance = balance;
		this->depositBalance = depositBalance;
		this->creditBalance = creditBalance;
		this->password = password;

		int creditCard = 4000;
		int f = rand() % 999;
	    creditCard += f;

	}
	void Prisvoit(Account account)
	{
		name = account.name;
		balance = account.balance;
		creditBalance = account.creditBalance;
		depositBalance = account.depositBalance;
		password = account.password;
		nameOfCreditCard = account.nameOfCreditCard;

	}
	Account()
	{

	}

	void TakeMoneyFromDeposit() {

		int count = 0;
		std::cout << "Deposit balance: " << depositBalance << endl;
		std::cout << "Enter count thet you wont take: ";
		cin >> count;

		if (count <= depositBalance)
		{
			balance += count;
			depositBalance -= count;
			std::cout << "Succefully taking money form deposit!!!\n";
		}
		else {
			std::cout << "You dont have enough money to takugn money from deposit!!!\n";
		}
	}

	void takeMoneyFromCredit()
	{
		if (creditBalance <= 0)
		{
			int count = 0;
			std::cout << "Enter you money that you want get max 10000: ";
			cin >> count;
			if (count <= 10000)
			{
				creditBalance += creditBalance;
			}
			else
			{
				std::cout << "Bank cant give you so much money!!!\n";
			}
		}
		else
		{
			std::cout << "You already have a credit you cant tale another!!!\n";
		}
	}

	void payForCredit()
	{
		if (creditBalance > 0)
		{
			int count = 0;
			cout << "Enter '1' to pay with balacne or '2' from deposit: ";
			if (count == 1)
			{
				std::cout << "Enter amount of money: ";
				cin >> count;

				if (count <= balance)
				{
					creditBalance -= count;
					balance -= count;
				}
				else {
					cout << "Dont enough money to pay!!!\n";
				}
			}
			else if (count == 2)
			{
				std::cout << "Enter amount of money: ";
				cin >> count;

				if (count <= depositBalance)
				{
					creditBalance -= count;
					depositBalance -= count;
				}
				else {
					cout << "Dont enough money to pay!!!\n";
				}
			}

		}
		else {
			cout << "You havent credit rigth now!!!\n";
		}
	}
};

