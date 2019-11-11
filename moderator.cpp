#ifndef moderator_cpp
#define moderator_cpp

class Moderator
{
    string password;
    public:
    string email;

    Moderator()
    {
        string temp_email="moderator";
        string temp_password="moderator@iitj#cc01";
        password=temp_password;
        email=temp_email;
    }
};

#endif