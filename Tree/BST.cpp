#include <iostream>
using namespace std;
struct BST{
    int data;
    BST *left, *right;
};
BST *root, *temp, *ttemp, *P;
void init(){
    root = temp = ttemp = NULL;
}
void create_Root(int x){
    root = new BST; 
    root->data = x; //root points to new node
    root->left = root->right = NULL;
}
void add_Node(int x){
    temp = root;
    while(temp!=NULL){
        ttemp = temp;
        if(temp->data > x)
            temp = temp->left;
        else
            temp = temp->right;
    }
    P=new BST; //create new node
    P->data = x;
    P->left = P->right = NULL;
    if(ttemp->data>x)
    ttemp->left = P;
    else
    ttemp->right = P;
}
void Inorder(BST *P){
    if(P!=NULL){
        Inorder(P->left);
        cout<<P->data<<" ";
        Inorder(P->right);
    }
}
void Preorder(BST *P){
    if(P!=NULL){
        cout<<P->data<<" ";
        Preorder(P->left);
        Preorder(P->right);
    }
}
void Postorder(BST *P){
    if(P!=NULL){
        Postorder(P->left);
        Postorder(P->right);
        cout<<P->data<<" ";
    }
}
int main(){
    init();
    create_Root(100);
    add_Node(50);
    add_Node(200);
    add_Node(150);
    add_Node(170);
    add_Node(300);
    add_Node(20);
    cout<<"Inorder Traversal: ";
    Inorder(root);
    cout<<"\nPreorder Traversal: ";
    Preorder(root);
    cout<<"\nPostorder Traversal: ";
    Postorder(root);
    return 0;
}
