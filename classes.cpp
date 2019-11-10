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
      int user_type;
      long long contact_number;
      long long credit_balance;
      long long wallet_balance;
      bool defaulter;
      Pair transaction_history[20];
    };    
