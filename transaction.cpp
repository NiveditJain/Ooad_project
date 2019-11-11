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
    public:
    void checkout();
};

void transaction :: checkout(){

}

#endif