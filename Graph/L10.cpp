#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(){
    int n;
    cout <<"Enter the value of n "<< endl;
    cin >> n;

    int m;
    cout <<"Enter the value of m "<< endl;
    cin >> m;

    vector<vector<int> > matrix(n, vector<int> (m, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j] ;
        }
    }

    queue<pair< pair<int, int>, int> > q1;
    vector<vector<int> > visited(n, vector<int> (m, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 1){
                q1.push({{i, j}, 0});
                visited[i][j] = true;
                matrix[i][j] = 0;
            }
        }
    }

    while(!q1.empty()){
        int row = q1.front().first.first;
        int col = q1.front().first.second;
        int dist = q1.front().second;

        q1.pop();

        int drwo[] = {};
        int dcol[] = {};

        int rowSize = matrix.size();
        int colSize = matrix[0].size();

        for(int i = 0; i < 4; i++){
            int n = row + i;
            int m = row + i;

            if(n >= 0 && n < rowSize && m >= 0 && m < colSize && !visited[n][m] ){
                q1.push({{n, m}, dist+1});
                visited[n][m] = true;
                matrix[n][m] = dist + 1;
            }
        }
    }

    return 0;
}