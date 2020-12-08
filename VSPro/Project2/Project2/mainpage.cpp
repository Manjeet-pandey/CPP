#include<iostream>
#include <stdlib.h>
#include<cstring>
#include"customer.cpp"
using namespace std;
//struct order* createorder(struct node*);
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
    strcpy_s(newnode->foodname, foodname);

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


//struct order {
//    int quantity;
//    char foodname[20];
//    int data;
//    float price;
//    struct order* prev;
//    struct order* next;
//};
//struct order* heado = NULL, * tailo = NULL;
/*
struct order* createorder(struct node* head)
{

    int q;
    struct order* newnode = new order;
    cout<<"Enter the quantity";
    cin>>q;
    newnode->quantity = q;
    newnode->data=head ->data;
    strcpy(newnode->foodname,head->foodname);
    newnode->price=head->price;
    newnode->next = NULL;
    struct order* temp = heado;

    if (temp == NULL){
        heado = tailo = newnode;
    }
    else{
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = tailo;
        tailo = newnode;
    }
    return heado;
};
*/
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
//struct order* createorder(struct node* head)
//{
//
//    struct node* temp = head;
//    struct node* temp1 = NULL;
//
//    if (temp == NULL)
//    {
//        std::cout << "List EMpty" << std::endl;
//    }
//    else
//    {
//        while (temp != NULL)
//        {
//            std::cout << temp->data << "\t" << temp->foodname << "\t" << temp->price << std::endl;
//
//            int q;
//            struct order* newnode = new order;
//            cout << "Enter the quantity";
//            cin >> q;
//            newnode->quantity = q;
//            newnode->data = temp->data;
//            strcpy_s(newnode->foodname, temp->foodname);
//            newnode->price = temp->price;
//            newnode->next = NULL;
//            struct order* tempo = heado;
//
//            if (tempo == NULL) {
//                heado = tailo = newnode;
//            }
//            else {
//                while (tempo->next != NULL)
//                {
//                    tempo = tempo->next;
//                }
//                tempo->next = newnode;
//                newnode->prev = tailo;
//                tailo = newnode;
//            }
//
//            temp = temp->next;
//
//        }
//
//    }
//    return heado;
//};
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
//void displayOrder(struct order* head) {
//    struct order* temp = head;
//    struct order* temp1 = NULL;
//
//    if (temp == NULL)
//    {
//        std::cout << "List EMpty" << std::endl;
//    }
//    else
//    {
//        while (temp != NULL)
//        {
//            std::cout << temp->data << "\t" << temp->foodname << "\t" << temp->price << "\t" << temp->quantity << std::endl;
//            temp = temp->next;
//        }
//
//    }
//
//
//}
void mainpage()
{
    cout << "Welcome to restaurant management system \n";
    cout << "1. Admin\n";
    cout << "2. Customer\n";

}
void admindisplay()
{
    cout << "Welcome to restaurant management system \n";
    cout << "1. View Oders.\n";
    cout << "2. Delete Oders.\n";
    cout << "3. Add Oders.\n";

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
        displayOrder(heado);
        break;
    case 2:
        cout << "What do you want to delete :";
        cin >> data_elem;
        //deleteorder(heado, data_elem);
        admin();
        break;
    case 3:
        //addlist();
        admin();
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
