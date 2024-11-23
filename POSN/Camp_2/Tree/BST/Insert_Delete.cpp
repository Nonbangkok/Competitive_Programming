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

Node* insert(Node* root,int key){
    Node* current = root;
    bool stop=0;
    while(!stop){
        if(key>current->data){
            if(current->right==NULL){
                current->right = new Node(key);
                stop = !stop;
            }else current = current->right;
        }else{
            if(current->left==NULL){
                current->left = new Node(key);
                stop = !stop;
            }else current = current->left;
        }
    }
    return root;
}

// remain deletion in BST
/*
              8
            /   \
           3    10
         /  \      \
       1     6     14
           /  \   /
          4   7  13
*/
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
    root = insert(root,2);
    Inorder(root);
}