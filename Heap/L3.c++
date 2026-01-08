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



bool check_heap(Node* root){
    if(root == nullptr){
        return true;
    }
    
    queue<Node*> q1;
    
    q1.push(root);
    bool missing = false;
    
    while(!q1.empty()){
        Node* temp = q1.front();
        q1.pop();
        
        if(temp->left == nullptr && temp->right == nullptr){
            missing = true;
            continue;
        }
        
        if(temp->left!= nullptr && temp->data < temp->left->data  
            || temp->right != nullptr && temp->data < temp->right->data){
            return false;
        }
        
        if(temp->left){
            if(missing){
                return false;
            }
            q1.push(temp->left);
        }
        
        else{
            missing = true;
        }

        if(temp->right){
            if(missing){
                return false;
            }
            q1.push(temp->right);
        }
        
        else{
            missing = true;
        }
        
    }
    
    return true;
}

int main(){

}