#ifndef transaction_cpp
#define transaction_cpp
#include<bits/stdc++.h>
//#include "user.cpp"
#include "customer.cpp"
//#include "database.cpp"
#include "item.cpp"
// #include "moderator.cpp" 
#include "shop.cpp"
#include "shopkeeper.cpp" 
//#include "terminal.cpp"
//#include "utilities.cpp"
//#include "deliveryboy.cpp"
using namespace std;
// always use this in place of int or long long will be easy to handle
typedef unsigned long long int ulli;



class Transaction{
    public:
    ulli quantity;
    bool marked[100][1000];
    ulli selected;
    ulli listed[100][1000];
    ulli no_of_items;
    char Email[51];
    Shop shop;
    bool payment_details;//0->COD,1->credit
    char delivery_place[51];
    //Deliveryboy deliveryboy;
    //char delivery_place[51];
    Item items[20]; 
    ulli slot;
    ulli transaction_ID;
    time_t  date;
    bool payment_status;//1->done,0->pending
    ulli total_price;
    void update(ulli x,ulli y);
    void Initialise(string email);
};



void Transaction :: update(ulli x,ulli y)
{
   items[x-1].quantity+=y; 
}

void Transaction :: Initialise(string email)
{
    
    no_of_items=0;//Email=email;
    Utilities::convert(email,Transaction::Email);
    payment_details=0;payment_status=0;total_price=0;
    for(ulli i=0;i<20;i++)
    {items[i].quantity=0;}
     marked[100][1000]={0};
     selected=0;
     listed[100][1000]={0};quantity=0;
}
struct Shop_trans
{
char email[51];
ulli quantity;
char name[51];
} ;

   void update_shop_transaction_details(char *email,Transaction &t)
   {
       for(ulli i=0;i<20;i++)
       {
           Shop_trans obj;
           strcpy(obj.email,email);
           strcpy(obj.name,t.items[i].name);
           obj.quantity=t.items[i].quantity;           
           string Shop_category(t.items[i].shop_category);
           string path="database/transaction_data/"+Shop_category+".ooad";
           ofstream file(path.c_str(),std::ios::app);
           file.seekp(0L,ios::end);
           file.write((char *)&obj,sizeof(Shop_trans));
           file.close();
       }

   }      
         


#endif