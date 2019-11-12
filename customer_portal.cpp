#include<bits/stdc++.h>
using namespace std;
#include "customer.cpp"
#include "database.cpp"

int customer_portal(string email)
{
    Customer customer;
    cout<<"> Enter your password :: ";
    customer=get_customer(email);
    string password=input_password();
        
    if(password.length()==0)
        return -1;
    if(!customer.login(password))
    {
        cout<<"> invalid email password combination";
        return -1;
    }    
}