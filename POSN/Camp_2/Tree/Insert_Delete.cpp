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

// function prototype
void Inorder(Node* root);
Node* insertion(Node* root, int key);
Node* deletion(Node* root, int key);
void deleteDeepest(Node* root,Node* deepest_node);

void Inorder(Node* root){
    if(root==NULL)return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

Node* insertion(Node* root, int key){
    if(root==NULL)root = new Node(key);
    queue<struct Node*> q;
    q.push(root);

    //BFS
    while (!q.empty()){
        Node* node = q.front();
        q.pop();

        if(node->left==NULL){
            node->left= new Node(key);
            break;
        }else q.push(node->left);

        if(node->right==NULL){
            node->right= new Node(key);
            break;
        }else q.push(node->right);
    }
    return root;
}

void deleteDeepest(Node* root,Node* deepest_node){
    Node* node;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        node = q.front();
        q.pop();

        if(node==deepest_node){
            node = NULL;
            delete(deepest_node);
            return;
        }

        if(node->right != NULL){
            if(node->right == deepest_node){
                node->right = NULL;
                delete(deepest_node);
                return;
            }else q.push(node->right);
        }

        if(node->left != NULL){
            if(node->left == deepest_node){
                node->left = NULL;
                delete(deepest_node);
                return;
            }else q.push(node->left);
        }
    }
}

Node* deletion(struct Node* root, int key){
    if(root==NULL)return NULL;
    if(root->left==NULL&&root->right==NULL){
        if(root->data==key)return NULL;
        else return root;
    }
    Node* node,*key_node;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        node = q.front();
        q.pop();
        if(node->data==key)key_node=node;
        if(node->left!=NULL)q.push(node->left);
        if(node->right!=NULL)q.push(node->right);
    }

    if(key_node!=NULL){
        int x = node->data;
        deleteDeepest(root,node);
        key_node->data = x;
    }
    return root;
}

/*
          10
        /    \
       11      9
      /       / \
     7      15   8
*/

int main(){

    Node* root        = new Node(10);
    root->left        = new Node(11);
    root->left->left  = new Node(7);
    root->right       = new Node(9);
    root->right->left = new Node(15);
    root->right->right= new Node(8);

    cout << "\nInOrder Traversal of Binary Tree before insert is \n";
    Inorder(root);
    int ins_key = 12;
    root = insertion(root, ins_key);
    cout << "\nInOrder Traversal of Binary Tree after insert is \n";
    Inorder(root);

/*
           10
        /      \
       11       9
      /  \     / \
     7   12  15   8
*/

    cout << "\nInOrder Traversal of Binary Tree before deletion is \n";
    Inorder(root);
    int del_key = 11;
    root = deletion(root, del_key);
    cout << "\nInOrder Traversal of Binary Tree after deletion is \n";
	Inorder(root);

	return 0;
}
