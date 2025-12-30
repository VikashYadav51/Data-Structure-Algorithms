#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void BFS(int start, vector<bool> &visited, vector<vector<int> > adj){
    visited[start] = true;
    queue<int> q1;
    q1.push(start);
    
    while(!q1.empty()){
        int data = q1.front();
        q1.pop();
        
        int size = adj[data].size();
        for(int it = 0; it < size; it++ ){
            if(!visited[it] && it != data &&  adj[data][it] == 1){
                q1.push(it);
                visited[it] = true;
            }
        }
    }


}

int numProvinces(vector<vector<int>> adj, int V) {
    int size = adj.size();
    vector<bool > visited(size, 0);
    
    int count  = 0;
    for(int i = 0; i < size; i++){
        if(!visited[i]){
            BFS(i, visited, adj);
            count++;
        }
    }
    return count;
}
    

int main(){

}