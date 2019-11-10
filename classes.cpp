#include<bits/stdc++.h>
using namespace std;

struct Pair
{
  long long category;
  long long count;  
};

struct customer
{ 
      char email[51];
      char password[51];
      char name[20];
      const int type=0;
      long long contact_number;
      long long credit_balance;
      long long wallet_balance;
      bool defaulter;
      Pair transaction_history[20];
};  

struct shopkeeper
{
   char email[51];
   char password[51];
   char name[20];
   const int type=1;
   char shop_name[30];
   long long account_number;
   long long pending_amount;
   Pair transaction_history[20];
   long long holiday[366];  
};


