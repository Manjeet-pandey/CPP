#include<iostream>
#include <stdlib.h>
#include<cstring>
using namespace std;
struct node{
    
    int quantity;
    char foodname[20];
    int data;
    float price;
    node* next;
    node* prev;
};
struct node* heada = NULL, * taila = NULL;
struct node* menu(struct node* head, int data, char foodname[20], float price) {
    struct node* newnode = new node;
    newnode->data = data;
    newnode->price = price;
    newnode->quantity = 0;
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
void addlist()
{
  
    char food_Momo[] = "MO:MO";
    char food_burger[] = "Burger";
    heada = menu(heada, 1, food_Momo, 100.0);
    heada = menu(heada, 2, food_burger, 200.0);

}