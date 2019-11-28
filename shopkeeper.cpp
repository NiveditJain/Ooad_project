#ifndef shopkeeper_cpp
#define shopkeeper_cpp
#include "shop.cpp" 
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ulli;
// #include "user.cpp"

class Shopkeeper: public User 
{
  public:
   
  char shop_name[51];
  char shop_category[51];
  ulli account_name;
  char IFSC_code[51];
  ulli holiday_list[366];
  ulli pending_amount;
  // ulli transactions_done;
  ulli shop_id;

  bool login(string password)
  {
    char string_password[51];
    copy(password.begin(),password.end(),string_password);
    string_password[password.size()]='\0';

    Utilities::encrypt(string_password);

    if(strcmp(string_password,Shopkeeper::password)==0)
      return true;

    return false;    
  }

  void set_password(string password)
  {
    copy(password.begin(),password.end(),Shopkeeper::password);
    Shopkeeper::password[password.size()]='\0';
    Utilities::encrypt(Shopkeeper::password);
  }

    Shopkeeper(ulli id=0)
    {
      pending_amount=0;
      // transactions_done=0;
      shop_id=id;
    }

    int get_details(string email)
    {
      Utilities::convert(email,Shopkeeper::email);

      cout<<"> Enter your name :: ";
      string name;
      char waste;
      scanf("%c",&waste);
      getline(cin,name);
      if(name.length()==0)
      {
        return -1;
      }
      Utilities::convert(name,Shopkeeper::name);

      cout<<"> Enter your phone number (without country code) :: ";
      string phone_number;
      getline(cin,phone_number);

      phone_number=Utilities::valid_phone_size(phone_number);
      phone_number=Utilities::all_digits(phone_number);

      if(phone_number.length()==0)
      {
        return -1;
      }

      Utilities::convert(phone_number,Shopkeeper::contact_number);
      cout<<"> Enter shop name :: ";
      string shp_nme;
      getline(cin,shp_nme);
      Utilities::convert(shp_nme,Shopkeeper::shop_name);
       
      cout<<"> Enter shop category :: ";
      string shop_category;
      getline(cin,shop_category);
      Utilities::convert(shop_category,Shopkeeper::shop_category);

      cout<<"> Enter the password for your account\n";
      cout<<"> It must contain at least 1 number, capital letter, small letter and a speacial character. Lenghth of password must also be >= 8\n";
      cout<<"> Password :: ";

      string password=Terminal::get_password(8);

      if(password.length()==0)
        return -1;
        
      set_password(password);

      cout<<"> Enter your Account Number (must be a number) :: ";
      cin>>account_name;

      string IFSC_code;

      cout<<"> Enter the IFSC code of your bank :: ";
      cin>>waste;
      getline(cin,IFSC_code);

      Utilities::convert(IFSC_code,Shopkeeper::IFSC_code);
      return 0;
    }


};

#endif