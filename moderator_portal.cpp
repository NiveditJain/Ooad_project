#include<bits/stdc++.h>
#include "terminal.cpp"
using namespace std;
#include "moderator.cpp"
#include "customer.cpp"
int moderator_auth()
{
    string password;
    password=input_password();
    if(password.length()==0)
        return -1;
    
    if(moderator.login(password)==false)
    {
        cout<<"\n > invalid email password combination";
        return -1;
    }
}

void change_password()
{
    string passwrd;
    cout<<"Enter new password:\n";
    passwrd=input_password();
    moderator.set_password(passwrd);
}

void assign_delivery_boy(Customer cs)
{

}

void holiday()
{
    string start_date,end_date;
    cout<<">Enter all dates in dd/mm/yyyy format"<<endl;
    cout<<"Start date:"<<endl;
    getline(cin,start_date);
    cout<<"End date:"<<endl;
    getline(cin,end_date);
    char sdate[start_date.length()],edate[end_date.length()];
    strcpy(sdate,start_date.c_str());
    strcpy(edate,end_date.c_str());
    if(strcmp(sdate,edate)==0)
    else
    {
        
    }
    


}