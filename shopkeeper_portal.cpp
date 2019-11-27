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
            return home_page_shpkpr(shopkeeper);
        }
        case 'c':
        {
            return -1;
        }
        }
        break;
    }
    case 2:
    {
        display_shop_details(shopkeeper.shop_category);
        return home_page_shpkpr(shopkeeper);
        break;
              
    }
    case 3:
    {
        Shop shop;
        cout<<">Shop_Category-> "<<shopkeeper.shop_category<<" shop"<<endl;
        shop.add_items(shopkeeper.shop_category); 

        cout<<"item added sucessfully";
        return home_page_shpkpr(shopkeeper);
        break;
    }
    case 4:
    {
        display_shop_details(shopkeeper.shop_category);
        cout << ">Enter the ID of the item whose record is to be updated : ";
        ulli num;
        cin >> num;
        Item item = get_item(shopkeeper.shop_category, num);
        string name(shopkeeper.shop_category);
        update_item_record(item, name);
        return home_page_shpkpr(shopkeeper);
        break;
    }
    case 5:
    {
        return -1;
    }
    case 6:
    {
        return -1;
    }
    default:
    {
        return -1;
    }
    }
    return -1;
}

int home_page_shpkpr(Shopkeeper shopkeeper){
    cout << "> Welcome " << shopkeeper.name << " !\n";
    cout << "\n";
    cout << ">Select any of the following options (Type the corresponding index to select a option):\n\n";
    cout << ">1)profile\n";
    cout << ">2)view items in the shop\n";
    cout << ">3)add items to shop\n";
    cout << ">4)update item record\n";
    cout << ">5)transaction history\n";
    cout<<">6)Logout\n";
    cout << "\n>";
    ulli option; //contains the input option given by the user
    cin >> option;
    system("clear");
    return process(option,shopkeeper);
}



int shopkeeper_portal(string email)
{
    Shopkeeper shopkeeper(get_number_of_shops());
    shopkeeper=get_shopkeeper(email);
    cout<<"> Enter your password :: ";
    string password=input_password();
    
    if(password.length()==0)
        return -1;

    while(!shopkeeper.login(password))
    {
        cout<<"> invalid email password combination";
        cout<<"\n> Do you want to re-enter password? (y/n)";char input;
        cin>>input;if(input=='y'||input=='Y')
        {
          cout<<"> Enter your password :: ";
          password=input_password();
    
        if(password.length()!=0)
        continue;
        }
        else 
        return -1;
    }
    
    return home_page_shpkpr(shopkeeper);
}
#endif

