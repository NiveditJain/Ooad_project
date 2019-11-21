#ifndef transaction_cpp
#define transaction_cpp
#include<bits/stdc++.h>
//#include "user.cpp"
#include "customer.cpp"
//#include "database.cpp"
#include "item.cpp"
#include "moderator.cpp" 
#include "shop.cpp"
#include "shopkeeper.cpp"
//#include "terminal.cpp"
//#include "utilities.cpp"
#include "deliveryboy.cpp"
using namespace std;
// always use this in place of int or long long will be easy to handle
typedef unsigned long long int ulli;
class Transaction{
    public:
    ulli no_of_items;
    char Email[51];
    Shop shop;
    bool payment_details;//0->COD,1->credit
    char delivery_place[51];
    Deliveryboy deliveryboy;
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


//calculating grand total
/*ulli Transaction :: total_price(){ 
   ulli totalprice=0;
    for(ulli i=0;i<20;i++)
    {
        totalprice+=items[i].quantity*items[i].price;
    }
    return totalprice;
} */

void Transaction :: update(ulli x,ulli y)
{
   items[x-1].quantity+=y; 
}

void Transaction :: Initialise(string email)
{
    
    no_of_items=0;//Email=email;
    convert(email,Transaction::Email);
    payment_details=0;payment_status=0;
    for(ulli i=0;i<20;i++)
    {items[i].quantity=0;}
}

#endif