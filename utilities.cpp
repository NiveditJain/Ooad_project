#ifndef utilities_cpp
#define utilities_cpp
#include<bits/stdc++.h>
using namespace std;
bool check_email_iitj(char input[]){
    char *ptr;
        ptr= strstr(input,"@iitj.ac.in"); //searches input array for "@iitj.ac.in" string
        if(ptr) 
        {
            return true;
        }
    return false;
}

bool verify_email(char input[]){
    string empty_email;
    if(check_email_iitj(input)==false)
    {
        cout<<"> this email does not belong to iitj!\n";
        return false;
    }
    return true;
}

string get_email()
{
    string email;
    getline(cin,email);

    int x = 100;          //51+@iitj.ac.in
    char input[x];       //array to hold input
    copy(email.begin(),email.end(),input);
    input[email.length()]='\0';

    string first_part;
    int second_part_length=0;

    int count_at=0,count_dot=0;
    for(char temp: email)
    {
        if(temp=='@')    
            count_at++;
        if(count_at==0)
            first_part.push_back(temp);
        if(count_at!=0)
        {
            second_part_length++;
            count_dot++;
        }
    }

    string empty;

    if(second_part_length>29 || count_dot==0||count_at!=1)
    {
        cout<<"> not a valid email\n";
        return empty;
    }

    if(!count_at==1)
    {
        cout<<"> not a vaild email\n";
        return empty;
    }

    if(verify_email(input)==false)
    {
        return empty;
    }

    return first_part;
}

char encrypt(char str[])
{
    for(int i=0;str[i]!='\0';i++)
        str[i]=str[i]-27;
}

void convert(string str,char data[])
{
    copy(str.begin(),str.end(),data);
    data[str.size()]='\0';
}

int valid_phone(string phone_number)
{
    if(phone_number.size()!=10)
        return false;
    return true;
}

#endif