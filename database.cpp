#ifndef database_cpp
#define database_cpp
#include<bits/stdc++.h>
using namespace std;
#include "customer.cpp"
#include "shopkeeper.cpp"
#include "moderator.cpp"

Customer get_customer(string email)
{
    Customer temp;
    temp.name[0]='\0';
    email="database/customer_data/"+email+".ooad";
    fstream file(email.c_str());

    if(!file)
    {
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

bool database_present(string email)
{
    string path = "database/customer_data/"+email+".ooad";
    
    fstream file1(path.c_str());

    if(file1)
    {
        file1.close();
        return true;
    }

    path="database/shopkeeper_data/"+email+".ooad";

    fstream file2(path.c_str());

    if(file2)
    {
        file2.close();
        return true;
    } 

    return false;   
}

#endif