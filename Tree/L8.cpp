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

Node* find_pre(Node* root){
    Node* temp = root;
    temp = temp->left;

    while(temp->right != nullptr && temp->right != root){
        temp = temp->right;
    }

    return temp;
}

void morrish_treversal(Node* root){
    if(root == nullptr){
        return ;
    }

    Node* curr = root;

    while(curr != nullptr){
        if(curr->left == nullptr){
            cout << curr->data <<",  ";
            curr = curr->right;
        }

        else{
            Node* pre = find_pre(curr);

            if(pre->right == nullptr){
                pre->right = curr;
                curr = curr->left;
            }

            else{
                pre->right = nullptr;
                cout << curr->data <<",  ";
                curr = curr->right;
            }
        }
    }

    return ;
}

int main(){
    Node* root = nullptr;

    // 1 2 4 -1  7 -1 -1 5 -1 -1 3 -1 6 -1 -1
    root = built_tree();

    morrish_treversal(root);

}