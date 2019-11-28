#ifndef item_cpp 
#define item_cpp
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ulli;
#include "utilities.cpp"
//#include "transaction.cpp"
class Item
{
    public:
        // number of keywords under usage
        int number_of_keyword;

        // 10 key possible in each file 
        // 30 characters per key word
        char keywords[10][31];

        //name of the item
        char name[51];
           
        //shop category
        char shop_category[51];

        // price of item
        int price;
    
        // description of each time maximum lenght 100 characters
        char description[1000]; 

        // unique ID for each item
        unsigned long long int item_ID;

        // quantity of each item
        int quantity;  

        //constructor
        Item();

        //function to add a keyword
        void add_keyword(char keyword[]);

        //to take item details
        int get_item_details(string name1,unsigned long long int ID);

};

Item :: Item(){
    number_of_keyword=0;
    quantity=0;
}
 
int Item :: get_item_details(string category,unsigned long long int ID){
    
    // holding temperary data
    item_ID=ID;
    string temp;
    char waste;
    strcpy(shop_category,category.c_str());
    cout<<"> Enter name of the item : ";
    scanf("%c",&waste);
    getline(cin,temp);

    if(temp.length()==0)
    {
        cout<<"> Name lenght must be greater than 0";
        exit(0);
    }

    strcpy(name,temp.c_str());

    // cout<<"> Enter ItemID : "
    // cin>>item_ID;
    // if(item_ID<0)
    // {
    //     cout<<"> ItemID should be greater than 0";
    //     exit(0);
    // }

    cout<<"> Enter the price of the item : ";
    cin>>price;
    if(price<0)
    {
        cout<<"> price of the item should be greater than 0";
        exit(0);
    }

    cout<<"> Enter the quantity available : ";
    cin>>quantity;
    if(quantity<0)
    {
        cout<<"> quantity should be greater than zero";
        exit(0);
    }

    cout<<"> Enter no. of keywords (1=<__<=30): ";
    cin>>number_of_keyword;
    if(number_of_keyword<0)
    {
        cout<<"> number of keywords should be greater than zero";
        exit(0);
    }

    cout<<"> Enter keywords\n";
    for(int j=0;j<number_of_keyword;j++)
    {
        cout<<"> ";
        cin>>temp;
        if(temp.length()==0)
        {
            cout<<"> length of the keyword shoul be greater than zero";
            exit(0);
        }
        strcpy(keywords[j],temp.c_str()); 
    }

    cout<<"> Enter a description less than 1000 characters : ";
    string des; 
    scanf("%c",&waste);
    getline(cin,des);
    strcpy(description,des.c_str());

    return -1;
} 
void update_item_record(Item item, string name1)
{
    cout << ">" << item.name << endl
         << "> what do you want to update?\n";
    cout << "> 1) quantity\n> 2) price\n> 3) both price and quantity\n> ";
    ulli i;
    cin >> i;
    if (i == 1)
    {
        cout << "> Enter the new quantity : ";
        cin >> item.quantity;
    }
    else if (i == 2)
    {
        cout << "> Enter the new price : ";
        cin >> item.price;
    }
    else
    {
        cout << "> Enter the new quantity : ";
        cin >> item.quantity;
        cout << "> Enter the new price : ";
        cin >> item.price;
    }
    string path = "database/shop_items/" + name1 + ".ooad";
    fstream file(path.c_str());
    Item temp;
    while (file.read((char *)&temp, sizeof(Item)))
    {
        if (item.item_ID == temp.item_ID)
        {
            long pos = file.tellp(); 
            file.seekp(pos - sizeof(Item));
            file.write((char *)&item, sizeof(Item));
            break;
        }
    }
    file.close();
}


#endif