#ifndef database_cpp
#define database_cpp
#include<bits/stdc++.h>
using namespace std;
#include "customer.cpp"
#include "shopkeeper.cpp"
#include "moderator.cpp"
#include "network.cpp"
ulli number_of_shops;

Customer get_customer(string email)
{
    Customer temp;
    temp.name[0]='\0';
    email="database/customer_data/"+email+".ooad";
    fstream file(email.c_str());

    if(!file)
    {
        cout<<"stuck here";
        return temp;
    }

    file.read((char *)&temp,sizeof(Customer));
    file.close();
    return temp;
}

Shopkeeper get_shopkeeper(string email)
{
    Shopkeeper temp;
    temp.name[0]='\0';
    email="database/shopkeeper_data/"+email+".ooad";
    fstream file(email.c_str());

    if(!file)
    {
        return temp;
    }

    file.read((char *)&temp,sizeof(Shopkeeper));
    file.close();
    return temp;    
}

void register_customer(Customer temp,string email)
{    
    string path="database/customer_data/"+email+".ooad";
    ofstream file(path.c_str());
    file.write((char*)&temp,sizeof(Customer));
    file.close();

    fstream emails("database/customer_data/emails.txt",ios::app);
    emails<<email<<"\n";
    emails.close();
}

void register_shopkeeper(Shopkeeper temp,string email)
{    
    string path="database/shopkeeper_data/"+email+".ooad";
    ofstream file(path.c_str());
    file.write((char*)&temp,sizeof(Shopkeeper));
    file.close();

    fstream emails("database/shopkeeper_data/emails.txt",ios::app);
    emails<<email<<"\n";
    emails.close();
}

bool is_customer(string email)
{
    string path = "database/customer_data/"+email+".ooad";
    
    fstream file1(path.c_str());

    if(file1)
    {
        file1.close();
        return true;
    }

    return false;    
}

bool is_shopkeeper(string email)
{
    string path="database/shopkeeper_data/"+email+".ooad";

    fstream file2(path.c_str());

    if(file2)
    {
        file2.close();
        return true;
    } 

    return false; 
}

bool is_moderator(string email)
{
    if(strcmp(Moderator::email,email.c_str())==0)
        return true;
    
    return false;
}

void increase_shop()
{
    fstream file1("database/shopkeeper_data/number_of_shops.num",ios::in);
    ulli number;
    file1>>number;
    number++;
    file1.close();
    fstream file2("database/shopkeeper_data/number_of_shops.num",ios::out);
    file2<<number;
    file2.close();
}

ulli get_number_of_shops()
{
    fstream file1("database/shopkeeper_data/number_of_shops.num",ios::in);
    ulli number;
    file1>>number;
    file1.close();
    return number;    
}

int register_shop(Shop shop)
{
    string id=Utilities::ulli_to_string(shop.ID);
    string path="database/shop_data/"+id+".shop";
    ofstream file(path.c_str());
    file.write((char*)&shop,sizeof(Shop));
    file.close();
    string path2="database/shop_data/"+id+".num";
    ofstream file2(path2.c_str());
    file2<<0;
    file2.close();
}

