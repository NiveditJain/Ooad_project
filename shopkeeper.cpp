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
  ulli transactions_done;

  bool login(string password)
  {
    char string_password[51];
    copy(password.begin(),password.end(),string_password);
    string_password[password.size()]='\0';

    encrypt(string_password);

    if(strcmp(string_password,Shopkeeper::password)==0)
      return true;

    return false;    
  }

  void set_password(string password)
  {
    copy(password.begin(),password.end(),Shopkeeper::password);
    Shopkeeper::password[password.size()]='\0';
  }

    Shopkeeper()
    {
      transactions_done=0;
    }

    int get_details(string email)
    {
        convert(email,Shopkeeper::email);

        cout<<"> Enter your name :: ";
        string name;
        getline(cin,name);
        if(name.length()==0)
        {
            return -1;
        }
        convert(name,Shopkeeper::name);

        cout<<"> Enter your phone number(withput country code) :: ";
        string phone_number;
        getline(cin,phone_number);

        if(valid_phone(phone_number)==0)
        {
            cout<<"> Invalid Phone Number\n";
            return -1;
        }

        int number= (ulli)stoi(phone_number);
        // Shopkeeper::contact_number=number;


    }
};
#endif