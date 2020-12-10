#include<iostream>
#include <stdlib.h>
#include<cstring>
#include<iomanip>
#include<string.h>
using namespace std;
void choice();
void c_choice();
void admin();
void topbar();
void mainpage();
void searchFood(); //line 243
void order_main(); //line 354
int main();
void main_menu(); //line 373
void customer_main(); //line 385
//void foodDisplayOrder(); //line 253
void foodSearchOrder(); //line 228
int totalOrder = 0; //line 321
int choice_value;

struct order {
    int quantity;
    char foodname[20];
    float price;
    int orderNumber;
    order* prev;
    order* next;
};

struct order* orderArray[20];
int orderNumber = 0;

class AVLNode
{
public:
    int key;
    int nodeNumber;
    int quantity;
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
        cout <<" \n \t \t" <<root->food << " ";
        cout << root->key << " \n";

        inOrder(root->right);
    }
}

void foodSearchOrder(AVLNode* root, char foodSearch[20])
{
     AVLNode* temp = new AVLNode;
    if (root != NULL)
    {
        temp = root;
        foodSearchOrder(root->left, foodSearch);
        if(!strcmp(temp->food,foodSearch))
            std::cout<<"\t \t \t" << temp->food << "\t \t"<< temp->key << "\t" <<std::endl;
        foodSearchOrder(root->right, foodSearch);
    }
}

order* heado = NULL, * tailo = NULL;
void choice_order()
{
    cout<<"\n \t \t \tDo you want to Order? (0/1): ";
    cin>>choice_value;
    switch(choice_value){
    case 0:
        break;
    case 1:
        order_main();
    default:
        order_main();
    }
}

void searchFood(AVLNode* root) {
    char foodSearch[20];
    topbar();
    std::cout<<" \n \n \t \tEnter foodname to be searched: ";
    std::cin>>foodSearch;
    std::cout<<"\n \t \t \tFood Item \t"<<"Price \t"<<std::endl;
    foodSearchOrder(root, foodSearch);
    choice_order();
};

/*void foodDisplayOrder(AVLNode* root)
{
     AVLNode* temp = new AVLNode;
    if (root != NULL)
    {
        temp = root;
        cout<<"Customer"<<root->nodeNumber<<endl;
        foodDisplayOrder(root->left);
        std::cout << temp->food << "\t"<< temp->key << "\t" << temp->quantity<<"\t"<<temp->quantity*temp->key<<"\t"<<std::endl;
        foodDisplayOrder(root->right);
    }
}*/

void displayAdminOrder( order* heado) {
    struct order* temp = heado;
    if (temp == NULL)
    {
        std::cout << "List EMPTY" << std::endl;
    }
    else
    {
        int num = 0;
        //std::cout<<"Customer "<<temp->orderNumber<<std::endl;
        while (temp != NULL)
        {
            if(!strcmp(temp->foodname,"MOMO"))
                std::cout<<"Customer "<<temp->orderNumber<<std::endl;
            std::cout << temp->orderNumber<<"\t"<<temp->foodname << "\t" << temp->price << "\t" << temp->quantity << "\t" << temp->price * temp->quantity << std::endl;
            temp = temp->next;
        }


    }
};

void displayDeleteOrder( order* heado) {
    struct order* temp = heado;
    if (temp == NULL)
    {
        std::cout << "List EMPTY" << std::endl;
    }
    else
    {
        int num = 0;
        //std::cout<<"Customer "<<temp->orderNumber<<std::endl;
        while (temp->next != NULL)
        {
            if(!strcmp(temp->foodname,"MOMO"))
                std::cout<<"Customer "<<temp->orderNumber<<std::endl;
            std::cout << temp->orderNumber<<"\t"<<temp->foodname << "\t" << temp->price << "\t" << temp->quantity << "\t" << temp->price * temp->quantity << std::endl;
            temp = temp->next;
        }


    }
};

