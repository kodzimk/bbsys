#pragma once
#include<iostream>

using namespace System;
using namespace std;



ref class Login
{
public:
	String^ password;
	String^ nickname;

	Login(String^ password, String^ nickname)
	{
		this->password = password;
		this->nickname = nickname;
	}
};

