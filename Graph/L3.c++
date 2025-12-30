#include<iostream>
#include<vector>

using namespace std;

void DFS(int start, vector<bool> &visited, vector<int> &result, vector<int> list[]){
    visited[start] = true;
    result.push_back(start);

    for(auto it : list[start]){
        if(!visited[it]){
            DFS(it, visited, result, list);
        }
    }
}

int main(){
    int n;
    cout <<"Enter the value of n "<< endl;
    cin>> n;

    int m;
    cout <<"Enter the value of m "<< endl;
    cin>> m;

    vector<int> list[n+1];

    for(int i = 0; i < m; i++){
        int u, v;
        cin>> u >> v;

        list[u].push_back(v);
        list[v].push_back(u);

    }

    vector<bool> visited(n+1, 0);
    vector<int> result;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            DFS(i, visited, result, list);
        }
    }

    for(auto it  : result){
        cout << it <<",  ";
    }


}