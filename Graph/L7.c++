#include<iostream>
#include<vector>
#include<queue>
 
using namespace std;

// ....Rotten Orange Problems....

int orangesRotting(vector<vector<int>>& grid) {
    queue<pair <pair<int, int> , int> > q1;

    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool> > visited(n, vector<bool> (m, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2){
                q1.push({{i, j}, 0});
                visited[i][j] = true;
            }
        }
    }

    int time = 0;

    while(!q1.empty()){
        int row = q1.front().first.first;
        int col = q1.front().first.second;
        int t1 = q1.front().second;

        time = max(time, t1);

        q1.pop();

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int row1 = row + drow[i];
            int col1 = col  +dcol[i];

            if(row1 >= 0 && row1 < n && col1 >= 0 && col1 < m){
                if(!visited[row1][col1] && grid[row1][col1] == 1){
                    q1.push({{row1, col1}, t1 + 1});
                    visited[row1][col1] = true;
                    grid[row1][col1] = 2;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1){
                return -1;
            }
        }
    }

    return  time;
}

int main(){

}