#ifndef shop_cpp
#define shop_cpp
#include <bits/stdc++.h>
#include "customer.cpp"
#include "shopkeeper.cpp"
#include "item.cpp"
#include "transaction.cpp"
using namespace std;

//need to add a member working_days!!!

class shop  {
    protected:
    string type;
    string name;
    string timings;
    shopkeeper shp_kpr;
    vector<item> items;
    public:
    void search_item();
};

void shop :: search_item(){

}

#endif