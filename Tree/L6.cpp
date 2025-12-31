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

int find_position(int startingIndex, int endingIndex, int node, vector<int> &inorder){
    for(int i = startingIndex; i <= endingIndex; i++){
        if(node == inorder[i]){
            return  i;
        }
    }

    return -1;
}

Node* construct_tree(int &index, int startingIndex, int endingIndex, int size, vector<int> postorder, vector<int> inorder){
    if(index < 0 || startingIndex > endingIndex){
        return nullptr;
    }

    int data = postorder[index];
    int pos = find_position(startingIndex, endingIndex, data, inorder);
    index--;

    Node* root = new Node(data);

    root->right = construct_tree(index, pos+1, endingIndex, size, postorder, inorder);

    root->left = construct_tree(index, startingIndex, pos-1,  size, postorder, inorder);

    return root;
}

void print_preorder(Node* root){
    if(root == nullptr){
        return ;
    }

    cout << root->data <<",  ";
    print_preorder(root->left);
    print_preorder(root->right);
}



int main(){
    vector<int> post;
    post.push_back(9);
    post.push_back(3);
    post.push_back(20);
    post.push_back(15);
    post.push_back(7);

    vector<int> in;
    in.push_back(9);
    in.push_back(3);
    in.push_back(15);
    in.push_back(20);
    in.push_back(7);

    int size = 5;

    int startingIndex = 0;
    int endingIndex = size-1;

    int index = size-1;

    Node* ans = construct_tree(index, startingIndex, endingIndex, size, post, in);

    cout <<"Print the data int preorder "<< endl;
    print_preorder(ans);
    cout << endl ;
}