#ifndef utilities_cpp
#define utilities_cpp
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ulli;

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

string valid_phone_size(string phone_number)
{
    string empty;
    if(phone_number.size()!=10)
    {
        cout<<"> Phone number be exactly of 10 digits\n";
        return empty;
    }    
    return phone_number;
}

string all_digits(string phone_number)
{
    string empty;
    for(char ch: phone_number)
    {
        if(!(ch>='0' && ch<='9'))
        {
            cout<<"> It must only be a digit";
            return empty;
        }
    }
    return phone_number;
}

string ulli_to_string(ulli number)
{
    ulli factor=10;
    while(number/factor>0)
    {
        factor=factor*(ulli)10;
    }
    factor=factor/(ulli)10;

    string answer;

    while(factor>0)
    {
        answer.push_back(number/factor+'0');
        number=number%factor;
        factor=factor/10;        
    }

    return answer;
}

#endif