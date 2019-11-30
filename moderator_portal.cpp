#include<bits/stdc++.h>
#include "customer.cpp"
#include "terminal.cpp"
using namespace std;

#include "moderator.cpp"
#include "customer.cpp"
#include "utilities.cpp"
void holiday_vacation();
int moderator_portal()
{
    string password;
    cout<<"> Enter Password for Moderator :: ";
    password=Terminal::input_password();
    if(password.length()==0)
        return -1;
    
    char password_file[51];
    ifstream file("database/.modu");
    file>>password_file;

    strcpy(Moderator::password,password_file);
    file.close();

    if(Moderator::login(password)==false)
    {
        cout<<"\n > Invalid email password combination";
        return -1;
    }
    int choice;
    Utilities::loading(10);
    cout<<"\n> Login successful!"<<endl;
    cout<<"> Welcome Moderator!"<<endl;
    cout<<"> Choose your action:"<<endl;
    cout<<"> 1. Holiday/Vacation declaration"<<endl;
    cout<<"> 2. Decrease Credit Balance of a customer"<<endl;
    cout<<"> 3. Change password"<<endl;
    cout<<"> 4. Logout"<<endl;
    cout<<"> Enter your choice :: ";
    cin>>choice;
    switch(choice)
    {
        case 1:holiday_vacation();
                break;
        case 2: 
        {
            cout<<"> Enter the email of customer :: ";

            char waste;
            scanf("%c",&waste);

            string email=Utilities::get_email();

            unsigned long long int amount_to_decrease;
            cout<<"> Enter amount to decrease :: ";
            cin>>amount_to_decrease;

            if(email.length()==0)
            {
                cout<<"> Invalid email\n";
                exit(0);
            }

            try
            {
                Moderator::set_credit_0(email,amount_to_decrease);
            }
            catch(Utilities::my_exception error)
            {
                cout<<error.what();
            }
            
        }
                break;
        case 3: Moderator::update_password();
            break;
        case 4: Utilities::logging_out(10);
                exit(0);
        default: cout<<"> Invalid choice entered!";
                Utilities::logging_out(10);
                exit(0);  
    }
    
}


void holiday_vacation()
{
    string start_date,end_date,occassion;
    char waste;
    cout<<"> Enter all dates in dd/mm/yyyy format"<<endl;
    cout<<"> Start date:"<<endl;
    scanf("%c",&waste);
    getline(cin,start_date);
    cout<<"> End date:"<<endl;
    getline(cin,end_date);
    cout<<"> Enter the occassion:"<<endl;
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