#ifndef shopkeeper_portal_cpp
#define shopkeeper_portal_cpp
#include<bits/stdc++.h>
using namespace std;
#include "database.cpp"
#include "shopkeeper.cpp"
#include "shop.cpp"

int home_page_shpkpr(Shopkeeper);

int process(ulli option, Shopkeeper shopkeeper)
{
    switch (option)
    {
    case 1:
    {
        cout << ">Name : " << shopkeeper.name << endl;
        cout<<">shop name : "<<shopkeeper.shop_name<<endl;
        cout << ">Email : " << shopkeeper.email << endl;
        cout << ">contact number : " << shopkeeper.contact_number << endl;
        cout << ">Account Number : " << shopkeeper.account_name << endl;
        cout << ">IFSC code : " << shopkeeper.IFSC_code << endl;
        cout << ">Pending amount : " << shopkeeper.pending_amount << endl;
        cout << endl;
        cout << ">select any of the following options :\n";
        cout << ">a)Edit profile\n";
        cout << ">b)go to home page\n";
        cout << ">c)logout\n";
        cout << ">";
        char option1;
        cin >> option1;
        switch (option1){
        case 'a':
        {
            shopkeeper.get_details(shopkeeper.email);
            register_shopkeeper(shopkeeper, shopkeeper.email);
            cout << ">profile updated successfully\n";
            return home_page_shpkpr(shopkeeper);
        }
        case 'b':
        {
            system("clear");
            home_page_shpkpr(shopkeeper);
        }
        case 'c':
        {
            // system("g++ main.cpp -o main && ./main");
            return -1;
        }
        }
        break;
    }
    case 2:
    {
        break;        
    }
    case 3:
    {
        Shop shop;
        cout<<">"<<shopkeeper.shop_name<<endl;
        shop.add_items(shopkeeper.shop_name);
        cout<<"item added sucessfully";
        home_page_shpkpr(shopkeeper);
        break;
    }
    default:
    {
        
    }
    }
}

int home_page_shpkpr(Shopkeeper shopkeeper){
    cout << "> Welcome " << shopkeeper.name << " !\n";
    cout << "\n";
    cout << ">Select any of the following options (Type the corresponding index to select a option):\n\n";
    cout << ">1)profile\n";
    cout << ">2)view items in the shop\n";
    cout << ">3)add items to shop\n";
    cout << ">4)transaction history\n";
    cout<<">5)Logout\n";
    cout << "\n>";
    ulli option; //contains the input option given by the user
    cin >> option;
    system("clear");
    process(option,shopkeeper);
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
    
    return home_page_shpkpr(shopkeeper);
}
#endif

