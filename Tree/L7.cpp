#include<iostream>
#include<queue>
#include<map>
#include<unordered_map>

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
    cin >> data;

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

Node* find_root(Node* root, int n1){
    if(root == nullptr){
        return nullptr;
    }

    if(root->data == n1){
        return root;
    }

    Node* left = find_root(root->left, n1);

    Node* right = find_root(root->right, n1);

    if(left != nullptr){
        return left;
    }

    else if(right != nullptr){
        return right;
    }

    else{
        return nullptr;
    }
}

void mapping_node(Node* root, unordered_map<Node* , Node*> &mapping){
    if(root == nullptr){
        return ;
    }

    if(root->left){
        mapping[root->left] = root;
    }

    if(root->right){
        mapping[root->right] = root;
    }

    mapping_node(root->left, mapping);

    mapping_node(root->right, mapping);

    return ;
}

int totalTime(Node* root, unordered_map<Node*, Node* > mapping){

    queue<Node* > q1;

    q1.push(root);

    int time = 0;

    unordered_map<Node*, bool > visited;
    visited[root] = true;

    while(!q1.empty()){
        Node* temp = q1.front();
        q1.pop();
        bool flag = false;

        if(temp->left){
            if(!visited[temp->left]){
                visited[temp->left] = true;
                q1.push(temp->left);
                flag = true;
            }
        }

        if(temp->right){
            if(!visited[temp->right]){
                visited[temp->right] = true;
                q1.push(temp->right);
                flag = true;
            }
        }

        if(mapping.find(temp) != mapping.end()){
            Node* value = mapping[temp];
            if(value != nullptr && !visited[value]){
                visited[value] = true;
                flag = true;
                q1.push(value);
            }
        }

        if(flag){
            time++;
        }
    }

    return time;

}

int main(){
    Node* root = nullptr;

    root = built_tree();

    int n1 = 1;

    // 1 2 4 -1 -1 5 7 -1 -1 6 -1 -1 3 -1 8 -1 -1

    Node* node = find_root(root, n1);
    if(node == nullptr){
        cout <<" node is not exist..."<< endl;
    }
    else{
        cout << node->data << endl;
    }

    cout << root->data << endl;


    unordered_map<Node*, Node*> mapping;

    mapping_node(root, mapping);

    for(auto it : mapping){
        cout<<"First node "<< it.first->data <<"  Sceond node  "<< it.second->data << endl;
    }

    cout << endl;

    int time = totalTime(node, mapping);
    cout <<"Totla time to burn treee "<< time << endl;
    

}