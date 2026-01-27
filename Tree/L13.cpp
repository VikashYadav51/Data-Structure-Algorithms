#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int element){
        this->data = element;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* construct_BST(Node* root, int data){
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

    return  root;
}

void take_input(Node* &root){
    int data;
    cout <<"Enter the data "<< endl;
    cin >> data;

    if(data == -1){
        return ;
    }
    
    root = construct_BST(root, data);

    take_input(root);

    return ;

}



int main(){

}