void displayCustomerOrder(AVLNode* root) {
    AVLNode* temp = root;
    if (temp != NULL)
    {
        if(temp != NULL)
        {
            displayCustomerOrder(root->left);
            std::cout << temp->food << "\t" << temp->key << "\t" << temp->quantity << "\t" << temp->key * temp->quantity << std::endl;
            displayCustomerOrder(root->right);
        }
    }
};

void deleteOrder(order* heado, int customer_number){
    order* temp = heado;
    while(temp->orderNumber!=customer_number ){
        temp = temp->next;
    }
        if(temp->orderNumber==customer_number){
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            temp=temp->next;
        }
        if(temp->next!= NULL){
            deleteOrder(heado, customer_number);
        }
        //temp->prev->next = temp->next;
        //temp->next->prev = temp->prev;
        //free(temp);
        //temp=temp->next;
    //for(int i=0;i<2;i++){
    //  deleteOrder(temp, customer_number);
    //}
}

order* createOrder(AVLNode* root)
{
    if (root == NULL)
        return 0;
    else if (root != NULL)
    {
        createOrder(root->left);
        //root=root->left;
        std::cout <<"\t \t" <<root->food << "\t";
        //int q;
        std::cout << "\t Quantity: ";
        std::cin >> root->quantity;
        root->nodeNumber = totalOrder;
        order* newnode = new order;
        newnode->quantity = root->quantity;
        newnode->price = root->key;
        newnode->orderNumber = root->nodeNumber;
        //cout<<"Order Number: "<<newnode->orderNumber<<std::endl;
        //cout<<"Node nUmber: "<<root->nodeNumber<<std::endl;
        strcpy(newnode->foodname, root->food);
        order* temp = heado;

        if (temp == NULL) {
            heado = tailo = newnode;
        }
        else {
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

void order_main()
{
    system("CLS");
    topbar();
    AVLNode* root = NULL;
    char food_Momo[] = "MOMO";
    char food_Burger[] = "BURGER";
    char food_Pasta[] = "PASTA";
    char food_Pizza[]= "PIZZA";
    root = insert(root, 100, food_Momo);
    root = insert(root, 300, food_Burger);
    root = insert(root, 200, food_Pasta);
    root = insert(root, 500, food_Pizza);
    std::cout<<"\n \n";
    std::cout<<"\t \t \t "<<std::setfill(' ')<<std::setw(34)<<"Today's Menu"<<std::endl;
    inOrder(root);
    std::cout << std::endl;
    totalOrder++;
    std::cout<<"\t \t \t Customer No."<<totalOrder<<std::endl;
    createOrder(root);
    system("CLS");
    topbar();
    std::cout<<"\t \t \t Customer No."<<totalOrder<<std::endl;
    displayCustomerOrder(root);
    choice();
}
AVLNode* root = NULL;
void main_menu()
{
    char food_Momo[] = "MOMO";
    char food_Burger[] = "BURGER";
    char food_Pasta[] = "PASTA";
    char food_Pizza[]= "PIZZA";
    root = insert(root, 100, food_Momo);
    root = insert(root, 300, food_Burger);
    root = insert(root, 200, food_Pasta);
    root = insert(root, 500, food_Pizza);
}

void customer_main(){
    main_menu();
    system("CLS");
    std::cout<<"\t \t \t"<<std::setfill('*')<<std::setw(74)<<""<<std::endl;
    std::cout<<"\t \t \t** \t \tWelcome to Restaurant"<<setfill(' ')<<setw(38)<<"**\n";
    std::cout<<"\t \t \t"<<std::setfill('*')<<std::setw(74)<<""<<std::endl;
    cout<<"\n \n\t \t \t 1. Search Food:"<<endl;
    cout<<"\n \n\t \t \t 2. Order Food"<<endl;
    cout<<"\n \t \t \tEnter choice: ";
    cin>>choice_value;
    switch(choice_value){
    case 1:
        system("CLS");
        searchFood(root);
        break;
    case 2:
        order_main();
        break;
    default:
        cout<<"\n \tRe-evaluate your choice"<<endl;
        customer_main();
    }
}

