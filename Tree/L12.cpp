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


//  Convert BST to flatten BST...

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

// Normal BST TO Balanace BST...

void inOrder(Node* root, vector<int> &result){
    if(root == nullptr){
        return ;
    }
    
    inOrder(root->left, result);
    result.push_back(root->data);
    inOrder(root->right, result);
}

Node* Balance_BST(Node* &root, int start, int end, vector<int> &result){
    if(start > end){
        return nullptr;
    }
    
    int mid = start + (end - start) / 2;
    int data = result[mid];
    
    root = new Node(data);
    
    root->left = Balance_BST(root->left, start, mid-1, result);
    
    root->right = Balance_BST(root->right, mid+1, end, result);
    
    return root;
}

// using preOrder array construct the BST.... 

Node* BST(Node* root, int data){
    if(root == nullptr){
        root = new Node(data);
        return root;
    }
    
    if(data < root->data){
        root->left = BST(root->left, data);
    }
    
    else{
        root->right = BST(root->right, data);
    }
    
    return root;
}

Node* Bst(int pre[], int size) {
    Node* root = nullptr;
    
    for(int i = 0; i < size; i++){
        int data = pre[i];
        root = BST(root, data);
    }
    
    return root;
}


int main(){

}