#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

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

    ifstream customer;
    customer.open("database/oath/customer.oath",ios::binary);

    if(!customer.is_open())
    {
        to_return.type=-2;
        last_find_email=to_return;
        return to_return;
    }
    
    auth_struct temp;

    while(customer.read((char *)&temp,sizeof(auth_struct)))
    {
        if(strcmp(temp.email,email)==0)
        {
            to_return.email_pass=temp;
            to_return.type=0;
            to_return.offset=present_offset;
            customer.close();
            last_find_email=to_return;
            return to_return;
        }
        present_offset++;
    }
     
    customer.close();

    present_offset=1;

    ifstream shopkeeper;
    shopkeeper.open("database/oath/customer.oath",ios::binary);

    if(!shopkeeper.is_open())
    {
        to_return.type=-2;
        last_find_email=to_return;
        return to_return;
    }

    while(shopkeeper.read((char *)&temp,sizeof(auth_struct)))
    {
        if(strcmp(temp.email,email)==0)
        {
            to_return.email_pass=temp;
            to_return.type=1;
            to_return.offset=present_offset;
            shopkeeper.close();
            last_find_email=to_return;
            return to_return;
        }
        present_offset++;
    }
}  

// verify email pass
