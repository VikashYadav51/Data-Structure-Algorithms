#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void BFS(int start, vector<int> &visited, vector<int> &result, vector<int> adj[]){
    queue<int> q1;
    q1.push(start);
    visited[start] = true;

    while(!q1.empty()){
        int data = q1.front();
        q1.pop();

        result.push_back(data);

        for(auto it : adj[data]){
            if(!visited[it]){
                q1.push(it);
                visited[it] = true;
            }
        }
    }

    return ;
}

int main(){
    int n;
    cout <<"Enter the value of total number of nodes "<< endl;
    cin >> n;

    int m;
    cout <<"Enter the value of total edges "<< endl;
    cin >> m;


    vector<int> adj[n];

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(n, 0);
    vector<int> result;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            BFS(i, visited, result, adj);
        }
    }

    cout <<"Print the element in BFS Order "<< endl;
    for(int i = 0; i < result.size(); i++){
        cout << result[i] <<",  ";
    }

    return 0;
}