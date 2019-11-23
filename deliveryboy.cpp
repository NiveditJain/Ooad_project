#ifndef delivery_boy_cpp
#define delivery_boy_cpp
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ulli;

class Deliveryboy
{
    string name;
    int id;
    ulli contact_number;
    bool availability;
    bool transaction;
    static int count_delivery_boys;

    public:
    Deliveryboy()
    {
        count_delivery_boys++;
        name="abcd";
        id=0;
        contact_number=0;
        availability=false;
        transaction=false;
    }
     void assign_id()
    {   
        id=count_delivery_boys;
    }
    void input_details()
    {
        cout<<"Enter name:\n";
        getline(cin,name);
        cout<<"\nEnter contact number:\n";
        cin>>contact_number;
    }
};
int Deliveryboy::count_delivery_boys=0;
#endif