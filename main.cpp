#include<bits/stdc++.h>
#include "customer.cpp"
#include "database.cpp"
#include "moderator.cpp"
#include "shop.cpp"
#include "shopkeeper.cpp"
#include "terminal.cpp"
#include "utilities.cpp"
#include "deliveryboy.cpp"
using namespace std;
typedef unsigned long long int ulli;
int main()
{
   string email=initial_display();
   if(!database_present(email))
      register_account(email);
   // Customer customer;
   // Shopkeeper shopkeeper;
   // if(email.size())
   // {
   //    // cout<<"Welcome Customer";
   //    if(get_customer(email).name[0]=='\0')
   //    {
   //    cout<<"You need to register first";
   //    Customer c;cout<<"Enter Password:\n";
   //    cin>>c.password;cout<<"Enter your name:\n";
   //    cin>>c.name;cout<<"Enter your contact number:";
   //    cin>>c.contact_number;
   //    }
   // }
}