#include<bits/stdc++.h>
using namespace std;
#include "customer.cpp"
#include "database.cpp"

int customer_portal(string email)
{
    Customer customer;
    cout<<"> Enter your password :: ";
    customer=get_customer(email);
    string password=get_password();
    
    if(password.length()==0)
        return -1;
    customer.print_pass();
    if(!customer.login(password))
    {
        cout<<"\n > invalid email password combination";
        return -1;
    }    
}