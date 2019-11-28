#ifndef moderator_cpp
#define moderator_cpp
//SOS forget password function,update password,retriever of mails
// all includes
#include<bits/stdc++.h>
using namespace std;
#include "utilities.cpp"
#include "deliveryboy.cpp"
#include "customer.cpp"

// an abstract class with all its data members and functions static 
class Moderator
{
    public:
    // not allowing them to be changed by anyone
        static char const password[51];
        static char const email[51];

    static bool login(string password)
    {   
        // password matching
        if(strcmp(password.c_str(),Moderator::password)==0)
            return true;
        return false;
    }

    static vector<string> get_customer_mails() //retrieving customer emails to send holiday mail
    {
        vector<string> emails;
        fstream file1("database/customer_data/emails.txt",ios::in);
        string mail;
        while(file1>>mail)
            emails.push_back(mail);
        file1.close();
        return emails;
    }
    
    static vector<string> get_shopkeeper_mails()//retrieving shopkeeper emails to send holiday mail
    {
        vector<string> emails;
        fstream file2("database/shopkeeper_data/emails.txt", ios::in);
        string mail;
        while (file2>>mail)
            emails.push_back(mail);
        file2.close();
        return emails;
    }

    static void mail_holiday(string date,string occassion)
    {   
        vector<string> cemails=get_customer_mails();
        vector<string> smails=get_shopkeeper_mails();
        for(auto str:cemails)
        {   
            string payload = "python3 holiday_mail.py " + str + " Customer "+date+" \""+occassion+"\"";
            system(payload.c_str());
        }
        for(auto str2:smails)
        {
            string payload = "python3 holiday_mail.py " + str2 + " Shopkeeper "+date+" \""+occassion+"\"";
            system(payload.c_str());
        }
    }

    static void mail_vacation(string date1,string date2,string occassion)
    {
        vector<string> cemails=get_customer_mails();
        vector<string> smails=get_shopkeeper_mails();
        for(auto str:cemails)
        {   
            string payload = "python3 vacation_mail.py " + str + " Customer "+date1+" "+date2+" \""+occassion+"\"";
            system(payload.c_str());
        }
        for(auto str2:smails)
        {   
            string payload = "python3 vacation_mail.py " + str2 + " Shopkeeper "+date1+" "+date2+" \""+occassion+"\"";
            system(payload.c_str());
        }
    }
    static int assign_delivery_boy()
    {   
        srand(time(0));
       int r= rand() % (5);
       return r;
    }

    virtual void create_abstract()=0;
};

char const Moderator::password[51]="moderator#cc2019@iitj";
char const Moderator::email[51]="moderator#cc";

#endif
