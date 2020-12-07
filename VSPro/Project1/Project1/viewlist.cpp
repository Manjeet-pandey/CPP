#include<iostream>
#include "addlist.cpp "
void viewlist(struct node* head)
{
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