int register_user(string email)
{
    cout<<"> Entered email not found in our database. Do you want to register (y/n)? ";
    char answer;
    cin>>answer;
    if(answer=='n')
        return -1;
    if(answer!='y')
        cout<<"> No a valid choice terminating\n";
    cout<<"> To register as Customer press (c) and to register as shopkeeper press (s)  ";
    cin>>answer;
    cout<<"> Terms and Conditions \n";
    Utilities::loading(40);
    switch(answer)
    {
        case 'c':
        {
            Customer customer;
            fstream file("database/customer_data/tandc.txt");
            string temp;
            cout<<"> Terms and Conditions are as following\n";
            char ch;
            // printing tandc
            while(file.get(ch))
                cout<<ch;
            file.close();
            cout<<"\n> I, as a Customer of CC Basket, I hereby declare that I have gone through above terms and conditions and accept them, I also pledge to follow them. I also understand that non-fullfillment of any such issue can lead to legal action.(Yes->y/No->n)  ";

            cin>>ch;
            if(ch=='n')
                return -1;
            if(ch!='y')
            {
                cout<<"> Invalid input\n";
                return -1;
            }
            if(customer.get_details(email)==-1)
                return -1;


            // verification process before entering into database
            string temp_name(customer.name);
            string temp_email(customer.email);
            string temp_phone(customer.contact_number);

            cout<<"> Starting email verification process\n";
            // verifing email
            string OTP=Network::mail_otp(temp_name,temp_email);

            if(OTP.length()==0)
                return -1;
            cout<<"> Enter OTP recieved on your email :: ";                
            char temp_otp[11];
            
            cin>>temp_otp;

            if(strcmp(temp_otp,OTP.c_str())!=0)
            {
                cout<<"> Worng OTP entered aborting process\n";
                return -1;
            }
            else
            {
                cout<<"> OTP accepeted\n";
            }


            cout<<"> Starting mobile verification\n";
            
            // sending OTP
            OTP=Network::sms_otp(temp_name,temp_phone);

            if(OTP.length()==0)
                return -1;
            
            cout<<"> Enter OTP recieved on your phone number :: ";                
            temp_otp[11];
            
            cin>>temp_otp;

            if(strcmp(temp_otp,OTP.c_str())!=0)
            {
                cout<<"> Worng OTP entered aborting process\n";
                return -1;
            }
            else
            {
                cout<<"> OTP accepeted\n";
            }            

            register_customer(customer,email);
            cout<<"> Customer Registration Completed \n";
            return 1;
        }
        break;
        case 's':
        {
            Shopkeeper shopkeeper(get_number_of_shops());
            fstream file("database/shopkeeper_data/tandc.txt");
            string temp;
            cout<<"> Terms and Conditions are as following\n";
            char ch;
            while(file.get(ch))
                cout<<ch;
            file.close();
            cout<<"\n> I, as a Shopkeeper of a shop under fbay network, I hereby declare that I have gone through above terms and conditions and accept them, I also pledge to follow them. I also understand that non-fullfillment of any such issue can lead to legal action.(Yes->y/No->n)  ";
            
            cin>>ch;
            if(ch=='n') 
                return -1;

            if(shopkeeper.get_details(email)==-1)
                return -1;

            // verification process before entering into database
            string temp_name(shopkeeper.name);
            string temp_email(shopkeeper.email);
            string temp_phone(shopkeeper.contact_number);


            cout<<"> Starting email verification process\n";
            // verifing email
            string OTP=Network::mail_otp(temp_name,temp_email);

            if(OTP.length()==0)
                return -1;
            cout<<"> Enter OTP recieved on your email :: ";                
            char temp_otp[11];
            
            cin>>temp_otp;

            if(strcmp(temp_otp,OTP.c_str())!=0)
            {
                cout<<"> Worng OTP entered aborting process\n";
                return -1;
            }
            else
            {
                cout<<"> OTP accepeted\n";
            }

            cout<<"> Starting mobile verification\n";
            
            // sending OTP
            OTP=Network::sms_otp(temp_name,temp_phone);

            if(OTP.length()==0)
                return -1;
            
            cout<<"> Enter OTP recieved on your phone number :: ";                
            temp_otp[11];
            
            cin>>temp_otp;

            if(strcmp(temp_otp,OTP.c_str())!=0)
            {
                cout<<"> Worng OTP entered aborting process\n";
                return -1;
            }
            else
            {
                cout<<"> OTP accepeted\n";
            }
          
            Shop shop(get_number_of_shops());
            if(shop.get_details(shopkeeper.email,shopkeeper.name,shopkeeper.shop_category)==-1)
                return -1;  
            
            register_shopkeeper(shopkeeper,email);
            register_shop(shop);
            increase_shop();
            
            cout<<"> Shopkeeper Registration Completed \n";
            cout<<"> You need to login to proceed!\n";
            return 2;
        }
        break;
        default:
        {
            cout<<"> Not a valid input\n";
            return 3;
        }
        break;
    }
}
#endif