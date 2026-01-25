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

pair<int, int> maximum_dia(Node* root){
    if(root == nullptr){
        return make_pair(0,0);
    }

    pair<int, int> left = maximum_dia(root->left);

    pair<int, int> right = maximum_dia(root->right);

    int op1 = left.first;

    int op2 = right.first;

    int op3 = left.second + right.second + 1;

    int op4 = max(op1, max(op2, op3));

    return make_pair(op4, max(left.second, right.second) + 1);
}




int main(){

}