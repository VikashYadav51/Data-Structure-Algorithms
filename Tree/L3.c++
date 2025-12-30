#include<iostream>
#include<queue>
#include<algorithm>
#include<map>

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

void print_zig_zag(Node* root){
    if(root == nullptr){
        return ;
    }

    queue<Node* > q1;
    q1.push(root);

    bool leftToRight = true;

    while(!q1.empty()){
        int size = q1.size();
        vector<int> ans(size);

        for(int i = 0; i < size; i++){
            Node* front = q1.front();
            q1.pop();

            int j = leftToRight ? i : size-i-1;
            ans[j] = front->data;

            if(front->left){
                q1.push(front->left);
            }

            if(front->right){
                q1.push(front->right);
            }
        }

        for(auto it : ans){
            cout << it <<",  ";
        }

        leftToRight = !leftToRight;
    }

    return ;
}

void print_leaf_node(Node* root, vector<int> &ans){
    if(root == nullptr){
        return ;
    }

    if(root->left == nullptr && root->right == nullptr){
        ans.push_back(root->data);
        return ;
    }

    print_leaf_node(root->left, ans);

    print_leaf_node(root->right, ans);

    return;
}

void print_left_node(Node* root, vector<int> &ans){
    if(root == nullptr ){
        return ;
    }

    if(root->left == nullptr && root->right == nullptr){
        return ;
    }

    ans.push_back(root->data);

    if(root->left){
        print_left_node(root->left, ans);
    }
    else{
        print_left_node(root->right, ans);
    }

    return ;
}

void print_right_node(Node* root, vector<int> &ans){
    if(root == nullptr){
        return ;
    }

    if(root->left == nullptr && root->right == nullptr){
        return ;
    }

    ans.push_back(root->data);

    if(root->right){
        print_right_node(root->right, ans);
    }

    else{
        print_right_node(root->left, ans);
    }

    return ;
}



void print_boundary_element(Node* root){
    vector<int> ans;
    ans.push_back(root->data);

    if(root->left){
        print_left_node(root->left, ans);
    }

    if((root != nullptr) || (root->left!= nullptr && root->right != nullptr)){
        print_leaf_node(root, ans);
    }

    vector<int> ans2;

    if(root-> right != nullptr){
        print_right_node(root->right, ans2);
    }

    int size = ans.size();

    for(int i = 0; i < size; i++){
        cout << ans[i]<< ",  ";
    }

    reverse(ans2.begin(), ans2.end());

    for(auto it : ans2){
        cout << it <<",  ";
    }
}

void print_verticalorder(Node* root){
    if(root == nullptr){
        return  ;
    }
    queue<pair<Node*, pair<int, int> > > q1;
    q1.push(make_pair(root, make_pair(0,0)));

    map<int, map<int, vector<int> > > mapping;

    while(!q1.empty()){
        pair<Node*, pair<int, int> > temp = q1.front();
        q1.pop();

        Node* frontNode = temp.first;

        int vd = temp.second.first;
        int hd = temp.second.second;

        mapping[vd][hd].push_back(frontNode->data);

        if(frontNode->left){
            q1.push(make_pair(frontNode->left, make_pair(vd-1, hd+1)));
        }

        if(frontNode->right){
            q1.push(make_pair(root->right, make_pair(vd + 1, hd + 1)));
        }
    }

    return ;
}







int main(){

}