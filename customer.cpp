#ifndef customer_cpp
#define customer_cpp
#include<bits/stdc++.h>
#include "item.cpp"
#include "user.cpp"
#include "shop.cpp"
using namespace std;
struct Pair
{
  long long category;
  long long count;  
};


struct cart{
  pair<item, int> item_quantity[10];
  int cost(){
    int price=0;
    for(auto it=item_quantity.begin();it!=item_quantity.end();it++)
      price+=(it->first->price) * (it->second);
    return price;
  }
};

class customer : public item,public user
{ 
  private:
    long long credit_balance;
    long long wallet_balance;
    bool defaulter;
    Pair transaction_history[20];
  public:
    cart c;
    customer();
    void edit_cart();
    void cancel_order();
    void check_credit_balance();
    void pay_credit_balance();
};

customer :: customer(){
  type=1;
}

void customer :: edit_cart(){

}

void customer :: cancel_order(){

}

void customer :: check_credit_balance(){

}

void customer :: pay_credit_balance(){

}



#endif