#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    system("stty -echo"); /* switch echo off */
    getline(cin,str);
    system("stty echo"); /* switch it on again */
    cout<<str;
}