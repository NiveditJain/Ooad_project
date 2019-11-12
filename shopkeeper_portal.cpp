#include<bits/stdc++.h>
using namespace std;
#include "database.cpp"
#include "shopkeeper.cpp"

int shopkeeper_portal(string email)
{
    Shopkeeper shopkeeper(get_number_of_shops());
    shopkeeper=get_shopkeeper(email);
    cout<<"> Enter your password :: ";
    string password=input_password();
    
    if(password.length()==0)
        return -1;

    if(!shopkeeper.login(password))
    {
        cout<<"> invalid email password combination";
        return -1;
    }

    cout<<"> Welcome "<<shopkeeper.name<<" !\n"; 
}