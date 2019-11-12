#include<bits/stdc++.h>
using namespace std;
#include "moderator.cpp"
int moderator_portal(string email)
{
    string password;
    
    if(password.length()==0)
        return -1;
    
    if(moderator.login(password)==false)
    {
        cout<<"\n > invalid email password combination";
        return -1;
    }
}