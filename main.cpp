#include <iostream>
#include <fstream>

using namespace std;

void LogIn();
void Register();
void secret();

class student
{

};

int main()
{
    int init_choice;
    cout << "\t\t--------------------------------------------" << endl;
    cout << "\t\t\t\t1.Log In" << endl;
    cout << "\t\t\t\t2.Register" << endl;
    cout << "\t\t\t\t3.Exit" << endl;
    cout << "\t\t--------------------------------------------" << endl;
    cout << "\t\t\t\tYour choice- " << endl;
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
    cout << "\t\t--------------------------------------------" << endl;
    cout << "\t\t\tLog in with an authorised account" << endl;
    cout << "\t\t--------------------------------------------" << endl;
    cout << "\t\t\t\tNAME- ";
    //cin >>
}