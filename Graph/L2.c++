#include<iostream>
#include<vector>
#include<queue>


using namespace std;

void BFS(int start, vector<bool> &visited, vector<int> &result, vector<int> list[]){
    visited[start] = true;
    queue<int> q1;
    q1.push(start);

    while(!q1.empty()){
        int data = q1.front();
        q1.pop();
        result.push_back(data);

        for(auto it : list[start]){
            if(!visited[it]){
                visited[it] = true;
                q1.push(it);
            }
        }
    }

    return ;
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

    vector<bool > visited(n, 0);
    vector<int> result;

    for(int i = 0; i < m; i++){
        if(!visited[i]){
            BFS(i, visited, result, list);
        }
    }

    for(auto it : result){
        cout << it << ",  ";
    }

    

}