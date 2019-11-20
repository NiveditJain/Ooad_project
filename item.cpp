#ifndef item_cpp
#define item_cpp
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ulli;
class Item
{
        // number of keywords under usage
        int number_of_keyword;

        // 10 key possible in each file 
        // 30 characters per key word
        char keywords[10][31];

    public:
        //name of the item
        char name[51];

        // price of item
        int price;
    
        // description of each time maximum lenght 100 characters
        char description[1000];

        // unique ID for each item
        long long int item_ID;

        // quantity of each item
        int quantity;  

        //constructor
        Item();

        //function to add a keyword
        void add_keyword(char keyword[]);

        //to take item details
        void get_item_details(string name1);

};

Item :: Item(){
    number_of_keyword=0;
    quantity=0;
}

void Item :: add_keyword(char keyword[]){
    number_of_keyword++;
    strcpy(keywords[number_of_keyword],keyword);
}

void Item :: get_item_details(string name1){
    Item temp;
    cout<<"\n>Enter name of the item : ";
    cin>>name;
    cout<<"\n>Enter ItemID : ";
    cin>>item_ID;
    cout<<"\n>Enter the price of the item : ";
    cin>>price;
    cout<<"\n>Enter the quantity available : ";
    cin>>quantity;
    cout<<"\nEnter no. of keywords (1=<__<=30): ";
    ulli i;
    char key[31];
    cin>>i;
    cout<<"Enter keywords\n";
    while(i--){
        cin>>key;
        add_keyword(key);
    }
    cout<<"\n>Enter a description less than 1000 letters : \n";
    cin>>description;
    cout<<"\n>Item added to shop\n";
    //opening a file with the name of the shop and storing the item details
    string path;
    path= "database/shop_items/"+name1+".ooad";
    fstream file(path.c_str(),std::ios::app);
    file.write((char *)&temp, sizeof(Item));
} 
#endif