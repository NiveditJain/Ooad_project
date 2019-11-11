#ifndef transaction_cpp
#define transaction_cpp
#include <bits/stdc++.h>
#include "customer.cpp"
#include "moderator.cpp"
#include "shop.cpp"
#include "item.cpp"
using namespace std;

class transaction{
    private:
    long long transaction_ID;
    customer cust;
    shop shp;
    int payment_details;
    bool payment_status;
    string delivery_place;
    string delivery_boy;
    public:
    transaction();
    void checkout();
    void get_details();
    void is_possible();
};

transaction :: transaction(){
    payment_details=cust.c.cost();
}

void transaction :: checkout(){

}

void transaction :: get_details(){

}

void transaction :: is_possible(){

}

#endif