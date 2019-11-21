#include<bits/stdc++.h>
using namespace std;
#include "customer.cpp"
#include "database.cpp"
#include "transaction.cpp"
int customer_portal(string email)
{
    Customer customer;
    cout<<"> Enter your password :: ";
    customer=get_customer(email);
    string password=get_password();char retry='n';
    
    if(!customer.login(password))
       {  cout<<"\n > invalid email password combination";
       // cout<<"\n >Do you want to retry? (y/n)";
        
       }
       else 
       {
           Transaction t=customer.select_items();retry='n';
           cout<<t.total_price<<endl;
           if(t.total_price>0){
           string path="database/transaction_data/"+email+".ooad";
           fstream file(path.c_str(),ios::app);
           file.write((char *)&t,sizeof(t));
           file.close();}
       }   
     
}
        
