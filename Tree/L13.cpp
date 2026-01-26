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

Node* build_tree(){
    int data;
    cout <<"Enter the data "<< endl;
    cin>> data;

    if(data == -1){
        return nullptr;
    }

    Node* root = new Node(data);

    cout << "Enter the data left side of "<< data <<" -> "<< endl;
    root->left = build_tree();

    cout <<"Enter the data right side of "<< data <<" -> "<< endl;
    root->right = build_tree();

    return root;
}

void print_right_node(Node* root){
    if(root == nullptr){
        return ;
    }

    cout << root->data <<",  ";

    if(root->right){
        print_right_node(root->right);
    }

    else{
        print_right_node(root->left);
    }

    return ;
}




int main(){

}