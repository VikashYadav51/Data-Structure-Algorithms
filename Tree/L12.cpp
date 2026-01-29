#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int element){
        this->data = element;
        this->left =nullptr;
        this->right = nullptr;
    }
};


Node*  construct_BST(Node* root, int data){
    if(root == nullptr){
        root = new Node(data);
        return root;
    }

    if(data < root->data){
        root->left = construct_BST(root->left, data);
    }

    else{
        root->right = construct_BST(root->right, data);
    }

    return root;
}

void takeInput(Node* &root){
    int data;
    cout <<"Enter the data "<< endl;
    cin>> data;

    if(data != -1){
        root = construct_BST(root, data);
        takeInput(root);
    }

    return ;
}

Node* Flatten_BST(Node* &root){
    if(root == nullptr){
        return root;
    }
    
    Node* left = root->left;
    
    if(left != nullptr){
        left = root->left;
        root->left = nullptr;
    }
    
    Node* temp = left;
    
    while(temp != nullptr && temp->right != nullptr){
        temp = temp->right;
    }
    
    
    if(temp != nullptr){
        temp->right = root;
    }
    
    if(left != nullptr){
        root = left;
    }
    
    if(left != nullptr){
       Node* op1 = Flatten_BST(root);
    }
    
    else{
        Node* op2 = Flatten_BST(root->right);
    }
    
    return root;
    
}


int main(){

}