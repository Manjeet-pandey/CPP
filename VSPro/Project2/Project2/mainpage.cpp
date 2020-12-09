#include<iostream>
#include <stdlib.h>
#include<cstring>
#include"customer.cpp"
using namespace std;
struct node {
    struct node* prev;
    char foodname[20];
    int data;
    float price;
    struct node* next;
};
struct node* heada = NULL, * taila = NULL;
struct node* createadmin(struct node* head, int data, char foodname[20], float price) {
    struct node* newnode = new node;
    newnode->data = data;
    newnode->price = price;
    newnode->next = NULL;
    strcpy(newnode->foodname, foodname);

    struct node* temp = head;

    if (temp == NULL) {
        heada = taila = newnode;
    }
    else {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = taila;
        taila = newnode;
    }

    return heada;
};
void displayList(struct node* head) {
    struct node* temp = head;
    struct node* temp1 = NULL;

    if (temp == NULL)
    {
        std::cout << "List EMpty" << std::endl;
    }
    else
    {
        while (temp != NULL)
        {
            std::cout << temp->data << "\t" << temp->foodname << "\t" << temp->price << std::endl;
            temp = temp->next;

        }

    }


}

//void addlist()
//{
//    node* heada;
//    heada = NULL;
//    char food_Momo[] = "MO:MO";
//    char food_burger[] = "Burger";
//    heada = createadmin(heada, 1, food_Momo, 100.0);
//    heada = createadmin(heada, 2, food_burger, 200.0);
//    createorder(heada);
//}

//struct order* deleteorder(struct order* head, int data)
//{
//    struct order* temp;
//    if (head == NULL)
//    {
//        cout << "List is empty\n";
//        return head;
//    }
//    if (head->next == NULL)
//        if (head->data == data)
//        {
//            temp = head;
//            head = NULL;
//            delete(temp);
//            return head;
//        }
//        else
//        {
//            cout << "Element " << data << " not found\n";
//            return head;
//        }
//
//    if (head->data == data)
//    {
//        temp = head;
//        head = head->next;
//        head->prev = NULL;
//        delete(temp);
//        return head;
//    }
//
//    temp = head->next;
//    while (temp->next != NULL)
//    {
//        if (temp->data == data)
//        {
//            temp->prev->next = temp->next;
//            temp->next->prev = temp->prev;
//            delete(temp);
//            return head;
//        }
//        temp = temp->next;
//    }
//
//    if (temp->data == data)
//    {
//        temp->prev->next = NULL;
//        delete(temp);
//        return head;
//    }
//    cout << "Element " << data << " not found\n";
//    return head;
//};

void mainpage()
{
    std::cout << "Welcome to restaurant management system \n";
    std::cout << "1. Admin\n";
    std::cout << "2. Customer\n";

}
void admindisplay()
{
    cout << "Welcome to restaurant management system \n";
    cout << "1. View Oders.\n";
    cout << "2. Delete Oders.\n";
}

void admin()
{
    admindisplay();

    int option;
    int data_elem;
    cout << "What would you like to do:  ";
    cin >> option;
    switch (option)
    {
    case 1:
        displayAdminOrder(heado);
        main();
        break;
    case 2:
        int customer_number;
        cout<<"Enter customer Number to delete order: ";
        cin>>customer_number;
        deleteOrder(heado, customer_number);
        cout<<"\bUpdated order"<<endl;
        displayAdminOrder(heado);
        main();
        break;
    default:
        cout << "Please choose wisely \n";
        admin();
        break;
    }

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

    case 2:
        customer_main();
        break;

    default:
        cout << "Please choose wisely \n";
        main();
        break;
    }
}
