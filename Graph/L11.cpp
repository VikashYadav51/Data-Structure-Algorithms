#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// Topological sorting 

void DFS(int start, vector<bool> &visited, vector<int> adj[], stack<int> &s1){
    visited[start] = true;
    
    for(auto it : adj[start]){
        if(!visited[it]){
            DFS(it, visited, adj, s1);
        }
    }
    
    s1.push(start);
    
    return ;
}


vector<int> topoSort(int V, vector<vector<int>>& edges) {
    int size = edges.size();
    
    vector<int> adj[V];
    
    for(int i = 0; i < size; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    
    vector<bool> visited(V, 0);
    
    stack<int> s1;
    
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            DFS(i, visited, adj, s1);
        }
    }
    
    
    vector<int> result;
    
    while(!s1.empty()){
        result.push_back(s1.top());
        s1.pop();
    }
    
    return result;
    
}

int main(){

}