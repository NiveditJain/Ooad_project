#ifndef moderator_cpp
#define moderator_cpp

// all includes
#include<bits/stdc++.h>
using namespace std;
// this class contains inplimentation of shopkeeper
// all includes
#include<bits/stdc++.h>
using namespace std;
#include "utilities.cpp"

// a abstract classn with all its data members and functions static 
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

    static vector<string> get_customer_mails()
    {
        vector<string> emails;
        fstream file1("database/customer_data/emails.txt",ios::in);
        string mail;
        while(file1>>mail)
            emails.push_back(mail);
        file1.close();
        return emails;
    }
    
    static vector<string> get_shopkeeper_mails()
    {
        vector<string> emails;
        fstream file2("database/customer_data/emails.txt", ios::in);
        string mail;
        while (file2>>mail)
            emails.push_back(mail);
        file2.close();
        return emails;
    }

    static void mail_holiday(string date,string occassion)
    {
        vector<string> emails=get_customer_mails();
        for(auto str:emails)
        {
            string payload = "python3 holiday_mail.py " + str + " Customer "+date+" \""+occassion+"\"";
            system(payload.c_str());
        }
    }

    virtual void create_abstract()=0;
};

char const Moderator::password[51]="moderator@iitj#cc01";
char const Moderator::email[51]="moderator@iitj.ac.in";

#endif
