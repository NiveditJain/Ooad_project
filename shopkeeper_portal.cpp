#include<bits/stdc++.h>
using namespace std;
#include "database.cpp"
#include "shopkeeper.cpp"

int shopkeeper_portal(string email)
{
    Shopkeeper shopkeeper;
    shopkeeper=get_shopkeeper(email);
    cout<<"> Enter your password :: ";
    string password=get_password(6);
    
    if(password.length()==0)
        return -1;

    if(!shopkeeper.login(password))
    {
        cout<<"\n > invalid email password combination";
        return -1;
    }   
}