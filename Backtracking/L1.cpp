#include<iostream>
#include<vector>

using namespace std;

bool isSafe(int newx, int newy, int n,  vector<vector<int> > matrix, vector<vector<int> > visited){
    if((newx >= 0 && newx < n) && (newy >=0 && newy < n) && (matrix[newx][newy] == 1)  && (visited[newx][newy] == false)){
        return true;
    }

    return false;
}

void solve(int x, int y, int n, vector<vector<int> > matrix, vector<vector<int> > &visited, vector<string> &ans, string path){
    // Base Case........

    if(matrix[x][y] == 0){
        return ;
    }
    
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return ;
    }

    visited[x][y] = true;

    // Downword
    if(isSafe(x+1, y, n, matrix, visited)){
        path.push_back('D');
        solve(x+1, y, n, matrix, visited, ans, path);
    }

    // Left
    if(isSafe(x, y+1, n, matrix, visited)){
        path.push_back('L');
        solve(x+1, y, n, matrix, visited, ans, path);
    }

    // Right
    if(isSafe(x, y-1, n, matrix, visited)){
        path.push_back('R');
        solve(x+1, y, n, matrix, visited, ans, path);
    }

    // upword
    if(isSafe(x-1, y, n, matrix, visited)){
        path.push_back('U');
        solve(x+1, y, n, matrix, visited, ans, path);
    }

    visited[x][y] = false;

    return ;


}

int main(){
    vector<vector<int> > matrix;

    int n;
    cout <<"Enter the value of n "<< endl;
    cin >> n ;

    vector<vector<int> > visited(n, vector<int> (n, 0));

    string path = "";

    vector<string> ans;

    solve(0, 0, n, matrix, visited, ans, path);


    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl << endl;
    }
}

