#include<bits/stdc++.h>
using namespace std;
#ifndef customer_cpp
#define customer_cpp
#include "user.cpp"
#include "terminal.cpp"
//#include "database.cpp"
typedef unsigned long long ulli;
#include "item.cpp"
#include "transaction.cpp"
typedef unsigned long long ulli;


ulli number_of_shop() 
{
    fstream file1("database/shopkeeper_data/number_of_shops.num",ios::in);
    ulli number;
    file1>>number;
    file1.close();
    return number;    
}
Shop get_shop(ulli Shop_id)
{
    Shop temp;string id=Utilities::ulli_to_string(Shop_id);
    string shop_id="database/shop_data/"+id+".shop";
    fstream file(shop_id.c_str());

    if(!file)
    {
        return temp;
    }

    file.read((char *)&temp,sizeof(Shop));
    file.close();
    return temp;    
}
void display_shops()
{
    ulli number_of_shops=number_of_shop();
    ulli flag=0;
    for(ulli i=0;i<number_of_shops;i++)
    { 
        string id=Utilities::ulli_to_string(i);
        string path="database/shop_data/"+id+".num";
        fstream file(path.c_str());
        ulli num=0;
        file>>num;
        if(num)
        {
        flag++;
        }
    }
    if(flag==0)
    {
        cout<<"sorry! all shops are out of stock :(\n";
        exit(0);
    }
    else
    {
        cout<<"\nShop_ID"<<"\t"<<"Category\n";
        for(ulli i=0;i<number_of_shops;i++)
        { 
            string id=Utilities::ulli_to_string(i);
            Shop shop=get_shop(i);
            cout<<"> "<<i<<"\t"<<shop.category<<"\n";
        }
    }        
    }
void display_shop_details(char *shop_category)
{
   string Shop_category="";
   ulli i=0;
   while(shop_category[i]!='\0')
   Shop_category+=shop_category[i],i++;
   string shop_category_name="database/shop_items/"+Shop_category+".ooad";
   ifstream file(shop_category_name.c_str());
   Item item;
   cout<<"Item_ID"<<"\t\t"<<"Price"<<"\t\t"<<"Quantity Left"<<"\t\t"<<"Name"<<"\n";
   while(file.read((char *)&item,sizeof(Item)))
   {
       cout<<item.item_ID<<"\t\t"<<item.price<<"\t\t"<<item.quantity<<"\t\t\t"<<item.name<<"\n";
   }
   file.close();
}



Item get_item(char *shop_category,ulli item_ID)
{
   string Shop_category="";
   ulli i=0;
   while(shop_category[i]!='\0')
   Shop_category+=shop_category[i],i++;
   string shop_category_name="database/shop_items/"+Shop_category+".ooad";
   fstream file(shop_category_name.c_str());
   Item item;
   while(file.read((char *)&item,sizeof(Item)))
   {
       if(item.item_ID==item_ID)
       {
           return item;
       }
   }
   file.close();
}

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

        Utilities::encrypt(string_password);

        if(strcmp(string_password,Customer::password)==0)
            return true;

        return false;
    }

    void set_password(string password)
    {
        copy(password.begin(),password.end(),Customer::password);
        Customer::password[password.size()]='\0';
        Utilities::encrypt(Customer::password);
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
        Utilities::convert(email,Customer::email);

        cout<<"> Enter your name :: ";
        string name; 
        char waste;
        scanf("%c",&waste);
        getline(cin,name);
        if(name.length()==0)
        {
            cout<<"length of name shoul be greater than zero";
            exit(0);
        }
        Utilities::convert(name,Customer::name);

        cout<<"> Enter your phone number (without country code) :: ";
        string phone_number;
        getline(cin,phone_number);

        phone_number=Utilities::valid_phone_size(phone_number);
        phone_number=Utilities::all_digits(phone_number);

        if(phone_number.length()==0)
        {
            return -1;
        }

        Utilities::convert(phone_number,Customer::contact_number);

        cout<<"> Enter the password for your account\n";
        cout<<"> It must contain at least 1 number, capital letter, small letter and alphaber. Lenghth of password must also be >= 6\n";
        cout<<"> Password :: ";

        string password=Terminal::get_password();

        if(password.length()==0)
        {
            cout<<"> length of password should be greater than zero";
            exit(0);
        }
        
        set_password(password);
    }

    void add_cart(Transaction &t,ulli shop_ID)
    {
      Shop shop=get_shop(shop_ID);

      display_shop_details(shop.category);ulli number_of_items=0;char addmore;
      
      do
      {
      cout<<"\n> Select item_id:";
      unsigned long long item_id;
      cin>>item_id;
      Item item=get_item(shop.category,item_id);

      if(t.marked[shop_ID][item_id]||(t.selected<20)) 
      {
          y:
            cout<<"\n> Select the no of items to add to cart: ";
            cin>>number_of_items;
      
            if(number_of_items+(t.marked[shop_ID][item_id]?t.items[t.listed[shop_ID][item_id]].quantity:0)>item.quantity)
            {
                cout<<"> OOPS!! We don't have that much in the stock"<<endl;
                goto y;
            }
      
      }
      
      else 
      {
          cout<<"\n> Sorry! You can't add more than 20 distinct item_type to your cart ";
      }

      if(t.marked[shop_ID][item_id]==0&& number_of_items>0)
      {
          t.listed[shop_ID][item_id]=t.selected;

          t.selected++;
          
          t.marked[shop_ID][item_id]=1;
      }
      if(number_of_items>0)
      {
          t.items[t.listed[shop_ID][item_id]].quantity+=number_of_items;
          
          t.total_price+=(item.price*number_of_items),item.quantity-=number_of_items;
          
          t.items[t.listed[shop_ID][item_id]].item_ID=item_id;
          
          strcpy(t.items[t.listed[shop_ID][item_id]].name,item.name);
          
          t.items[t.listed[shop_ID][item_id]].price=item.price;
          
          strcpy(t.items[t.listed[shop_ID][item_id]].shop_category,item.shop_category);
      }

      t.quantity+=number_of_items;
      
      cout<<"\n> Do you want to add more items from this shop ? (y/n)";
      cin>>addmore;

      }while(addmore=='y');
    }

    Transaction select_items(Transaction &t)
    {
      char addcart;
     
    do{
        display_shops();

        cout<<"\n> Select the shop ID which you would like to explore: ";
        
        ulli shop_ID;
        
        cin>>shop_ID;
        
        add_cart(t,shop_ID);
        
        cout<<"\n> Do you want to continue shopping ? (y/n)";
        
        cin>>addcart;
       
       }while(addcart=='y');
       return t;
    }
};

#endif