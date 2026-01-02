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

void print_LOT(Node* root){
    if(root == nullptr){
        return ;
    }

    queue<Node* > q1;
    q1.push(root);

    while(!q1.empty()){
        int size = q1.size();

        for(int i = 0; i < size; i++){
            Node* node = q1.front();
            q1.pop();

            cout << node->data <<",  ";

            if(node->left){
                q1.push(node->left);
            }

            if(node->right){
                q1.push(node->right);
            }
        }

        cout << endl ;
    }
}

Node* insertion_BST(Node* root, int element){

    if(root == nullptr){
        root = new Node(element);
        return root;
    }

    if(element < root->data){
        root->left = insertion_BST(root->left, element);
    }

    else{
        root->right = insertion_BST(root->right, element);
    }


}





int main(){
    Node* root = nullptr;

    takeInput(root);

    print_LOT(root);

    cout << endl << endl;

    insertion_BST(root, 7);

    print_LOT(root);

}