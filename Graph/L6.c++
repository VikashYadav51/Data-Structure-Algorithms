#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// First Method......

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



// Second Method....both the method Approach wil be same but writing of the code is differnent...

int main(){
    
    int n;
    cout <<"Enter the total number of row "<< endl;
    cin >> n;

    int m;
    cout <<"Enter the total number of column "<< endl;
    cin >> m;


    vector<vector<int> > matrix(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    int sr;
    cout <<"Enter the value of sr "<< endl;
    cin >> sr;

    int sc;
    cout <<"Enter the value of sc "<< endl;
    cin >> sc;

    int newColor;
    cout <<"Enter the value of newColor "<< endl;
    cin >> newColor;

    vector<vector<int> > visited(n, vector<int>(m, 0));

    queue<pair<int, int> > q1;

    q1.push({sr, sc});
    visited[sr][sc] = true;
    matrix[sr][sc] = newColor;

    while(!q1.empty()){
        int row = q1.front().first;
        int col = q1.front().second;
        q1.pop();

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        int rowSize = matrix.size();
        int colSize = matrix[0].size();

        for(int i = 0; i < 4; i++){
            int n = row + drow[i];
            int m = col + dcol[i];
            if(n >= 0 && n < rowSize && m >= 0 && m < colSize){
                if(matrix[n][m] == matrix[sr][sc] && !visited[i][m]){
                    matrix[n][m] = newColor;
                    visited[n][m] = true;
                    q1.push({n, m});
                }
            }
        }
    }

    cout <<"Flood fill Algorithms "<< endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << matrix[i][j]<<",  ";
        }
        cout << endl;
    }

    return 0;
}