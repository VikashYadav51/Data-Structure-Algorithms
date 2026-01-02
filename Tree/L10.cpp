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

bool serach_element(Node* root, int target){
    if(root == nullptr){
        return false;
    }

    if(target == root->data){
        return true;
    }

    if(target < root->data){
        bool op1 = serach_element(root->left, target);
    }

    else{
        serach_element(root->right, target);
    }

    return false;
}

bool element_search(Node* root, int target){
    if(root == nullptr){
        return false;
    }

    Node* temp = root;

    while(!temp){
        if(root->data == target){
            return true;
        }

        if(target < root->data){
            temp = temp->left;
        }

        else{
            temp = temp->right;
        }
    }

    return false;
}

int mini_value(Node* root){
    if(root->left == nullptr){
        return root->data;
    }

    return mini_value(root->left);
}

int maxi_value(Node* root){
    if(root->right == nullptr){
        return root->data;
    }
    return maxi_value(root->right);
}

void find_pre_succ(Node* root, int target, int &pre, int &succ){
    if(root == nullptr){
        return ;
    }
    if(target == root->data){
        if(root->left){
            pre = root->left->data;
        }
        if(root->right){
            succ = root->right->data;
        }

        return ;
    }

    succ = root->data;

    if(target < root->data){
        find_pre_succ(root->left, target, pre, succ);
    }

    else{
        find_pre_succ(root->right, target, pre, succ);
    }
}

Node* delete_element(Node* root, int target){
    if(root == nullptr){
        return nullptr;
    }

    if(target == root->data){
        // deletion code....

        // ....Zero child....

        if(root->left == nullptr && root->right == nullptr){
            delete(root);
            return ;
        }

        // one child...left only...or right only exist....
        if(root->left != nullptr && root->right == nullptr){
            Node* newNode = root->left;
            delete(root);
            return newNode;
        }

        if(root->right != nullptr && root->left == nullptr){
            Node* newNode = root->right;
            delete root;
            return newNode;
        }


        // .....both child is exist......
        if(root->left != nullptr && root->right == nullptr){
            
        }



    }

    if(target < root->data){
        root->left = delete_element(root->left, target);
    }

    else{
        root->right = delete_element(root->right, target);
    }

    return ;
}


int main(){
    Node* root = nullptr;

    takeInput(root);

    print_LOT(root);

    // cout << endl << endl;

    // insertion_BST(root, 7);

    // print_LOT(root);

    // cout << endl << endl;

    // cout <<"Minimum value of BST "<< endl;
    // int ans1 = mini_value(root);
    // cout << ans1 << endl;

    // cout <<"maximum value of BST "<< endl;
    // int ans2 = maxi_value(root);
    // cout << ans2 <<  endl ;


    cout << endl << endl;

    int pre = -1;
    int succ = -1;

    int target;
    cout <<"Enter the value of target "<< endl;
    cin>> target;

    find_pre_succ(root, target, pre, succ);

    cout << pre <<",  "<< succ << endl;



}