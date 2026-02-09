#include<iostream>
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

Node* built_tree(){
    int data;
    cout <<"Enter the data "<< endl;
    cin>> data;

    if(data == -1){
        return nullptr;
    }

    Node* root = new Node(data);

    cout <<"Enter the data left side of "<< data <<" -> "<< endl;
    root->left = built_tree();

    cout <<"Enter the data right side of "<< data << " -> "<< endl;
    root->right = built_tree();

    return root;
    
}

void print_inOrder(Node* root, vector<int> &nums){
    if(root == nullptr){
        return ;
    }

    print_inOrder(root->left, nums);
    // cout << root->data <<",  ";
    nums.push_back(root->data);
    print_inOrder(root->right, nums);
}

Node* construct_tree(Node* &root, int startingIndex, int endingIndex, vector<int> inorder)
    {
    if(startingIndex > endingIndex){
        return nullptr;
    }

    int index = startingIndex + (endingIndex - startingIndex) / 2;
    int element = inorder[index];

    cout << element <<",  ";

    if(root == nullptr){
        root = new Node(element);
    }

    root->left = construct_tree(root->left, startingIndex, index-1, inorder);

    root->right = construct_tree(root->right, index+1, endingIndex, inorder);

    return root;
}

int main(){

}