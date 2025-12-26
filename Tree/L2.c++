#include<iostream>
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

Node* build_tree(){
    int data;
    cout <<"Enter the data "<< endl;
    cin>> data;

    if(data == -1){
        return nullptr;
    }

    Node* root = new Node(data);

    cout << "Enter the data left side of "<< data <<" -> "<< endl;
    root->left = build_tree();

    cout <<"Enter the data right side of "<< data <<" -> "<< endl;
    root->right = build_tree();

    return root;
}

int height(Node* root){
    if(root == nullptr){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    int ans = (left, right) + 1;
    return ans;
}

int Maxi_dia(Node* root){
    if(root == nullptr){
        return 0;
    }

    int left = Maxi_dia(root->left);

    int right = Maxi_dia(root->right);

    int Height = height(root->left) + height(root->right) + 1;

    int ans = max(left, max(right, Height));

    return ans;
}

pair<int, int> maxi_dia(Node* root){
    if(root == nullptr){
        return make_pair(0, 0);
    }

    pair<int, int> left = maxi_dia(root->left);

    pair<int, int> right = maxi_dia(root->right);

    int op1 = left.first;

    int op2 = right.first;

    int op3 = left.second + right.second + 1;

    pair<int, int> ans;

    ans.first = max(op1, max(op2, op3));

    ans.second = max(left.second, right.second) + 1;

    return ans;
}

pair<bool, int> check_balance_tree(Node* root){
    if(root == nullptr){
        return make_pair(true, 0);
    }

    pair<bool, int> left = check_balance_tree(root->left);

    pair<bool, int> right = check_balance_tree(root->right);

    bool op1 = left.first;

    bool op2 = right.first;

    int op3 = abs(left.second - right.second);

    if(op1 && op2 && op3 <= 1){
        return make_pair(true, max(left.second, right.second) + 1);
    }

    else{
        return make_pair(false, max(left.second, right.second)  +1);
    }
}

pair<bool, int> check_sum_tree(Node* root){
    if(root == nullptr){
        return make_pair(true, 0);
    }

    if(root->left == nullptr && root->right == nullptr){
        return make_pair(true, root->data);
    }

    pair<bool, int> left = check_sum_tree(root->left);

    pair<bool, int> right = check_sum_tree(root->right);

    bool op1 = left.first;

    bool op2 = right.first;

    int op3 = (left.second + right.second);

    if(op1 && op2  && root->data  == op3){
        return make_pair(true, 2*root->data);
    }

    else{
        return make_pair(false, 2*root->data);
    }
}



int main(){
    Node* root = nullptr;
    root = build_tree();

    int ans = height(root);
    cout << "Maximum height of tree "<< endl << ans << endl ;

    int dia1 = Maxi_dia(root);
    cout <<"Maximum diameter of tree "<< endl << dia1 << endl;

    pair<int, int> dia2 = maxi_dia(root);
    cout <<"Maximum diamter of tree "<< endl << dia2.first << endl;

    pair<bool, int> check = check_balance_tree(root);
    if(check.first){
        cout <<"Given tree is a balance tree "<< endl;
    }
    else{
        cout <<"Given tree is not a balance tree "<< endl;
    }

    pair<int, int> check2 = check_sum_tree(root);
    if(check2.first){
        cout <<"Given tree is a sum tree "<< endl;
    }
    else{
        cout <<"Given tree is not a sum tree "<< endl;
    }



    return 0;
}