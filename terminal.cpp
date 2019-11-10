#include<iostream>
using namespace std;

// inputs user password in hidden mode 
// and returns as string
string input_password()
{
    string password;
    system("stty -echo");
    getline(cin,password);
    system("stty echo");
    return password; 
}

// 1->valid password
// 2->password length less than desired
// 3->no upper case
// 4->no lower case
// 5->no speacial character
// 6->no number
// parameters string and (int desried lenghth)
int check_password(string password,int desired_length=8)
{
    int lenghth=0;
    int count_upper=0;
    int count_lower=0;
    int count_special=0;
    int count_number=0;
    string allowed_speacial="~!@#$%^&*()_+-={}|?/><.,";

    for(char ch:password)
    {
        lenghth++;
        if('a'<=ch && ch<='z')
            count_lower++;
        else if('A'<=ch && ch<='Z')
            count_upper++;
        else if('1'<=ch && ch<='9')
            count_number++;
        else
        {
            char temp;
            for(auto temp: allowed_speacial)
            {
                if(temp==ch)
                {
                    count_special++;
                    break;
                }
            }
        }
    }
    if(lenghth<desired_length)
        return 2;
    if(count_upper==0)
        return 3;
    if(count_lower==0)
        return 4;
    if(count_special==0)
        return 5;
    if(count_number==0)
        return 6;
    return 1;
}

// input the password using get with conditions
string get_password(int desrired_length=8)
{
    string password=input_password();
    int error_type=check_password(password,desrired_length);
    if(error_type==1)
        return password;
    if(error_type==2)
        cout<<"\n > Password length must be >="<<desrired_length;
    if(error_type==3)
        cout<<"\n > Password must contain at least an upper case character";
    if(error_type==4)
        cout<<"\n > Password must contain at least a lower case character";
    if(error_type==5)
        cout<<"\n > Password must contain at least a special(~!@#$%^&*()_+-={}|?/><.,) character";
    if(error_type==6)
        cout<<"\n > Password must contain at least a number";
    string empty_string;
    return empty_string;
}