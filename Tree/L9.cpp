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
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* built_tree(){
    int data;
    cout <<"Enter the data "<< endl;
    cin>> data;

    if(data == -1){
        return nullptr;
    }

    Node* root = new Node(data);

    cout <<"Enter the data left side "<< data <<" -> "<< endl;
    root->left = built_tree();

    cout <<"Enter the data right side of "<< data <<" -> "<< endl;
    root->right = built_tree();

    return root;
}

void flatten_tree(Node* &root){
    if(root == nullptr){
        return ;
    }

    if(root->left  == nullptr&& root->right == nullptr){
        return ;
    }
    
    Node* left1 = nullptr;
    if(root->left){
        left1 = root->left;
    }
    
    Node* right1 = nullptr;
    if(root->right){
        right1 = root->right;
    }
    
    root->left = nullptr;
    root->right = nullptr;
    
    root->right = left1;
    
    Node* temp = root;
    
    while(temp->right != nullptr){
        temp = temp->right;
    }
    
    temp->right = right1;
    
    flatten_tree(root->right);
}

void print_tree(Node* root){
    if(root == nullptr){
        return ;
    }

    cout << root->data <<",  ";

    print_tree(root->right);
}

int main(){
    Node* root = nullptr;

    // 1 2 3 -1 -1 4 -1 -1 5 -1 6 -1 -1 
    root = built_tree();

    flatten_tree(root);

    print_tree(root);
}