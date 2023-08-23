#pragma once
#include<iostream>
#include <stdlib.h>
#include<time.h>

using namespace std;


ref class Account
{
public:
	System::String^ name;
	int balance = 0;
	int depositBalance = 0;
	int creditBalance = 0;
	int nameOfCreditCard;

	Account(System::String^  name, int balance, int depositBalance, int creditBalance) {
		srand(time(NULL));
		this->name = name;
		this->balance = balance;
		this->depositBalance = depositBalance;
		this->creditBalance = creditBalance;

		int creditCard = 4000;
		int f = rand() % 999;
	    creditCard += f;
		nameOfCreditCard = creditCard;
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

