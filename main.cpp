#include<bits/stdc++.h>
#include "customer.cpp"
#include "database.cpp"
#include "moderator.cpp"
#include "shop.cpp"
#include "shopkeeper.cpp" 
#include "network.cpp"
#include "terminal.cpp" 
#include "utilities.cpp"
#include "deliveryboy.cpp" 
#include "customer_portal.cpp"
#include "shopkeeper_portal.cpp"
//#include "moderator_portal.cpp"
#include "item.cpp"
using namespace std;
typedef unsigned long long int ulli;
void premain()
{
   Deliveryboy d[5];
   d[0].name="Ram";
   d[0].contact_number=9867856435;
   d[1].name="Mohan";
   d[1].contact_number=9672136435;
   d[2].name="Prabhu";
   d[2].contact_number=6867858985;
   d[3].name="Kashiram";
   d[3].contact_number=8867856421;
   d[4].name="Tagore";
   d[4].contact_number=6866656435;

}
int main() 
{ 
   Utilities::loading(50);
   system("clear");
   string email=Terminal::initial_display();
   if(email.size()==0)
      return -1;
   if(is_customer(email))
      return customer_portal(email);
   if(is_shopkeeper(email))
      return shopkeeper_portal(email);
   //if(is_moderator(email))
     // return moderator_portal(email);
   return register_user(email);
}