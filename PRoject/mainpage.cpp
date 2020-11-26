#include<iostream>
#include "admin.cpp"
#include "customers.cpp"
using namespace std;
void mainpage()
{
    cout<<"Welcome to restaurant management system \n";
    cout<<"1. Admin\n";
    cout<<"2. Customer\n";

}
int main()
{   
    int option;
    mainpage();
    cout<<"What do you want to Log-In as:  ";
    cin>>option;
    switch (option)
    {
    case 1: 
        admin();
        break;
    case 2 : 
        customer();
        break;
   
    default:
        cout<<"Please choose wisely \n";
        main();
        break;
    }
   
}