#ifndef database_cpp
#define database_cpp
#include<bits/stdc++.h>
using namespace std;
#include "customer.cpp"
#include "shopkeeper.cpp"
#include "moderator.cpp"
ulli number_of_shops;

Customer get_customer(string email)
{
    Customer temp;
    temp.name[0]='\0';
    email="database/customer_data/"+email+".ooad";
    fstream file(email.c_str());

    if(!file)
    {
        cout<<"stuck here";
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
    ofstream file(path.c_str());
    file.write((char*)&temp,sizeof(Customer));
    file.close();
}

void register_shopkeeper(Shopkeeper temp,string email)
{    
    string path="database/shopkeeper_data/"+email+".ooad";
    ofstream file(path.c_str());
    file.write((char*)&temp,sizeof(Shopkeeper));
    file.close();
}

bool is_customer(string email)
{
    string path = "database/customer_data/"+email+".ooad";
    
    fstream file1(path.c_str());

    if(file1)
    {
        file1.close();
        return true;
    }

    return false;    
}

bool is_shopkeeper(string email)
{
    string path="database/shopkeeper_data/"+email+".ooad";

    fstream file2(path.c_str());

    if(file2)
    {
        file2.close();
        return true;
    } 

    return false; 
}

bool is_moderator(string email)
{
    char string_email[51];
    copy(email.begin(),email.end(),string_email);
    string_email[email.size()]='\0';

    if(strcmp(moderator.email,string_email)==0)
        return true;
    
    return false;
}

void increase_shop()
{
    fstream file1("database/shopkeeper_data/number_of_shops.num",ios::in);
    ulli number;
    file1>>number;
    number++;
    file1.close();
    fstream file2("database/shopkeeper_data/number_of_shops.num",ios::out);
    file2<<number;
    file2.close();
}

ulli get_number_of_shops()
{
    fstream file1("database/shopkeeper_data/number_of_shops.num",ios::in);
    ulli number;
    file1>>number;
    file1.close();
    return number;    
}

int register_shop(Shop shop)
{
    string id=ulli_to_string(shop.ID);
    string path="database/shop_data/"+id+".shop";
    ofstream file(path.c_str());
    file.write((char*)&shop,sizeof(Shop));
    file.close();    
}

int register_user(string email)
{
    cout<<"> Entered email not found in our database. Do you want to register (y/n)? ";
    char answer;
    cin>>answer;
    if(answer=='n')
        return -1;
    if(answer!='y')
        cout<<"> No a valid choice terminating\n";
    cout<<"> To register as Customer press (c) and to register as shopkeeper press (s)  ";
    cin>>answer;
    cout<<"> Terms and Conditions \n";
    loading(40);
    switch(answer)
    {
        case 'c':
        {
            Customer customer;
            fstream file("database/customer_data/tandc.txt");
            string temp;
            cout<<"> Terms and Conditions are as following\n";
            while(file>>temp)
            {
                cout<<temp<<" ";
            }
            file.close();
            cout<<"\n> I, as a Customer of CC Basket, I hereby declare that I have gone through above terms and conditions and accept them, I also pledge to follow them. I also understand that non-fullfillment of any such issue can lead to legal action.(Yes->y/No->n)  ";
            char ch;
            cin>>ch;
            if(ch=='n')
                return -1;
            if(ch!='y')
            {
                cout<<"> Invalid input\n";
                return -1;
            }
            if(customer.get_details(email)==-1)
                return -1;
            register_customer(customer,email);
            cout<<"> Customer Registration Completed \n";
            return 1;
        }
        break;
        case 's':
        {
            Shopkeeper shopkeeper(get_number_of_shops());
            fstream file("database/shopkeeper_data/tandc.txt");
            string temp;
            cout<<"> Terms and Conditions are as following\n";
            while(file>>temp)
            {
                cout<<temp<<" ";
            }
            file.close();
            cout<<"\n> I, as a Shopkeeper of a shop under fbay network, I hereby declare that I have gone through above terms and conditions and accept them, I also pledge to follow them. I also understand that non-fullfillment of any such issue can lead to legal action.(Yes->y/No->n)  ";
            char ch;
            cin>>ch;
            if(ch=='n')
                return -1;

            if(shopkeeper.get_details(email)==-1)
                return -1;
            register_shopkeeper(shopkeeper,email);
            Shop shop(get_number_of_shops());
            if(shop.get_details(shopkeeper.email)==-1)
                return -1;
            register_shop(shop);
            increase_shop();
            cout<<"> Shopkeeper Registration Completed \n";
            return 2;
        }
        break;
        default:
        {
            cout<<"> Not a valid input\n";
            return 3;
        }
        break;
    }
}


#endif