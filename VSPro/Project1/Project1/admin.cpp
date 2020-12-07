#include<iostream>
#include"addlist.cpp"
#include"viewlist.cpp"
#include"deletelist.cpp"
using namespace std;
void display()
{
    cout << "Welcome to restaurant management system \n";
    cout << "1. View Oders.\n";
    cout << "2. Delete Oders.\n";
    cout << "3. Add Oders.\n";

}
void admin()
{
    display();

    int option;
    cout << "What would you like to do:  ";
    cin >> option;
    switch (option)
    {
    case 1:
        viewlist(heada);
        break;
    case 2:
        deletelist();
        break;
    case 3:
        addlist();
        break;

    default:
        cout << "Please choose wisely \n";
        admin();
        break;
    }

}