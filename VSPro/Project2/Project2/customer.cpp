#include<iostream>
#include <stdlib.h>
#include<cstring>
#include<string.h>
using namespace std;
void customer_main();
//void searchFood();
void order_main();
int main();

struct order {
    int quantity;
    char foodname[20];
    float price;
    order* prev;
    order* next;
};

struct order* orderArray[20];
int orderNumber = 0;

class AVLNode
{
public:
    int key;
    //float priceNode;
    AVLNode* left;
    AVLNode* right;
    int depth;
    char food[20];
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int depth(AVLNode* n)
{
    if (n == NULL)
        return 0;
    return n->depth;
}
AVLNode* newNode(int key, char foodname[20]) //this function needs update
{
    AVLNode* node = new AVLNode();
    node->key = key;
    strcpy(node->food, foodname);
    node->left = NULL;
    node->right = NULL;
    node->depth = 1;

    return(node);
}

AVLNode* rightRotate(AVLNode* y)
{
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;


    y->depth = max(depth(y->left),
        depth(y->right)) + 1;
    x->depth = max(depth(x->left),
        depth(x->right)) + 1;

    return x;
}

AVLNode* leftRotate(AVLNode* x)
{
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;
    x->depth = max(depth(x->left),
        depth(x->right)) + 1;
    y->depth = max(depth(y->left),
        depth(y->right)) + 1;

    return y;
}

int getBalance(AVLNode* N)
{
    if (N == NULL)
        return 0;
    return depth(N->left) -
        depth(N->right);
}
AVLNode* insert(AVLNode* node, int key, char foodname[20]) {
    if (node == NULL)
    {
        AVLNode* head = newNode(key, foodname);
        return(newNode(key, foodname));
    }


    if (key < node->key)
        node->left = insert(node->left, key, foodname);
    else if (key > node->key)
        node->right = insert(node->right, key, foodname);
    else
        return node;

    node->depth = 1 + max(depth(node->left), depth(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

AVLNode* minValueNode(AVLNode* node)
{
    AVLNode* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}
AVLNode* deleteNode(AVLNode* root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else
    {
        if ((root->left == NULL) ||
            (root->right == NULL))
        {
            AVLNode* temp = root->left ?
                root->left :
                root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            AVLNode* temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right,
                temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->depth = 1 + max(depth(root->left),
        depth(root->right));

    int balance = getBalance(root);

    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
void inOrder(AVLNode* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->food << " ";
        cout << root->key << " ";

        inOrder(root->right);
    }
}
void Next(AVLNode* root)
{
    if (root != NULL)
    {
        Next(root->left);
        Next(root->right);
    }
}
/*
void createOrder(AVLNode* root)
{
    if (root != NULL)
    {
        createOrder(root->left);
        cout<<root->food<<" ";
        int q;
        cout<<"Enter Quantity";
        cin>>q;
        order* newnode = new order;
        newnode->quantity=q;
        newnode->price=root->key;
        strcpy(newnode->foodname,root->food);
        order* temp = heado;

    if (temp == NULL){
        heada = taila = newnode;
    }
    else{
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = taila;
        taila = newnode;
    }


        createOrder(root->right);
    }
}
*/

order* heado = NULL, * tailo = NULL;

void searchFood(AVLNode* root) {
    char foodSearch[20];
    std::cout<<"Enter foodname to be searched: ";
    std::cin>>foodSearch;
    struct order* temp;
    strcpy(temp->foodname,root->food);
    temp->price = root->key;
    //struct order* temp1 = NULL;

    if (temp == NULL)
    {
        std::cout << "List EMPTY" << std::endl;
    }
    else
    {
        while (temp != NULL)
        {
            if(!strcmp(temp->foodname,foodSearch))
                std::cout << temp->foodname << "\t"<< temp->price << "\t" <<std::endl;
            temp = temp->next;
        }
        customer_main();
        //addAdminOrder(temp);

    }
};

void displayOrder(struct order* head) {
    struct order* temp = head;
    //struct order* temp1 = NULL;

    if (temp == NULL)
    {
        std::cout << "List EMPTY" << std::endl;
    }
    else
    {
        int order_num = 1;
        std::cout<<"Customer "<<order_num<<std::endl;
        while (temp != NULL)
        {
            std::cout << temp->foodname << "\t" << temp->price << "\t" << temp->quantity << "\t" << temp->price * temp->quantity << std::endl;
            temp = temp->next;
        }
        order_num++;

        //addAdminOrder(temp);

    }
};

order* createOrder(AVLNode* root)
{
    if (root == NULL)
        return 0;
    else if (root != NULL)
    {
        createOrder(root->left);
        //root=root->left;
        std::cout << root->food << " ";
        int q;
        std::cout << "Enter Quantity";
        std::cin >> q;
        order* newnode = new order;
        newnode->quantity = q;
        newnode->price = root->key;
        strcpy(newnode->foodname, root->food);
        order* temp = heado;

        if (temp == NULL) {
            heado = tailo = newnode;
        }
        else {
            /*while (temp->next != NULL)
            {
                temp = temp->next;
            }*/
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
            newnode->prev = tailo;
            tailo = newnode;
        }
        createOrder(root->right);
    }

    return heado;
}

/*void Order()
{
    AVLNode* root = NULL;
    createorder(root);
}
*/


void order_main()
{
    AVLNode* root = NULL;
    char food_Momo[] = "MO:MO";
    char food_Burger[] = "Burger";
    char food_ABC[] = "ABC";
    root = insert(root, 100, food_Momo);
    root = insert(root, 300, food_Burger);
    root = insert(root, 200, food_ABC);
    inOrder(root);
    std::cout << std::endl;
    createOrder(root);
    displayOrder(heado);
    main();
}
AVLNode* root = NULL;
void main_menu()
{
    char food_Momo[] = "MO:MO";
    char food_Burger[] = "Burger";
    char food_ABC[] = "ABC";
    root = insert(root, 100, food_Momo);
    root = insert(root, 300, food_Burger);
    root = insert(root, 200, food_ABC);
    //inOrder(root);
    //std::cout << std::endl;
    //createOrder(root);
    //displayOrder(heado);
    //main();
}

void customer_main(){
    int choice;
    main_menu();
    cout<<"To search food, enter 1"<<endl;
    cout<<"To order food enter 2"<<endl;
    cout<<"Enter choice: ";
    cin>>choice;
    switch(choice){
    case 1:
        searchFood(root);
        break;
    case 2:
        order_main();
        break;
    default:
        cout<<"Re-evaluate your choice"<<endl;
        customer_main();
    }
}

