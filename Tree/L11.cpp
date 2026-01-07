#include<iostream>
#include<vector>
#include<queue>


using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int element){
        this->data = element;
        this->left =nullptr;
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


//   Approach 1 valid BST.....T.C O(N).....SC....O(N)+O(N)....
void calculate_inorder(Node* root, vector<int> &nums){
    if(root == nullptr){
        return ;
    }

    calculate_inorder(root->left, nums);
    nums.push_back(root->data);
    calculate_inorder(root->right, nums);
}
bool isValidBST(Node* root) {
    vector<int> inorder;
    calculate_inorder(root, inorder);

    for(int i = 0; i < inorder.size() - 1; i++){
        if(inorder[i] >= inorder[i+1]){
            return false;
        }
    }
    return true;
}


void k_smallest_element(Node* root, int k, int &count, int &value){
    if(root == nullptr){
        return ;
    }

    k_smallest_element(root->left, k, count, value);
    count++;
    if(count == k){
        value = root->data;
        return ;
    }

    k_smallest_element(root->right, k, count, value);
}

Node* LCA(Node* root, int n1, int n2){
    if(root == nullptr){
        return nullptr;
    }
    
    if((n1 < root->data && n2 > root->data) || (n1 > root->data && n2 < root->data)){
        return root;
    }

    if(n1 < root->data && n2 < root->data){
        return LCA(root->left, n1, n2);
    }

    else{
        return LCA(root->right, n1, n2);
    }
}





int main(){
    Node* root = nullptr;

    takeInput(root);
    cout <<"Print the BST element "<< endl;
    print_LOT(root);
    cout << endl;

    int k;
    cout <<"Enter the value of k "<< endl;
    cin>> k;

    int count =  0;
    int value = -1;

    k_smallest_element(root, k, count, value);
    cout << value;

    return 0;
}