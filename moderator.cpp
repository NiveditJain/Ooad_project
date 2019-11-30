#ifndef moderator_cpp
#define moderator_cpp
// all includes
#include<bits/stdc++.h>
using namespace std;
#include "utilities.cpp"
#include "deliveryboy.cpp"
#include "customer.cpp"
#include "terminal.cpp"

// an abstract class with all its data members and functions static 
class Moderator
{
    public:
    
        static char  password[51];
        static char const email[51]; // not allowing it to be changed by anyone

    static bool login(string password)
    {   
        // password matching
        if(strcmp(password.c_str(),Moderator::password)==0)
            return true;
        return false;
    }

    static vector<string> get_customer_mails() 
    //retrieving customer emails to send holiday mail
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
    //retrieving shopkeeper emails to send holiday mail
    {
        vector<string> emails;
        fstream file2("database/shopkeeper_data/emails.txt", ios::in);
        string mail;
        while (file2>>mail)
            emails.push_back(mail);
        file2.close();
        return emails;
    }

    static void mail_holiday(string date,string occassion) //mail for holiday
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

    static void mail_vacation(string date1,string date2,string occassion) //mail for vacation
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
    static int assign_delivery_boy() //assigning delivery boy to deliver package
    {   
        srand(time(0));
       int r= rand() % (5); //generating random number from 0 to 4
       return r;
    }
    static void update_password() //change password
    {   string old_pass,new_pass1,new_pass_final,empty_string;
        cout<<"> Enter old password: "<<endl;
        char waste;
        scanf("%c",&waste);
        old_pass=Terminal::input_password();
        if(strcmp(old_pass.c_str(),Moderator::password)==0)
        {
            cout<<"> Enter new password:"<<endl;
            new_pass1=Terminal::get_password(); //checking validity of password
            if(new_pass1.empty())
            {
                cout<<"> Invalid password!"<<endl;
                Utilities::logging_out(10);
                exit(0);
            }
            cout<<"> Re-enter new password:"<<endl;
            new_pass_final=Terminal::get_password(); //checking validity of password
            if(strcmp(new_pass_final.c_str(),new_pass1.c_str())==0)
            {
                strcpy(Moderator::password,new_pass_final.c_str());
                ofstream file("database/.modu");
                file<<Moderator::password;
                file.close();
            }
            else
            {
                cout<<"> Passwords do not match!";
                Utilities::logging_out(10);
                exit(0);
            }

        }
        else
        {
            Utilities::logging_out(10);
            exit(0);
        }
        
        
    }

    static Customer get_customer(string email)
    {
        Customer temp;
        temp.name[0]='\0';
        email="database/customer_data/"+email+".ooad";
        fstream file(email.c_str());

        if(!file)
        {
            Utilities::my_exception error("> No such user found in database\n");
            throw error;
        }

        file.read((char *)&temp,sizeof(Customer));
        file.close();
        return temp;
    }    

    static void customer_write(Customer temp,string email)
    {
        string path="database/customer_data/"+email+".ooad";
        ofstream file(path.c_str());
        file.write((char*)&temp,sizeof(Customer));
        file.close();        
    }

    static void set_credit_0(string email,unsigned long long int amount_to_decrease)
    {
        Customer temp=get_customer(email);

        cout<<"> Credit Balance changed from "<<temp.credit_balance<<" to ";

        if(temp.credit_balance<amount_to_decrease)
            temp.credit_balance=0;
        else
            temp.credit_balance=temp.credit_balance-amount_to_decrease;
        
        cout<<temp.credit_balance<<"\n";

        customer_write(temp,email);
    }

    virtual void create_abstract()=0; //to make it an abstract class
};

char Moderator::password[51]="Moderator#cc2019@iitj";
char const Moderator::email[51]="moderator#cc";

#endif
