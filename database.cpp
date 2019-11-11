#include<bits/stdc++.h>
using namespace std;
#include "customer.cpp"
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
{//cout<<temp.name[0];
    
    string path="database/customer_data/"+email+".ooad";
    ofstream file(path.c_str(),ios::binary | ios::out);
   if(!file)cout<<"file not found";
    file.write((char*)&temp,sizeof(Customer));
    file.close();
}

