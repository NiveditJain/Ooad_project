#ifndef moderator_cpp
#define moderator_cpp

class Moderator
{
    char password[51];
    public:
    char email[51];

    Moderator()
    {
        char temp_email[51]="moderator";
        char temp_password[51]="moderator@iitj#cc01";
    }
};

#endif