#include<bits/stdc++.h>
#include "customer.cpp"
#include "database.cpp"
#include "moderator.cpp"
#include "shop.cpp"
#include "shopkeeper.cpp" 
#include "network.cpp"
#include "terminal.cpp" 
#include "utilities.cpp"
// #include "deliveryboy.cpp" 
#include "customer_portal.cpp"
#include "shopkeeper_portal.cpp"
#include "moderator_portal.cpp"
#include "item.cpp"
using namespace std;
typedef unsigned long long int ulli;
int main() 
{ 
   premain();
   Utilities::loading(50);
   system("clear");
   string email=Terminal::initial_display();
   if(email.size()==0)
      return -1;
   if(is_customer(email))
      return customer_portal(email);
   if(is_shopkeeper(email))
      return shopkeeper_portal(email);
   if(is_moderator(email))
     return moderator_portal();
   return register_user(email);
}