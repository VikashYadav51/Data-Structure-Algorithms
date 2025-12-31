#include<iostream>
#include<vector>
#include<queue>
using namespace std;


bool detect_cycle(int start, vector<int> list[], vector<bool> visited){
    visited[start] = true;
    queue<pair <int, int> > q1;
    q1.push({start, -1});

    while(!q1.empty()){
        int child = q1.front().first;
        int parent = q1.front().second;
        q1.pop();

        for(auto it : list[child]){
            if(!visited[it]){
                visited[it] = true;
                q1.push({it, child});
            }

            else if(it != parent){
                return true;
            }
        }
    }

    return false;
}

int main(){

}