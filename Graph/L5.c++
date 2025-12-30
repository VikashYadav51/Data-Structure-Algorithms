#include<iostream>
#include<vector>
#include<queue>


using namespace std;

void BFS(int i, int j, vector<vector<bool> > &visited, vector<vector<char > > &grid){
    visited[i][j] = true;
    queue<pair<int, int> > q1;
    q1.push({i, j});
    
    while(!q1.empty()){
        auto temp = q1.front();
        int row = temp.first;
        int col = temp.second;
        
        q1.pop();
        
        int left = col-1;
        int right = col+1;
        int top = row-1;
        int bottom =row+1;
        
        int size1 = grid.size();
        int size2 = grid[0].size();
        
        if(left >= 0 && grid[row][left] == 'L' && !visited[row][left]){
            q1.push({row, left});
            visited[row][left] = true;
        }
        
        if(right < size2 && grid[row][right] == 'L' && !visited[row][right]){
            q1.push({row, right});
            visited[row][right] = true;
        }
        
        if(top >= 0 && grid[top][col] == 'L' && !visited[top][col] ){
            q1.push({top, col});
            visited[top][col] = true;
        }
        
        if(bottom < size1 && grid[bottom][col] == 'L' && !visited[bottom][col]){
            q1.push({bottom , col});
            visited[bottom][col] = true;
        }
        
        if(row-1 >= 0 && col-1 >=0){
            if(grid[row-1][col-1] == 'L' && !visited[row-1][col-1]){
                q1.push({row-1, col-1});
                visited[row-1][col-1] = true;
            }
        }
        
        if(row-1 >= 0 && col+1 < size2){
            if(grid[row-1][col+1] == 'L' && !visited[row-1][col+1]){
                q1.push({row-1, col+1});
                visited[row-1][col+1] = true;
            }
        }
        
        if(row+1 < size1 && col-1 >=0){
            if(grid[row+1][col-1] == 'L' && !visited[row+1][col-1]){
                q1.push({row+1, col-1});
                visited[row+1][col-1] = true;
            }
        }
        
        if(row+1 < size1 && col+1 < size2 ){
            if(grid[row+1][col+1] == 'L' && !visited[row+1][col+1]){
                q1.push({row+1, col+1});
                visited[row+1][col+1] = true;
            }
        }
    }
    
    return ;
}

int countIslands(vector<vector<char>>& grid) {
    int rowSize = grid.size();
    int colSize = grid[0].size();
    
    vector<vector<bool> > visited(rowSize, vector<bool>(colSize, false));
    
    int count = 0;
    for(int i = 0; i < rowSize; i++){
        for(int j = 0; j < colSize; j++){
            if(!visited[i][j] && grid[i][j] == 'L'){
                BFS(i, j, visited, grid);
                count++;
            }
        }
    }
    
    return count;
}

int main(){

}