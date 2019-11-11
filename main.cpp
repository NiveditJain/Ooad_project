#include<iostream>
#include "all_includes"

int main()
{
    Customer nivedit;
    nivedit.name[0]='n';
    nivedit.name[1]='\0';
    nivedit.credit_balance=10;
    string email="nivedit";
    register_customer(nivedit,email);
}