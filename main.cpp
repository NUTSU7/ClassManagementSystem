#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
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
    ifstream Fp;
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
        Fp.seekg(0, ios::end);
        if (Fp.tellg() == 0)
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
    system("clear");
    users log;
    ifstream Fp;
    Fp.open("users", ios::binary | ios::in);
    string temp_user, temp_pass;
    Fp.seekg(0);
    Fp.read((char*)&log, sizeof(log));
    cout << "\t\t--------------------------------------------" << endl;
    cout << "\t\t\tLog in with an authorised account" << endl;
    cout << log.user << endl;
    cout << log.pass << endl;
    cout << "\t\t--------------------------------------------" << endl;
    cout << "\t\t\t\tName- ";
    cin >> temp_user;
    cout << "\n\t\t\t\tPass- ";
    cin >> temp_pass;
    cout << "\t\t--------------------------------------------" << endl;
    if(log.user == temp_user)
    {
        if(log.pass == temp_pass)
        {
            cout << "\t\t--------------------------------------------" << endl;
            cout << "\t\t\tSuccesfully logged in" << endl;
            cout << "\t\t--------------------------------------------" << endl;
            sleep(2);
            main();
            Fp.close();
        }
    }
}

void Register()
{
    system("clear");
    users Reg;
    fstream Fp;
    Fp.open("users", ios::binary | ios::in | ios::app);
    string temp_user, temp_pass, temp_reg_key;
    cout << "\t\t--------------------------------------------" << endl;
    cout << "\t\t\t\tRegister" << endl;
    cout << "\t\t--------------------------------------------" << endl;
    cout << "\t\t\t\tName- ";
    cin >> Reg.user;
    cout << "\n\t\t\t\tPass- ";
    cin >> Reg.pass;
    cout << "\n\t\t\t     Registration key- ";
    cin >> temp_reg_key;
    if(reg_key == temp_reg_key)
    {
        reg_key.clear();
        cout << "\t\t--------------------------------------------" << endl;
        cout << "\n\t\t\t\tSuccesfully registered"  << endl;
        cout << "\t\t--------------------------------------------" << endl;
        //Reg.user = temp_user;
        //Reg.pass = temp_pass;
        Fp.write((char*)&Reg, sizeof(Reg));
        Fp.close();
        sleep(2);
        main();
    }
    else
    {
        cout << "\n\t\t\tFailed, Registration key not matching" << endl;
        cout << "\t\t--------------------------------------------" << endl;
        sleep(2);
        main();
    }
}

void secret()
{
    system("clear");
    reg_key.clear();
    key();
    cout << "\t\t--------------------------------------------" << endl;
    cout << "\t\tYour secret REGISTRATION KEY is- " << reg_key << endl;
    cout << "\t\t--------------------------------------------" << endl;
    cout << "\t\tCopy it, it will be needed for registration" << endl;
    cout << "\t\t\t   In 10s this will disappear" << endl;
    sleep(4);
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