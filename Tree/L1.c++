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

    cout <<"Enter the data left side of "<< data <<" -> "<< endl;
    root->left = built_tree();

    cout <<"Enter the data right side of "<< data << " -> "<< endl;
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

            cout << temp->data << ",  ";

            if(temp->left){
                q1.push(temp->left);
            }

            if(temp->right){
                q1.push(temp->right);
            }
        }

        cout << endl;
    }

    return ;
}

void print_inOrder(Node* root){
    if(root == nullptr){
        return ;
    }

    print_inOrder(root->left);
    cout << root->data <<",  ";
    print_inOrder(root->right);
}


void print_preOrder(Node* root){
    if(root == nullptr){
        return ;
    }

    cout << root->data <<",  ";
    print_preOrder(root->left);
    print_preOrder(root->right);
}


void print_postOrder(Node* root){
    if(root == nullptr){
        return ;
    }

    print_postOrder(root->left);
    print_postOrder(root->right);
    cout << root->data <<",  ";
}

int main(){
    Node* root = nullptr;

    root = built_tree();

    cout <<"Print the data LOT ways "<< endl;
    print_LOT(root);
    cout << endl << endl;

    cout <<"Print the data Inorder ways "<< endl;
    print_inOrder(root);
    cout << endl << endl;

    cout << "Print the data PreOrder ways "<< endl;
    print_preOrder(root);
    cout << endl << endl;

    cout <<"Print the data PostOrder ways "<< endl;
    print_postOrder(root);
    cout << endl << endl;

    return 0;
}