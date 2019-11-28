#include<bits/stdc++.h>
#include "customer.cpp"
#include "terminal.cpp"
using namespace std;

#include "moderator.cpp"
#include "customer.cpp"
#include "utilities.cpp"
void holiday_vacation();
void MB();
int moderator_portal()
{
    string password;
    cout<<"> Enter Password for Moderator :: ";
    password=Terminal::input_password();
    if(password.length()==0)
        return -1;
    
    if(Moderator::login(password)==false)
    {
        cout<<"\n > invalid email password combination";
        return -1;
    }
    int choice;
    Utilities::loading(10);
    cout<<"\n> Login successful!"<<endl;
    cout<<"> Welcome Moderator!"<<endl;
    cout<<"> Choose your action:"<<endl;
    cout<<"> 1. Holiday/Vacation declaration"<<endl;
    cout<<"> 2.Update customer credit"<<endl;
    cout<<"> 3.Logout"<<endl;
    cout<<"> Enter your choice:"<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:holiday_vacation();
                break;
        // case 2: MB();
                break;
        case 3: Utilities::logging_out(10);
                exit(0);
        default: cout<<"> Enter valid choice!!";
                Utilities::logging_out(10);
                exit(0);
                
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