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
    Customer customer;
    Shop shop;
    bool payment_details;//0->COD,1->credit
    char delivery_place[51];
    Deliveryboy deliveryboy;
    char delivery_place[51];
    Item items[20]; 
    ulli slot;
    ulli transaction_ID;
    time_t  date;
    bool payment_status;//0->done,1->pending
    ulli total_price();
};


//calculating grand total
ulli Transaction :: total_price(){ 
   ulli totalprice=0;
    for(ulli i=0;i<20;i++)
    {
        totalprice+=items[i].quantity*items[i].price;
    }
} 

