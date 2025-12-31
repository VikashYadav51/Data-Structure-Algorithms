#include<iostream>
#include<queue>
#include<vector>

using namespace std;


bool check_cycle(int node, int parent,  vector< bool > &visited, vector<int> adj[]){
    visited[node] = true;

    for(auto it : adj[node]){
        if(!visited[it]){
            if(check_cycle(it, node, visited, adj) == true){
                return true;
            }
        }
        else if(it != parent){
            return true;
        }
    }

    return false;



}

int main(){

}