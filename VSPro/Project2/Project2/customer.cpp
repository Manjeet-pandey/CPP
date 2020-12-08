#include<iostream>
#include <stdlib.h>
#include<cstring>
using namespace std;

class AVLNode
{
public:
    int key;
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
    strcpy_s(node->food, foodname);
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
struct order {
    int quantity;
    char foodname[20];
    float price;
    order* prev;
    order* next;
};
order* heado = NULL, * tailo = NULL;
void displayOrder(struct order* head) {
    struct order* temp = head;
    struct order* temp1 = NULL;

    if (temp == NULL)
    {
        std::cout << "List EMpty" << std::endl;
    }
    else
    {
        while (temp != NULL)
        {
            std::cout << temp->foodname << "\t" << temp->price << "\t" << temp->quantity << "\t" << temp->price * temp->quantity << std::endl;
            temp = temp->next;
        }

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
        cout << root->food << " ";
        int q;
        cout << "Enter Quantity";
        cin >> q;
        order* newnode = new order;
        newnode->quantity = q;
        newnode->price = root->key;
        strcpy_s(newnode->foodname, root->food);
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
void customer_main()
{
    AVLNode* root = NULL;
    char food_Momo[] = "MO:MO";
    char food_Burger[] = "Burger";
    char food_ABC[] = "ABC";
    root = insert(root, 100, food_Momo);
    root = insert(root, 300, food_Burger);
    root = insert(root, 200, food_ABC);
    inOrder(root);
    cout << endl;
    createOrder(root);
    displayOrder(heado);
}