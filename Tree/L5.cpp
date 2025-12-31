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

    cout <<"Enter the data left side of "<< data << " -> "<< endl;
    root->left = built_tree();

    cout <<"Enter the data right side of "<< data <<" -> "<< endl;
    root->right = built_tree();

    return root;
}

int find_postion(int start, int end, int node, vector<int> inorder){
    for(int i = start; i <= end; i++){
        if(inorder[i] == node){
            return i;
        }
    }

    return -1;
}


Node* construct_tree(int &index, int startingIndex, int endingIndex,  int size, vector<int> preorder, vector<int> inorder){
    if(index >= size || startingIndex > endingIndex){
        return nullptr;
    }


    int data = preorder[index];
    int pos = find_postion(startingIndex, endingIndex, preorder[index], inorder);
    index++;

    Node* root = new Node(data);

    root->left = construct_tree(index, startingIndex, pos-1,size, preorder, inorder);

    root->right = construct_tree(index, pos+1, endingIndex, size, preorder, inorder);

    return root;
}

void print_postOrder(Node* root){
    if(root == nullptr){
        return ;
    }

    print_postOrder(root->left);
    print_postOrder(root->right);
    cout << root->data << ",  ";
}


int main(){
    vector<int> pre;
    pre.push_back(9);
    pre.push_back(3);
    pre.push_back(20);
    pre.push_back(15);
    pre.push_back(7);

    vector<int> in;
    in.push_back(9);
    in.push_back(3);
    in.push_back(15);
    in.push_back(20);
    in.push_back(7);

    int size = 5;

    int startingIndex = 0;
    int endingIndex = size-1;

    int index = 0;

    Node* ans = construct_tree(index, startingIndex, endingIndex, size, pre, in);

    cout<<"Print the data postorder "<< endl;
    print_postOrder(ans);
    cout << endl << endl;
}