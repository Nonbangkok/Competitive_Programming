#include <bits/stdc++.h>
#define coutf(n, m) cout << fixed << setprecision(n) << m
#define forr(i, a, n) for (int i = a; i < n; i++)
#define forl(i, a, n) for (int i = a; i > n; i--)
#define macos ios::sync_with_stdio(0);cin.tie(0)
#define endll "\n"
#define sp " "
typedef long long ll;
using namespace std;
//Levelorder = BFS
//Inorder Preorder Postorder = DFS

//Levelorder -> use to add new node in
//Inorder -> get sorted array from BST
//Preorder -> use to create graph and prefix expression
//Postorder -> use to delete node

struct Node{
    int data;
    Node *left, *right;

    Node(int num){
        data = num;
        left=right=NULL;
    }
};

void Levelorder(Node* node);
void Inorder(Node* node);
void Preorder(Node* node);
void Postorder(Node* node);

void Levelorder(Node *root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node *node = q.front();
        cout << node->data << ", ";
        if(node->left != NULL)q.push(node->left);
        if(node->right != NULL)q.push(node->right);
        q.pop();

    }
}

void Inorder(Node* node){
     if(node==NULL) return;
     Inorder(node->left);
     cout<< node->data << ", ";
     Inorder(node->right);
}

void Preorder(Node* node){
     if(node==NULL) return;
     cout<< node->data << ", ";
     Preorder(node->left);
     Preorder(node->right);
}

void Postorder(Node* node){
     if(node==NULL) return;
     Postorder(node->left);
     Postorder(node->right);
     cout<< node->data << ", ";
}

/*
          1
        /   \
       2     3
      / \ 
     4   5
*/

int main() {macos;

    Node *root        = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);

    printf("Root data = %d", root->data);
    printf("\nleft child = %d", root->left->data);
    printf("\nright child = %d", root->right->data);
    printf("\nleft left child = %d", root->left->left->data);
    printf("\nleft right child = %d", root->left->right->data);

    cout << "\nLevel Order Traversal of Binary Tree is \n";
    Levelorder(root);
    cout << "\nInorder Traversal of Binary Tree is \n";
    Inorder(root);
    cout << "\nPreorder Traversal of Binary Tree is \n";
    Preorder(root);
    cout << "\nPostorder Traversal of Binary Tree is \n";
    Postorder(root);

    return 0;
}