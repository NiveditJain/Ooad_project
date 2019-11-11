#ifndef database_cpp
#define database_cpp
#include<bits/stdc++.h>
using namespace std;
#include "customer.cpp"
#include "shopkeeper.cpp"

Customer get_customer(string email)
{
    Customer temp;
    temp.name[0]='\0';
    email="database/customer_data/"+email+".ooad";
    fstream file(email.c_str());

    if(!file)
    {
        file.close();
        return temp;
    }

    file.read((char *)&temp,sizeof(Customer));
    file.close();
    return temp;
}

Shopkeeper get_shopkeeper(string email)
{
    Shopkeeper temp;
    temp.name[0]='\0';
    email="database/shopkeeper_data/"+email+".ooad";
    fstream file(email.c_str());

    if(!file)
    {
        file.close();
        return temp;
    }

    file.read((char *)&temp,sizeof(Shopkeeper));
    file.close();
    return temp;    
}

void register_customer(Customer temp,string email)
{    
    string path="database/customer_data/"+email+".ooad";
    ofstream file(path.c_str(),ios::binary | ios::out);
    file.write((char*)&temp,sizeof(Customer));
    file.close();
}

void register_shopkeeper(Shopkeeper temp,string email)
{    
    string path="database/shopkeeper_data/"+email+".ooad";
    ofstream file(path.c_str(),ios::binary | ios::out);
    file.write((char*)&temp,sizeof(Shopkeeper));
    file.close();
}
#endif