#ifndef user_cpp
#define user_cpp
typedef unsigned long long ulli ;
class User
{
protected:
char password[51];

public:
    char email[51];
    char name[20];
    ulli contact_number;
};
#endif