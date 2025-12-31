#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Distance of nearest cell having 1

vector<vector<int>> nearest(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    queue<pair<pair<int, int>, int> > q1;
    
    vector<vector<bool> > visited(n, vector<bool>(m, 0));
    
    vector<vector<int> > nums(n, vector<int>(m, 0));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1){
                visited[i][j] = true;
                q1.push({{i, j}, 0});
            }
        }
    }
    
    while(!q1.empty()){
        int row = q1.front().first.first;
        int col = q1.front().first.second;
        int dist = q1.front().second;
        
        q1.pop();
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        int size1 = grid.size();
        int size2 = grid[0].size();
        
        for(int i = 0; i < 4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            
            if(nrow >= 0 && nrow < size1 && ncol >= 0 && ncol < size2){
                if(!visited[nrow][ncol]){
                    q1.push({{nrow, ncol}, dist+1});
                    nums[nrow][ncol] = dist + 1;
                    visited[nrow][ncol] = true;
                }
            }
        }
    }
    
    return nums;
}

int main(){

}