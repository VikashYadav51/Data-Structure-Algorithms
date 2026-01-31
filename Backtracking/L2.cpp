#include<iostream>
#include<vector>

using namespace std;

bool isSafe(int row, int col, int n, vector<string > board){
    // row Check...

    for(int j = 0; j < n; j++){
        if(board[row][j] == 'Q'){
            return false;
        }
    }

    // col check...

    for(int i = 0; i < n; i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }


    // diagnoal..check...

    int x = row;
    int y = col;

    while((x >= 0 && x < n ) && (y >= 0 && y < n)){
        if(board[x][y] == 'Q'){
            return false;
        }

        x--;
        y++;
    }


    x = row;
    y = col;

    while((x >= 0 && x < n ) && (y >= 0 && y < n)){
        if(board[x][y] == 'Q'){
            return false;
        }

        x--;
        y--;
    }

    return  true;

}

void insert_N_Queen(int row,  int n, vector<string > board, vector<vector<string> > &ans){
    if(row == n){
        ans.push_back({board});
        return ;
    }

    for(int j = 0; j < n; j++){
        if(isSafe(row, j, n, board)){
            board[row][j] = 'Q';
            insert_N_Queen(row+1, n, board, ans);
            board[row][j] = '.';
        }
    }

    return ;
}


int main(){
    vector<vector<string > > ans;

    int n;
    cout <<"Enter the the value of n "<< endl;
    cin >> n;

    vector<string > board(n, ".");


    insert_N_Queen(0, n, board, ans);

    // return ans;



}