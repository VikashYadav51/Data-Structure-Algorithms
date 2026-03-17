#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool BFS(int start, vector<int> &visited, vector<int> list[]){
    queue<pair<int, int> > q1;
    q1.push({start, -1});
    visited[start] = true;

    while(!q1.empty()){
        int data = q1.front().first;
        int parent = q1.front().second;
        q1.pop();

        for(auto it : list[data]){
            if(!visited[it]){
                q1.push({it, data});
                visited[it] = true;
            }

            else if(visited[it] == true && it != parent){
                return true;
            }
        }
    }

    return  false;
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
            ans = BFS(i, visited, list);
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