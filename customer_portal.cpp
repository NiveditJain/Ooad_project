#include<bits/stdc++.h>
using namespace std;
#ifndef customer_portal_cpp
#define customer_portal_cpp
#include "customer.cpp"
#include "database.cpp"
#include "transaction.cpp"

int home_page_customer(Customer customer,Transaction &t);


void update_shop(Transaction &t)
{
    Item temp;

    for(ulli i=0;i<20;i++)
    {   
        if(t.items[i].quantity>0)
        {
        string Shop_category(t.items[i].shop_category);
       
         
       
         string path = "database/shop_items/" + Shop_category + ".ooad";
         fstream file(path.c_str());
         if(!file)cout<<"Not Found";
        
        while (file.read((char *)&temp, sizeof(Item)))
        {
        if (t.items[i].item_ID==temp.item_ID)
        {   
            temp.quantity-=t.items[i].quantity;
            long pos = file.tellp();
            file.seekp(pos - sizeof(Item));
            file.write((char *)&temp, sizeof(Item));
        }
       } file.close();
        }
    }
}


Transaction process(ulli option, Customer customer,Transaction &t)
{
    switch (option)
    {
     
    case 1:
    {
          Transaction t=customer.select_items(t);//retry='n'; 
          cout<<t.total_price<<" "<<t.quantity<<endl;
          return t;
    }
    case 2:
    {
       string email="";Transaction temp;
       ulli i=0;
       while(customer.email[i]!='\0')
       email+=customer.email[i],i++;
       string path="database/transaction_data/"+email+".ooad";
       ifstream file(path.c_str());
       while(file.read((char *)&temp,sizeof(Transaction)))
       {
           //Print the Transaction slip
           for(int i=0;i<20;i++)
         {if(temp.items[i].quantity>0)
             cout<<endl<<temp.items[i].name<<"\t"<<temp.items[i].quantity;
         }
       }
       file.close();
       return t;
    }
    case 3:
    {
        cout << "> Name : " << customer.name << endl;
        cout << "> Email : " << customer.email << endl;
        cout << "> contact number : " << customer.contact_number << endl;
        cout << "> Credit Balance : " << customer.credit_balance << endl;
        cout << "> Wallet Balance : " << customer.wallet_balance << endl;
        if(customer.defaulter)
        cout<<"\n> You are a defaulter and can't shop until you clear your debts";
        
        cout << endl;
        
        cout << "> select any of the following options :\n";
        cout << "> a) Edit profile\n";
        cout << "> b) go to home page\n";
        cout << "> c) logout\n";
        cout << ">";
        char option1;
        cin >> option1;
        switch (option1){
        case 'a':
        {
            customer.get_details(customer.email);
            register_customer(customer, customer.email);
            cout << "> profile updated successfully\n";
            return t;
        }
        case 'b':
        {
            system("clear");
            //home_page_customer(customer,t);
            return t;
        }
        case 'c':
        {
            cout<<"\n> Thanks for using our application\n";
            exit(0);
            return t;
        }
        }
        break;
    }
    case 4:
    {    cout<<"> Items\tQuantity\n";
         //cout<<t.total_price<<" "<<t.quantity<<endl;
         for(int i=0;i<20;i++)
         {if(t.items[i].quantity>0)
             //cout<<"not greater than zero";
             cout<<"> "<<t.items[i].name<<"\t"<<t.items[i].quantity<<"\t\t"<<endl;
         }
         cout<<"> Total Price-->"<<t.total_price<<endl;
         return t;
    } 

    case 5:
    {
           cout<<">Total Price-->"<<t.total_price<<"\n";
           //Do the checkout
           //cout<<"Only Cash on Delivery Available!!\n";
           //cout<<"Would you like to go back? (y/n)";bool goback;cin>>goback;
           //if(goback=='y')return t;
           cout<<"> Would you like to pay on COD or Pay Later (c/p)? ";
           char payment;
           cin>>payment;
           
            if(payment=='c')
                t.payment_status=1;
            else if(payment=='p')
            {
                t.payment_status=0;
                customer.credit_balance+=t.total_price;
            }
            else
                exit(0);
            

            // call mailer after MUSKAN


            update_shop(t);
            update_shop_transaction_details(customer.email,t);
           //Afer completion of Transaction(do not if the transaction is terminated)
           //cout<<t.total_price<<endl;
           string email="";
           if(t.total_price>0){
           ulli i=0;
           while(customer.email[i]!='\0')
           email+=customer.email[i],i++;
           string path="database/transaction_data/"+email+".ooad";
           ofstream file(path.c_str(),std::ios::app);
           file.seekp(0L,ios::end);
           file.write((char *)&t,sizeof(t));
           file.close();}
           t.Initialise(email);
           exit(1);
           return t;
    }
    case 6:
    {
         cout<<"\n> Thanks for using our application";
         exit(0);
         return t;
    }
    }
}

int home_page_customer(Customer customer,Transaction &t)
{
    cout<<"\n> Welcome "<<customer.name<<" !\n";int x=1;
    cout << "> Select any of the following options (Type the corresponding index to select a option):\n\n";
    do{
    cout << "> 1) Shop now or add more items to cart\n";
    cout << "> 2) View Transaction History\n";
    cout << "> 3) Profile\n";
    cout << "> 4) View Cart\n";
    cout << "> 5) Checkout\n";
    cout<<  "> 6) Logout\n";
    cout << "\n> ";
    ulli option; //contains the input option given by the user
    cin >> option;
    //system("clear");
    t=process(option,customer,t);
    }while(x==1);
    return -1;
}

int customer_portal(string email)
{
    Customer customer;
    cout<<"> Enter your password :: ";
    customer=get_customer(email);
    string password;char retry='n';string tryagain="NO";
    password=Terminal::get_password();
    while(!customer.login(password))
       {cout<<"\n> Invalid email password combination";
        cout<<"\n> Do you want to retry? ";
        cin>>tryagain;
        if((tryagain)=="y"||(tryagain)=="yes"||tryagain=="Y")
        {cout<<"\n> Re-enter your password::";
        password=Terminal::get_password();continue;}
        else break; 
       }
       if(tryagain=="n"||tryagain=="no"||tryagain=="N")
       {cout<<"\n> Thanks for using our services";return 0;} 
       Transaction t;t.Initialise(email);
       return home_page_customer(customer,t);
       
     
}
#endif     
