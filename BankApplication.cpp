#include "pch.h"
#include<iostream>
#include"Login.h"
#include"Function.h"
#include"Account.h"

using namespace std;
using namespace System;
using namespace Data;
using namespace Data::Sql;
using namespace Data::SqlClient;
using namespace Data::SqlTypes;
using namespace System::Data;





//Data Source = LAPTOP - VK8D2UTK; Initial Catalog = Bank; Integrated Security = True

int main()
{
    Function connecter;
    Account user("", 1000, 0, 0);
    Login login("123", "Kaisar");
  
    String^ stroka;

    printf("SAJXMAJSA");
    

    return 0;
}
