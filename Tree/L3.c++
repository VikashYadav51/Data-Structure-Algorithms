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
    int data ;
    cout<<"Enter the data "<< endl;
    cin>> data;

    if(data == -1){
        return nullptr;
    }

    Node* root = new Node(data);

    cout << "Enter the data left side of "<< data <<" -> "<< endl;
    root->left = built_tree();

    cout <<"Enter the data right side of "<< data <<" -> "<< endl;
    root->right = built_tree();

    return root;
}

void print_zig_zag(Node* root){
    queue<Node* > q1;
    q1.push(root);
    bool leftToRight = true;

    while(!q1.empty()){
        int size = q1.size();
        vector<int> ans;
        for(int i = 0; i < size; i++){
            Node* temp = q1.front();
            q1.pop();

            int j = leftToRight ? i : size - i - 1;
            ans[i] = temp->data;

            if(temp->left){
                q1.push(temp->left);
            }

            if(temp->right){
                q1.push(temp->right);
            }
        }

        leftToRight = !leftToRight;

        for(auto it : ans){
            cout << it <<",  ";
        }
    }

    return ;
}

int main(){
    return 0;
}