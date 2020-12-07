#include<iostream>
#include "admin.cpp"
using namespace std;
void mainpage()
{
    cout << "Welcome to restaurant management system \n";
    cout << "1. Admin\n";
    cout << "2. Customer\n";

}
int main()
{
    int option;
    mainpage();
    cout << "What do you want to Log-In as:  ";
    cin >> option;
    switch (option)
    {
    case 1:
        admin();
        break;


    default:
        cout << "Please choose wisely \n";
        main();
        break;
    }

}