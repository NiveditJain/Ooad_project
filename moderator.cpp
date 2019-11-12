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
        strcpy(password,temp_password);
        strcpy(email,temp_email);
    }


    bool login(string password)
    {    
        char string_password[51];
        copy(password.begin(),password.end(),string_password);
        string_password[password.size()]='\0';

        encrypt(string_password);

        if(strcmp(string_password,Moderator::password)==0)
            return true;

        return false;
    }

    void set_password(string password)
    {
        copy(password.begin(),password.end(),Moderator::password);
        Moderator::password[password.size()]='\0';
    }


}moderator;

#endif