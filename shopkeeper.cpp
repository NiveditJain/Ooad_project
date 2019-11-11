#ifndef shopkeeper_cpp
#define shopkeeper_cpp
#include <bits/stdc++.h>
#include "user.cpp"
#include "moderator.cpp"
using namespace std;

struct Pair
{
    long long category;
    long long count;
};
class shopkeeper : public user
{
    private:
        char shop_name[30];
        long long account_number;
        long long pending_amount;
        Pair transaction_history[20];
        long long holiday[366];
    public:
        shopkeeper();
        void add_items();
        void update_record();
        void add_holiday();
};

shopkeeper :: shopkeeper(){
    type=1;
}

void shopkeeper :: add_items(){

} 

void shopkeeper :: update_record(){

}

void shopkeeper :: add_holiday(){

}

#endif