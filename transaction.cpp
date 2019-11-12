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
    char customer_email[51];
    char shopkeeper_email[51];
    bool payment_details;//0->COD,1->credit
    char delivery_place[51];
    Deliveryboy deliveryboy;
    ulli delivery_place;
    Item item; 
    ulli slot;
    ulli transaction_ID;
    time_t  date;
    bool payment_status;//0->done,1->pending
    ulli total_price();
};


//calculating grand total
ulli Transaction :: total_price(){ 
    return item.price*item.quantity;
} 

