#ifndef shopkeeper_cpp
#define shopkeeper_cpp
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ulli;
//#include "user.cpp"

class User
{
public:
    char email[51];
    char password[51];
    char name[20];
    ulli contact_number;
};

class Shopkeeper: public User
{
  public:
  char shop_name[51];
  ulli account_name;
  char IFSC_code[21];
  ulli holiday_list[366];
  ulli pending_amount;
};
#endif