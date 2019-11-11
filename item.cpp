

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
};

