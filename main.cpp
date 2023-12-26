#pragma once
#include <iostream>
#include "Customer.h"
#include "Transaction.h"
#include "StartMenu.h"

int main()
{
    int CountOfUsers = 0;
    Customer* ListOfUsers = new Customer[1];
    Menu(CountOfUsers, ListOfUsers);
    delete[] ListOfUsers;
}
