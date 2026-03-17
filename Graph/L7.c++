#include<iostream>
#include<vector>
#include<queue>

using namespace std;

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

    vector<vector<int> > visited(n, vector<int>(m, 0));
    
    queue<pair<pair<int, int>, int > > q1;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            q1.push({{i, j}, 0});
        }
    }
    
    int maxiTime = -1;

    while(!q1.empty()){
        int row = q1.front().first.first;
        int col = q1.front().first.second;
        int t1 = q1.front().second;
        q1.pop();

        maxiTime = max(maxiTime, t1);

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        int rowSize = matrix.size();
        int colSize = matrix[0].size();

        for(int i = 0; i < 4; i++){
            int n = row + drow[i];
            int m = col + dcol[i];
            if(n >= 0 && n < rowSize && m >= 0 && m < colSize){
                if(matrix[n][m] == 1 && !visited[n][m]){
                    matrix[n][m] = 2;
                    visited[n][m] = true;
                    q1.push({{n, m}, t1 + 1});
                }
            }
        }
    }

    cout <<"Rotten Orange Algortrithms "<< endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 1){
                return -1;
            }
        }
    }

   cout << maxiTime << endl;
}