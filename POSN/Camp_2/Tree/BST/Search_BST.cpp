#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left, *right;
    Node(int num){
        data = num;
        left = right = NULL;
    }
};

void Inorder(Node* node){
    if(node==NULL) return;
    Inorder(node->left);
    cout<< node->data << ", ";
    Inorder(node->right);
}

Node* Search(Node* node,int key){
    if(node==NULL||node->data==key)return node;
    else if(node->data>key) return Search(node->left,key);
    else return Search(node->right,key);
    return NULL;
}

int main(){

    Node* root                = new Node(8);
    root->left                = new Node(3);
    root->left->left          = new Node(1);
    root->left->right         = new Node(6);
    root->left->right->left   = new Node(4);
    root->left->right->right  = new Node(7);
    root->right               = new Node(10);
    root->right->right        = new Node(14);
    root->right->right->left  = new Node(13);

    Inorder(root);
    cout << endl;
    Node* temp = Search(root,2);
    cout << temp->data;
}