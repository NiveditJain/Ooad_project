#include<bits/stdc++.h>
using namespace std;
#include "customer.cpp"
#include "database.cpp"

int customer_portal(string email)
{
    Customer customer;
    customer=get_customer(email);
    string password=get_password();
    
    if(password.length()==0)
        return -1;

    if(!customer.login(email,password))
    {
        cout<<"\n > invalid email password combination";
        return -1;
    }    
}