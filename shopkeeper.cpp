#ifndef shopkeeper_cpp
#define shopkeeper_cpp
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ulli;
// #include "user.cpp"

class Shopkeeper: public User
{
  public:
  char shop_name[51];
  ulli account_name;
  char IFSC_code[21];
  ulli holiday_list[366];
  ulli pending_amount;

  bool login(string email,string password)
  {
    char string_password[51];
    copy(password.begin(),password.end(),string_password);
    string_password[password.size()]='\0';

    encrypt(string_password);

    if(strcmp(string_password,Shopkeeper::password)==0)
      return true;

    return false;    
  }
};
#endif