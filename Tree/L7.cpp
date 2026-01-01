#include<iostream>
#include<queue>
#include<vector>
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

    cout <<"Enter the data left side of "<< data <<" -> "<< endl;
    root->left = built_tree();

    cout <<"Enter the data right side of "<< data <<" -> "<< endl;
    root->right = built_tree();

    return root;
}

Node* findNode(Node* root, int target){
    if(root == nullptr){
        return nullptr;
    }
    
    if(root->data == target){
        return root;
    }
    
    Node* left = findNode(root->left, target);
    if(left != nullptr){
        return left;
    }
    
    Node*right = findNode(root->right, target);
    if(right != nullptr){
        return right;
    }
    
    return nullptr;
}
    
void child_to_parent(Node* root, map<Node*, Node*> &mapping){
    if(root == nullptr){
        return ;
    }
    
    if(root->left){
        mapping[root->left] = root;
    }
    
    if(root->right){
        mapping[root->right] = root;
    }
    
    
    child_to_parent(root->left, mapping);
    
    child_to_parent(root->right, mapping);
}
    
    
    
int calculateTime(Node* root, map<Node*, Node*> &mapping){
    queue<pair<Node*, int> > q1;
    q1.push({root, 0});
    map<Node*, bool> burn;
    burn[root] = true;
    
    int time = 0;
    
    while(!q1.empty()){
        Node* temp = q1.front().first;
        int t1 = q1.front().second;
        
        q1.pop();
        
        time = max(time, t1);
        // cout <<"time "<< t1 <<"    " << time << endl;
        
        if(temp->left && !burn[temp->left]){
            q1.push({temp->left, t1+1});
            burn[temp->left] = true;
        }
        
        if(temp->right && !burn[temp->right]){
            q1.push({temp->right, t1+1});
            burn[temp->right] = true;
        }
        
        if(mapping.find(temp) != mapping.end()){
            Node* value = mapping[temp];
            if(value != nullptr && !burn[value]){
                burn[value] = true;
                q1.push({value, t1+1});
            }
        }
    }
    // cout << time << endl;
    return time;
}

int minTime(Node* root, int target) {
    map<Node*, Node* > mapping;
    
    child_to_parent(root, mapping);
    
    Node* newroot = findNode(root, target);
    
    int time = calculateTime(newroot, mapping);
    
    return time;
}

int main(){

}