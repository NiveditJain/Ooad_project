#ifdef database_cpp
#define database_cpp
#include<iostream>
#include<fstream>
#include<string.h>
#include "utilities.cpp"
#include "classes.cpp"
#include "main.cpp"
using namespace std;

char moderator_pass[51]="moderator1@iitjcc";

struct auth_struct
{
    char email[51];
    char password[51];
};

// -2 for error
// type = -1 means not found
// type = 0 customer
// type = 1 shopkeeper
// type = 3 moderator
struct auth_info
{
    auth_struct email_pass;
    int type;
    int offset;
};

auth_info last_find_email;

// extract email ID and password from database and 
// if no such exist then returns null
auth_info get_email_pass(char email[])
{
    auth_info to_return;
    to_return.email_pass.email[0]='\0';
    to_return.email_pass.password[0]='\0';
    int present_offset=1;    

    ifstream infile;
    infile.open("database/oath/customer1.oath",ios::in|ios::binary);

    if(!infile.is_open())
    {
        to_return.type=-2;
        last_find_email=to_return;
        return to_return;
    }
    
    customer c;auth_struct temp;

    while(infile.read((char *)&c,sizeof(customer)))
    {
        if(strcmp(c.email,email)==0)
        {   strcpy(temp.email,c.email);
            strcpy(temp.password,c.password);
            to_return.email_pass=temp;
            to_return.type=0;
            to_return.offset=present_offset;
            infile.close();
            last_find_email=to_return;
            return to_return;
        }
        present_offset++;
    }
     
    infile.close();

    present_offset=1;

    ifstream infile;
    infile.open("database/oath/shopkeeper1.oath",ios::in,ios::binary);

    if(!infile.is_open())
    {
        to_return.type=-2;
        last_find_email=to_return;
        return to_return;
    }
    shopkeeper s;
    while(shopkeeper.read((char *)&s,sizeof(shopkeeper)))
    {
        if(strcmp(s.email,email)==0)
        {strcpy(temp.email,c.email);
            strcpy(temp.password,c.password);
            to_return.email_pass=temp;
            to_return.type=1;
            to_return.offset=present_offset;
            infile.close();
            last_find_email=to_return;
            return to_return;
        }
        present_offset++;
    }
}  

// verify email pass
// verify user ID and password
// returns 1 if correct
// matches with last search
// returns 0 in case of do not match
// returns -1 if error
int authenticate_user(string email,string password)
{
    char string_email[51];
    copy(email.begin(),email.end(),string_email);
    string_email[email.size()]='\0';

    if(last_find_email.type==-1)
        return -1;
    
    char string_pass[51];
    copy(password.begin(),password.end(),string_pass);
    string_pass[password.size()]='\0';

    encrypt(string_pass);

    if(!strcmp(string_email,last_find_email.email_pass.email)==0)
    {
        get_email_pass(string_email);
    }

    char moderator[51]="moderator";
    if(strcmp(moderator,string_email)==0)
    {
        if(strcmp(moderator_pass,string_pass)==0)
        {
            return 1;
        }
        else
            return 0;
    }

    if(strcmp(string_pass,last_find_email.email_pass.password)==0)
        return 1;
    else    
        return 0;
}


// returns the last type of user used in 
// get_email_function
// 0-> for customer
// 1-> shopkeer
// 2-> moderator
// -1-> error
int get_user_type()
{
    return last_find_email.type;
}

#endif
