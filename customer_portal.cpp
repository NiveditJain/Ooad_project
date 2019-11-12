#include<bits/stdc++.h>
using namespace std;
#include "customer.cpp"

Customer login_customer(string email)
{
    string password=get_password();
    
    char string_password[51];
    copy(password.begin(),password.end(),string_password);
    string_password[password.size()]='\0';

    encrypt(string_password);

    Customer customer=get_customer(email);

    if(strcmp(string_password,customer.password)==0)
        return customer;
    
    customer.email[0]='\0';
    return customer;
}

int customer_portal(string email)
{
    Customer customer;
    customer=login_customer(email);
}