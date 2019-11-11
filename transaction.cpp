#ifndef transaction_cpp
#define transaction_cpp
#include "all_includes"


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
ulli transaction :: total_price(){ 
   ulli totalprice=0;
    for(ulli i=0;i<20;i++)
    {
        totalprice+=items[i].quantity*items[i].price;
    }
} 

#endif