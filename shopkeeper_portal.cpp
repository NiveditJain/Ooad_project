#ifndef shopkeeper_portal_cpp
#define shopkeeper_portal_cpp
#include<bits/stdc++.h>
using namespace std;
#include "database.cpp"
#include "shopkeeper.cpp"

void home_page_shpkpr(char *name){
    cout << "> Welcome " << name << " !\n";
    cout << "\n";
    cout << ">Select any of the following options (Type the corresponding index to select a option):\n\n";
    cout << ">1)profile\n";
    cout << ">2)view items in the shop\n";
    cout << ">3)add items to shop\n";
    cout << ">4)transaction history\n";
    cout << "\n>";
}

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
    
    home_page_shpkpr(shopkeeper.name);

    ulli option;   //contains the input option given by the user
    cin>>option;
    system("clear");

    switch(option){
        case 1:
        {
            cout<<">Name : "<<shopkeeper.name<<endl;
            cout<<">Email : "<<shopkeeper.email<<endl;
            cout<<">contact number : "<<shopkeeper.contact_number<<endl;
            cout<<">Account Number : "<<shopkeeper.account_name<<endl;
            cout<<">IFSC code : "<<shopkeeper.IFSC_code<<endl;
            cout<<">Pending amount : "<<shopkeeper.pending_amount<<endl;
            cout<<endl;
            cout<<">select any of the following options :\n";
            cout<<">a)Edit profile\n";
            cout<<">b)go to home page\n";
            cout<<">c)logout\n";
            cout<<">";
            char option1;
            cin>>option1;
            switch(option1)
                case 'a':
                {
                    shopkeeper.get_details(shopkeeper.email);
                    register_shopkeeper(shopkeeper,shopkeeper.email);
                    cout<<">profile updated successfully\n";
                    home_page_shpkpr(shopkeeper.name);
                }
                case 'b':
                {
                    system("clear");
                    home_page_shpkpr(shopkeeper.name);
                }
                case 'c':
                {
                    return -1;
                }

        }
        case 2:
        {
            
        }
    }
}
#endif

