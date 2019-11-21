#include<bits/stdc++.h>
using namespace std;
#ifndef customer_cpp
#define customer_cpp
#include "user.cpp"
#include "terminal.cpp"
typedef unsigned long long ulli;
#include "item.cpp"
#include "transaction.cpp"
typedef unsigned long long ulli;
bool marked[100][1000]={0};
bool selected=0;
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

        ulli transactions_done;

    bool login(string password)
    {    
        char string_password[51];
        copy(password.begin(),password.end(),string_password);
        string_password[password.size()]='\0';

        encrypt(string_password);

        if(strcmp(string_password,Customer::password)==0)
            return true;

        return false;
    }

    void set_password(string password)
    {
        copy(password.begin(),password.end(),Customer::password);
        Customer::password[password.size()]='\0';
        encrypt(Customer::password);
    }

    Customer()
    {
        credit_balance=0;
        wallet_balance=0;
        items_in_cart=0;
        defaulter=false;
        transactions_done=0;
    }

    int get_details(string email)
    {
        convert(email,Customer::email);

        cout<<"> Enter your name :: ";
        string name; 
        char waste;
        scanf("%c",&waste);
        getline(cin,name);
        if(name.length()==0)
        {
            cout<<"got here";
            return -1;
        }
        convert(name,Customer::name);

        cout<<"> Enter your phone number (without country code) :: ";
        string phone_number;
        getline(cin,phone_number);

        phone_number=valid_phone_size(phone_number);
        phone_number=all_digits(phone_number);

        if(phone_number.length()==0)
        {
            return -1;
        }

        convert(phone_number,Customer::contact_number);

        cout<<"> Enter the password for your account\n";
        cout<<"> It must contain at least 1 number, capital letter, small letter and alphaber. Lenghth of password must also be >= 6\n";
        cout<<"> Password :: ";

        string password=get_password();

        if(password.length()==0)
            return -1;
        
        set_password(password);
    }
    void add_cart(Transaction &t,ulli shop_ID)
    {
      Shop shop=get_shop(shop_ID);
      display_shop_details(shop.category);ulli number_of_items=0;char addmore;
      do{
      cout<<"/n >Select item_id:";ulli item_id;cin>>item_id;Item item=get_item(shop.category,item_ID);
      if(marked[shop_ID][item_id]||(selected<20))
      {
      cout<<"/n >Select the no of items to add to cart: ";
      cin>>number_of_items;
      }
      if(marked[shop_ID][item_id]==0&& number_of_items>0)
      {selected++;marked[shop_ID][item_id]=1;}
      t.items[selected].quantity+=number_of_items;t.total_price+=(item.price*number_of_items);
      cout<<"/n >Do you want to add more items from this shop ? (y/n)";
      cin>>addmore;
      }while(addmore=='y');
    }

    Transaction select_items()
    {
      char addcart;
      Transaction t;  t.Initialise(email);
    do{
        display_shops();
        cout<<"\n >Select the shop ID which you would like to explore: ";ulli shop_ID;
        cin>>shop_ID;
        add_cart(t,shop_ID);
        cout<<"\n>Do you want to continue shopping ? (y/n)";cin>>addcart;
       }while(addcart=='y');
       return t;
    }
};

#endif