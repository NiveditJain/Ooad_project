#ifndef shop_cpp
#define shop_cpp
#include "shopkeeper.cpp"
#include "Item.cpp"

class Shop
{
    public:
    ulli ID;
    char type[51];
    char name[51];
    time_t timing;
    char email[51];
    bool working_days[7];
    ulli no_of_items;
    void search_item();
};


#endif