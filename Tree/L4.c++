#include<iostream>
#include<map>
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

    cout <<"Enter the data right side of "<< data << " -> "<< endl;
    root->right = built_tree();

    return root;
}

pair<int, int> LPS(Node* root){
    if(root == nullptr){
        return make_pair(0,0);
    }

    pair<int, int> left = LPS(root->left);

    pair<int, int> right = LPS(root->right);

    pair<int, int> ans;

    int op1 = left.first;

    int op2 = right.first;

    int op3 = left.second;

    int op4 = right.second;

    if(op1 > op2){
        ans.first = op1 + 1;
        ans.second = root->data + op3;
    }

    else if(op1 == op2){
        ans.first = op1 + 1;
        ans.second = max(op3, op4)  +root->data;
    }

    else{
        ans.first = op2 + 1;
        ans.second = op4 + root->data;
    }

    return ans;
}


bool find_path(Node* root, int n1, vector<int> &result){
    if(root == nullptr){
        return false;
    }

    if(root->data == n1){
        return true;
    }

    result.push_back(root->data);

    if(find_path(root->left, n1, result) || find_path(root->right, n1, result)){
        return true;
    }

    result.pop_back();
    return false;
}

Node* find_LCA(Node* root, int n1, int n2){
    if(root == nullptr){
        return nullptr;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* left = find_LCA(root->left, n1, n2);

    Node* right = find_LCA(root->right, n1, n2);

    if(left != nullptr && right!= nullptr){
        return root;
    }

    else if(left != nullptr && right == nullptr){
        return left;
    }

    else if(left == nullptr && right != nullptr){
        return right;
    }

    else{
        return nullptr;
    }
}


void K_sum_path(Node* root, int &count, vector<int> &result, int value){
    if(root == nullptr){
        return ;
    }

    result.push_back(root->data);

    K_sum_path(root->left, count, result, value);

    K_sum_path(root->right, count, result, value);

    int sum = 0;
    int size = result.size();

    for(int i = size - 1; i>=0; i--){
        sum = sum  + result[i];
        if(sum == value){
            count++;
        }
    }

    result.pop_back();

    return ;
}

Node* K_Ancestor(Node* root, int n1, int &count, int &variable){
    if(root == nullptr){
        return nullptr;
    }

    if(root->data == n1){
        return root;
    }

    Node* left = K_Ancestor(root->left, n1, count, variable);

    Node* right = K_Ancestor(root->right, n1, count, variable);

    if(left){
        count--;
        if(count == 0){
            variable = root->data;
            count = INT32_MAX;
        }
        return root;
    }

    else if(right){
        count--;
        if(count == 0){
            variable = root->data;
            count = INT32_MAX;
        }
        return root;
    }

    else{
        return nullptr;
    }
}





int main(){
    return 0;
}

