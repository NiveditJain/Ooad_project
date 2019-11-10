#include<iostream>
#include<cstring>
using namespace std;

bool check_email_iitj(char input[]){
    char *ptr;
        ptr= strstr(input, "@iitj.ac.in"); //searches input array for "@iitj.ac.in" string
        if(ptr) 
        {
            return true;
        }
}

void verify_email(char input[],int sizeOf){
    string empty_email;
    if(check_email_iitj(input)==false)
    cout<<"this email does not belong to iitj!";
}


void get_email(){
    int x = 61;          //51+@iitj.ac.in
    char input[x];       //array to hold input
    int sizeOf;          //holds length of input array
    cin.getline(input, x);
    verify_email(input,sizeOf);
}
