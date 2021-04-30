#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;

void LogIn();
void Register();
void secret();
string key();

string reg_key;

class users
{
public:
    string user;
    string pass;
};

class student
{
public:
    string name;
};

int main()
{
    system("clear");
    ofstream Fp;
    Fp.open("users", ios::binary | ios::in);
    int init_choice;
    cout << "\t\t--------------------------------------------" << endl;
    cout << "\t\t\t\t1.Log In" << endl;
    cout << "\t\t\t\t2.Register" << endl;
    cout << "\t\t\t\t3.Exit" << endl;
    cout << "\t\t--------------------------------------------" << endl;
    cout << "\t\t\t\tYour choice- ";
    cin >> init_choice;
    switch(init_choice)
    {
    case 1:
        Fp.seekp(0, ios::end);
        if (Fp.tellp() == 0)
        {
            cout << "\n\n\t\t--------------------------------------------" << endl;
            cout << "\t\t\t\tFile is empty" << endl;
            cout << "\t\t--------------------------------------------" << endl;
            sleep(2);
            main();
        }
        else
            LogIn();
    case 2:
        Register();
    case 3:
        exit;
    case 10:
        secret();
    }
    return 0;
}

void LogIn()
{
    string temp_name, temp_pass;
    system("clear");
    cout << "\t\t--------------------------------------------" << endl;
    cout << "\t\t\tLog in with an authorised account" << endl;
    cout << "\t\t--------------------------------------------" << endl;
    cout << "\t\t\t\tName- ";
    cin >> temp_name;
    cout << "\n\t\t\t\tPass- ";
    cin >> temp_pass;
    cout << "\t\t--------------------------------------------" << endl;
}

void Register()
{
    system("clear");
    string temp_name2, temp_pass2, reg_key2;
    cout << "\t\t--------------------------------------------" << endl;
    cout << "\t\t\tLog in with an authorised account" << endl;
    cout << "\t\t--------------------------------------------" << endl;
    cout << "\t\t\t\tName- ";
    cin >> temp_name2;
    cout << "\n\t\t\t\tPass- ";
    cin >> temp_pass2;
    cout << "\n\t\t\t\tReg.key ";
    cin >> reg_key2;
    if(reg_key == reg_key2)
    {
        reg_key.clear();
        cout << "\n\t\t\t\tSuccesfully registered ";
        cout << "\t\t--------------------------------------------" << endl;
        sleep(2);
        main();
    }
    else
    {
        cout << "\n\t\t\t\tFailed, Registration key not matching";
        cout << "\t\t--------------------------------------------" << endl;
        sleep(2);
    }
}

void secret()
{
    system("clear");
    key();
    cout << "\t\t--------------------------------------------" << endl;
    cout << "\t\tYour secret REGISTRATION KEY is- " << reg_key << endl;
    cout << "\t\t--------------------------------------------" << endl;
    cout << "\t\tCopy it, it will be needed for registration" << endl;
    cout << "\t\t\t   In 10s this will disappear" << endl;
    sleep(10);
    main();
}

string key()
{
    int i=8;
    string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int pos;
    while(reg_key.size() != i) {
        pos = ((rand() % (str.size() - 1)));
        reg_key += str.substr(pos,1);
    }
    return reg_key;
}