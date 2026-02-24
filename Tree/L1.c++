#include<iostream>
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

    cout <<"Enter the data left side of "<< data << endl;
    root->left = built_tree();

    cout <<"Enter the data right side of "<< data << endl;
    root->right = built_tree();

    return root;

}

void print_LOT(Node* root){
    if(root == nullptr){
        return ;
    }

    queue<Node* > q1;
    q1.push(root);

    while(!q1.empty()){
        int size = q1.size();
        for(int i = 0; i < size; i++){
            Node* temp = q1.front();
            q1.pop();

            cout << temp->data <<",  ";

            if(temp->left){
                q1.push(temp->left);
            }

            if(temp->right){
                q1.push(temp->right);
            }
        }

        cout << endl << endl;
    }

    return ;
}

void print_inorder(Node* root){
    if(root == nullptr){
        return ;
    }

    print_inorder(root->left);
    cout << root->data << ",  ";
    print_inorder(root->right);
}

void print_preorder(Node* root){
    if(root == nullptr){
        return ;
    }

    cout << root->data <<",  ";
    print_preorder(root->left);
    print_preorder(root->right);
}

void print_postorder(Node* root){
    if(root == nullptr){
        return ;
    }

    print_postorder(root->left);
    print_postorder(root->right);
    cout << root->data <<",  ";
}



int main(){
    Node* root = nullptr;
    root = built_tree();

    cout <<"Print the data Level Order Treversal "<< endl;
    print_LOT(root);
    cout << endl << endl;

    cout <<"Print the data inorder "<< endl;
    print_inorder(root);
    cout << endl << endl;

    cout <<"Print the data preorder "<< endl;
    print_preorder(root);
    cout << endl << endl;

    cout <<"Print the data postorder "<< endl;
    print_postorder(root);
    cout << endl << endl; 

}