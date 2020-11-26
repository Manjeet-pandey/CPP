#include<iostream>
#include"addclist.cpp"
#include"viewclist.cpp"
#include"deleteclist.cpp"
using namespace std;
void cdisplay()
{
    cout<<"Welcome to restaurant management system \n";
    cout<<"1. View Your Oders.\n";
    cout<<"2. Delete Your Oder.\n";
    cout<<"3. Add Oders.\n";

}
void customer()
{   
    cdisplay();
    int option;
    cout<<"What would you like to do:  ";
    cin>>option;
    switch (option)
    {
    case 1: 
        viewclist();
        break;
    case 2 : 
        deleteclist();
        break;
    case 3:
        addclist();
   
    default:
        cout<<"Please choose wisely \n";
        
        break;
    }
   
}