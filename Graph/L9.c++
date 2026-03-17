#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool DFS(int start, int parent, vector<int> &visited, vector<int> list[]){
    visited[start] = true;

    for(auto it : list[start]){
        if(!visited[it]){
            bool ans = DFS(it, start, visited, list);
            if(ans){
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
    int n;
    cout <<"Enter the total number of nodes "<< endl;
    cin >> n;


    int m;
    cout <<"Enter the total number of edges "<< endl;
    cin >> m;

    vector<int> list[n+1];


    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        list[u].push_back(v);
        list[v].push_back(u);
    }

    vector<int> visited(n+1, 0);

    bool ans = false;

    for(int i = 0; i < n+1; i++){
        if(!visited[i]){
            ans = DFS(i, -1, visited, list);
            if(ans){
                break;
            }
        }
    }

    if(ans){
        cout <<"Cycle is persent at given graph "<< endl;
    }

    else{
        cout <<"Cycle is not persent at given graph "<< endl;
    }

    cout <<"Adjancency list are "<< endl;
    for(int i = 0; i < n+1; i++){
        cout << i <<" ->  ";
        for(int j = 0; j < list[i].size(); j++){
            cout << list[i][j] <<",  ";
        }
        cout << endl;
    }

    return 0;
}