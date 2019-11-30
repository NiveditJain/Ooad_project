#ifndef network_cpp
#define network_cpp
#include<bits/stdc++.h>
#include "customer.cpp"
#include "utilities.cpp"
using namespace std;

namespace Network
{
string sms_otp(string name,string number)
{
    string processed_name;
    for(int i=0;i<name.size() && name[i]!=' ';i++)
        processed_name.push_back(name[i]);
    string otp=Utilities::generate_otp();
    string command="python3 sms_otp.py "+number+" "+otp+" "+processed_name;
    cout<<"> Sending OTP.............\n";
    system(command.c_str());
    fstream file(".junk");
    int status;
    file>>status;
    if(status==-1)
    {
        cout<<"> OTP Sending Faliure. Please Check Your Network And Try Later.\n";
        string empty;
        return empty;
    }
    cout<<"> OTP Sent Success\n";
    return otp;
}

string mail_otp(string name,string email)
{
    string processed_name;
    for(int i=0;i<name.size() && name[i]!=' ';i++)
        processed_name.push_back(name[i]);
    string otp=Utilities::generate_otp();
    string command="python3 mail_otp.py "+email+" "+otp+" "+processed_name;
    cout<<"> Sending OTP.............\n";
    system(command.c_str());
    fstream file(".junk");
    int status;
    file>>status;
    if(status==-1)
    {
        cout<<"> OTP Sending Faliure. Please Check Your Network And Try Later.\n";
        string empty;
        return empty;
    }
    cout<<"> OTP Sent Success\n";
    return otp;
}

string OTP_password(string name,string number,string email)
{
    string processed_name;
    for(int i=0;i<name.size() && name[i]!=' ';i++)
        processed_name.push_back(name[i]);
    string otp=Utilities::generate_otp();
    {
        string command="python3 sms_otp.py "+number+" "+otp+" "+processed_name;
        system(command.c_str());
        fstream file(".junk");
        int status;
        file>>status;
        if(status==-1)
        {
            cout<<"> OTP Sending Faliure. Please Check Your Network And Try Later.\n";
            string empty;
            return empty;
        }        
    }
    {
        string command="python3 mail_otp.py "+email+" "+otp+" "+processed_name;
        system(command.c_str());
        fstream file(".junk");
        int status;
        file>>status;
        if(status==-1)
        {
            cout<<"> OTP Sending Faliure. Please Check Your Network And Try Later.\n";
            string empty;
            return empty;
        }        
    }
    cout<<"> OTP sent success\n";
    return otp;
}

};
#endif