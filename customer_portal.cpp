#include<bits/stdc++.h>
using namespace std;
#ifndef customer_portal_cpp
#define customer_portal_cpp
#include "customer.cpp"
#include "database.cpp"
#include "transaction.cpp"

int home_page_customer(Customer customer,Transaction &t);

Deliveryboy deliveryboys[5];
void premain()
{
   deliveryboys[0].name="Ram";
   deliveryboys[0].contact_number=9867856435;
   deliveryboys[1].name="Mohan";
   deliveryboys[1].contact_number=9672136435;
   deliveryboys[2].name="Prabhu";
   deliveryboys[2].contact_number=6867858985;
   deliveryboys[3].name="Kashiram";
   deliveryboys[3].contact_number=8867856421;
   deliveryboys[4].name="Tagore";
   deliveryboys[4].contact_number=6866656435;
}

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
             cout<<temp.items[i].name<<"\t"<<temp.items[i].quantity<<endl;
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
        cout << "> a) go to home page\n";
        cout << "> b) logout\n";
        cout << ">";
        char option1;
        cin >> option1;
        switch (option1){
        case 'a':
        {
            system("clear");
            //home_page_customer(customer,t);
            return t;
        }
        case 'b':
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
           cout<<"> Total Price--> "<<t.total_price<<"\n";
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

            cout<<"> Delivery Slots:"<<endl;
            cout<<"> 1) 11:00 to 12:00"<<endl;
            cout<<"> 2) 13:00 to 15:00"<<endl;
            cout<<"> 3) 15:30 to 17:00"<<endl;
            cout<<"> 4) 17:30 to 19:00"<<endl;
            cout<<"> 5) 19:30 to 20:30"<<endl;

            int option_selected,option_selected2;
             cout<<"> Please input the delivery slot suitable for you\n";
             cin>>option_selected;

            cout<<endl;
            cout<<"> Delivery Locations:"<<endl;
            cout<<"> 1)Common garden,Faculty Quarters\n";
            cout<<"> 2)Admin/Library Block\n";
            cout<<"> 3)LHC\n";
            cout<<"> 4)Dining Hall Building\n";
            cout<<"> 5)Common area between Green and Blue Student Hostels\n";
            cout<<"> Please input the delivery location suitable for you\n";
            cin>>option_selected2;
            
            int deiver_boy_number=Moderator::assign_delivery_boy();
            string temp_name(customer.name);
            string temp_email(customer.email);
            string temp_deliveryboy_name(deliveryboys[deiver_boy_number].name);
            string temp_number(Utilities::ulli_to_string(deliveryboys[deiver_boy_number].contact_number));
            string temp_amount(Utilities::ulli_to_string(t.total_price));
            // working here
            string pay_load="python3 mail_trans.py "+temp_email+" \""+temp_name+"\" "+temp_amount+" "+temp_deliveryboy_name+" "+temp_number;
            if(payment=='c')
                pay_load=pay_load+" Cash on Delivery";
            else
                pay_load=pay_load+" Credit";

            system(pay_load.c_str());

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

            string path="database/customer_data/"+email+".ooad";
            ofstream file(path.c_str());
            file.write((char*)&customer,sizeof(Customer));
            file.close();             

           cout<<"> Transaction Done Success"; 
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
    string password;
    password=Terminal::input_password();
    if(!customer.login(password))
    {
        cout<<"\n> Invalid email password combinationn\n";
        cout<<"> Do you want to login with OTP? (y/n)";
        char ch;
        cin>>ch;

        if(ch!='y')
            return -1;

        if(ch=='y')
        {
            cout<<"> Sending OTP on your mail and mobile\n";
            string temp_name(customer.name);
            string temp_number(customer.contact_number);
            string otp=Network::OTP_password(temp_name,temp_number,email);

            if(otp.length()==0)
                return -1;

            string entered_otp;
            cout<<"> Enter the OTP :: ";

            char waste;
            scanf("%c",&waste);

            getline(cin,entered_otp);

            if(strcmp(entered_otp.c_str(),otp.c_str())!=0)
            {
                cout<<"> Invalid OTP";
                return -1;
            }

        }
        return -1; 
    }
    
    Transaction t;
    t.Initialise(email);
    return home_page_customer(customer,t);  
}
#endif     
