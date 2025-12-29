#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cout<<"Enter the total number of nodes "<< endl;
    cin>> n;

    int m;
    cout <<"Enter the total number of egges "<< endl;
    cin>> m;

    /*  store Graph data in adjancency matrix.....SC..O(n2)...
        vector<vector<int>> matrix(n+1, vector<int>(n+1, 0));

        for(int i = 0; i < m; i++){
            int u, v;
            cin>> u >> v;

            matrix[u][v] = 1;
            matrix[v][u] = 1;
        }

        cout <<"Nodes are in the graph.... "<< endl;

        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < n+1; j++){
                cout << matrix[i][j]<<",  ";
            }

            cout << endl ;
        }

    */


    //  Store graph data in adjancey list...

    /*

        vector<int> list[n+1];

        for(int i = 0; i < m; i++){
            int u, v;
            cin>> u >> v;

            list[u].push_back(v);
            list[v].push_back(u);
        }

        for(int i = 1; i <= n; i++){
            cout << i <<" --> ";

            for(int j = 0; j < list[i].size(); j++){
                cout << list[i][j] <<", ";
            }

            cout << endl;
        }
    */


    

    return 0;
}