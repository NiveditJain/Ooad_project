#include<iostream>
#include "terminal.cpp"
#include "database.cpp"
#include "utilities.cpp"
#include "classes.cpp"
using namespace std;

int main(){
    string mail=get_email();
    if(!mail.size())
    {customer c;
        
    /*cout<<"Register"
    //Get all the customer Data including Password Except Email id
    cout<<"Falaana Dhimkaana Customer\n";
    cout<<"";
        
    */
    fstream outfile ;
    outfile.open("database/oath/customer1.oath",ios::in|ios::out|ios::binary);
    outfile.seekp(0L,ios::end);
    outfile.write((char *)&c,sizeof(c));
    outfile.close();
    //Now the shopping option//
    }
}
