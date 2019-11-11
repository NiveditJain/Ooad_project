#ifndef database_cpp
#define database_cpp
#include "all_includes"

Customer get_customer(string email)
{
    Customer temp;
    temp.name[0]='\0';
    email="database/customer_data/"+email+".ooad";
    fstream file(email.c_str());

    if(!file)
    {
        file.close();
        return temp;
    }

    file.read((char *)&temp,sizeof(Customer));
    file.close();
    return temp;
}

// Shopkeeper get_shopkeeper(string email)
// {
//     Shopkeeper temp;
//     temp.name[0];
//     email="database/shopkeeper_data/"+email;
//     filestream file(email.str());

//     if(!file)
//         return temp;
    
//     file.read((char *)&temp,sizeof(Shopkeeper));
//     return temp;
// }

void register_Customer(Customer temp,string email)
{
    string path="database/customer_data/"+email+".ooad";
    ofstream file(path.c_str(),ios::binary | ios::out);
    file.write((char*)&temp,sizeof(Customer));
    file.close();
}

#endif