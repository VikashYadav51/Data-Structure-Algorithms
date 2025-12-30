#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void BFS(int sr, int sc, int color, int newcolor, vector<vector<bool> > &visited, vector<vector<int> > &grid){
    visited[sr][sc] = true;
    queue<pair<int, int> > q1;
    q1.push({sr, sc});
    grid[sr][sc] = color;

    while(!q1.empty()){
        int row = q1.front().first;
        int col = q1.front().second;
        q1.pop();

        int left = col-1;
        int right = col+1;
        int top = row-1;
        int bottom =row+1;

        int size1 = grid.size();
        int size2 = grid[0].size();
        
        if(left >= 0 && grid[row][left] == newcolor && !visited[row][left]){
            q1.push({row, left});
            visited[row][left] = true;
            grid[row][left] = color;
        }
        
        if(right < size2 && grid[row][right] == newcolor && !visited[row][right]){
            q1.push({row, right});
            visited[row][right] = true;
            grid[row][right] = color;
        }
        
        if(top >= 0 && grid[top][col] == newcolor && !visited[top][col] ){
            q1.push({top, col});
            visited[top][col] = true;
            grid[top][col] = color;
        }
        
        if(bottom < size1 && grid[bottom][col] == newcolor && !visited[bottom][col]){
            q1.push({bottom , col});
            visited[bottom][col] = true;
            grid[bottom][col] = color;
        }
    }

    return ;
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int newcolor = image[sr][sc];
    int rowsize = image.size();
    int colsize =image[0].size();

    vector<vector<bool> > visited(rowsize, vector<bool>(colsize, 0));

    BFS(sr, sc, color, newcolor, visited, image);

    return image;
}



int main(){

}