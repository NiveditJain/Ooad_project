#ifndef item_cpp
#define item_cpp
#include <bits/stdc++.h>
using namespace std;

class item
{
protected:
    int price;
    vector<string> keywords;
    string description;
    long long item_ID;
    int quantity_available;
public:
    item();
    bool match_keyword(string);
    
};

item::item()
{
}

bool item :: match_keyword(string s){

}




#endif