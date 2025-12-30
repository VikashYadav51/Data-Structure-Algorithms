#include<iostream>
#include<map>
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

    cout <<"Enter the data left side of "<< data << " -> "<< endl;
    root->left = built_tree();

    cout <<"Enter the data right side of "<< data << " -> "<< endl;
    root->right = built_tree();

    return root;
}

pair<int, int> LPS(Node* root){
    if(root == nullptr){
        return make_pair(0,0);
    }

    pair<int, int> left = LPS(root->left);

    pair<int, int> right = LPS(root->right);

    pair<int, int> ans;

    int op1 = left.first;

    int op2 = right.first;

    int op3 = left.second;

    int op4 = right.second;

    if(op1 > op2){
        ans.first = op1 + 1;
        ans.second = root->data + op3;
    }

    else if(op1 == op2){
        ans.first = op1 + 1;
        ans.second = max(op3, op4)  +root->data;
    }

    else{
        ans.first = op2 + 1;
        ans.second = op4 + root->data;
    }

    return ans;
}







int main(){
    return 0;
}

