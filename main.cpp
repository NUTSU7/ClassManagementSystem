#include <iostream>
#include <fstream>

using namespace std;

void LogIn();
void Register();
void secret();

class student
{
public:
    string name;
};

int main()
{
    system("clear");
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
}

void secret()
{
    system("clear");
}