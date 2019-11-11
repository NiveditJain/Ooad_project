#include<bits/stdc++.h>
using namespace std;
#ifndef customer_cpp
#define customer_cpp
//#include "user.cpp"
typedef unsigned long long ulli;
class User
{
public:
    char email[51];
    char password[51];
    char name[20];
    ulli contact_number;
};

#include "item.cpp"
typedef unsigned long long ulli;
class Customer : public User
{
    public:
        // credit balance
        ulli credit_balance;

        // wallet balnce
        ulli wallet_balance;

        // number of items in cart
        ulli items_in_cart;

        // cart
        Item cart[20];

        // is cutomer a defaulter
        bool defaulter;
};

#endif