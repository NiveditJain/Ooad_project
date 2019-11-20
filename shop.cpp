#ifndef shop_cpp
#define shop_cpp
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ulli;
#include "shopkeeper.cpp"
#include "item.cpp"

class Shop
{
    public:
    ulli ID;
    // char type[51];
    char name[51];
    char description[501];
    // time_t timing;
    char email[51];
    bool working_days[7];
    // ulli no_of_items;
    void search_item();

    Shop(int id=0)
    {
        ID=id;
    }

    int get_details(char shopkeeper_email[])
    {
        for(int i=0;shopkeeper_email[i]!='\0';i++)
            email[i]=shopkeeper_email[i];
        
        string name;
        cout<<">please re-enter the name of the shop\n> Enter the name of Shop :: ";
        getline(cin,name);

        convert(name,Shop::name);

        string description;
        cout<<"> Enter a short discription of your shop(250 character max without enter)\n";
        getline(cin,description);

        if(description.length()>250)
        {
            cout<<"> Entered Description greater than 250 characters";
            return -1;
        }

        convert(description,Shop::description);

        char answer;
        
        cout<<"> Is your shop open on Sunday? (y/n)  ";
        cin>>answer;
        
        if(answer=='y')
            working_days[0]=true;
        else if(answer=='n')
            working_days[0]=false;
        else
        {
            cout<<"> Invalid case selected";
            return -1;
        }



        cout<<"> Is your shop open on Monday? (y/n)  ";
        cin>>answer;
        
        if(answer=='y')
            working_days[1]=true;
        else if(answer=='n')
            working_days[1]=false;
        else
        {
            cout<<"> Invalid case selected";
            return -1;
        }


        cout<<"> Is your shop open on Tuesday? (y/n)  ";
        cin>>answer;
        
        if(answer=='y')
            working_days[2]=true;
        else if(answer=='n')
            working_days[2]=false;
        else
        {
            cout<<"> Invalid case selected";
            return -1;
        }


        cout<<"> Is your shop open on Wednesday? (y/n)  ";
        cin>>answer;
        
        if(answer=='y')
            working_days[3]=true;
        else if(answer=='n')
            working_days[3]=false;
        else
        {
            cout<<"> Invalid case selected";
            return -1;
        }


        cout<<"> Is your shop open on Thursday? (y/n)  ";
        cin>>answer;
        
        if(answer=='y')
            working_days[4]=true;
        else if(answer=='n')
            working_days[4]=false;
        else
        {
            cout<<"> Invalid case selected";
            return -1;
        }



        cout<<"> Is your shop open on Friday? (y/n)  ";
        cin>>answer;
        
        if(answer=='y')
            working_days[5]=true;
        else if(answer=='n')
            working_days[5]=false;
        else
        {
            cout<<"> Invalid case selected";
            return -1;
        }


        cout<<"> Is your shop open on Saturday? (y/n)  ";
        cin>>answer;
        
        if(answer=='y')
            working_days[6]=true;
        else if(answer=='n')
            working_days[6]=false;
        else
        {
            cout<<"> Invalid case selected";
            return -1;
        }

        return 0;
    }

    void add_items(char name[]){
        string name1(name);
        Item temp;
        temp.get_item_details(name1);
    }
};


#endif