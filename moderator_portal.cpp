#include<bits/stdc++.h>
#include "terminal.cpp"
using namespace std;

#include "moderator.cpp"
#include "customer.cpp"
int moderator_auth()
{
    string password;
    password=Terminal::input_password();
    if(password.length()==0)
        return -1;
    
    if(Moderator::login(password)==false)
    {
        cout<<"\n > invalid email password combination";
        return -1;
    }
}


void holiday_vacation()
{
    string start_date,end_date,occassion;
    cout<<">Enter all dates in dd/mm/yyyy format"<<endl;
    cout<<"Start date:"<<endl;
    getline(cin,start_date);
    cout<<"End date:"<<endl;
    getline(cin,end_date);
    cout<<"Enter the occassion:"<<endl;
    getline(cin,occassion);
    char sdate[start_date.length()],edate[end_date.length()],occ[occassion.length()];
    strcpy(sdate,start_date.c_str());
    strcpy(edate,end_date.c_str());
    strcpy(occ,occassion.c_str());
    if(strcmp(sdate,edate)==0)
    {
        Moderator::mail_holiday(sdate,occ);
    }
    else
    {
        Moderator::mail_vacation(sdate,edate,occ);
    }
}

int main()
{
    holiday_vacation();
}