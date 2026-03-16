#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout <<"Enter the value of total number of nodes "<< endl;
    cin >> n;

    int m;
    cout <<"Enter the value of total edges "<< endl;
    cin >> m;

    /* First method to store the graph in matrix formate................
        vector<vector<int> > matrix(n, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            matrix[u][v] = 1;
            matrix[v][u] = 1;
        }

        cout <<"Graph data are stored in matrix formate "<< endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << matrix[i][j] <<",  ";
            }
            cout << endl;
        }
    */


    /*Store the graph in adjancency list........
        vector<int> adj[n];

        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout <<"Print the graph data in store in adjancency "<< endl;

        for(int i = 0; i < n; i++){
            cout << i <<"  -> ";
            for(int j = 0; j < adj[i].size(); j++){
                cout << adj[i][j] << ",  ";
            }
            cout <<endl;
        }

    */



    /* Store the weighted graph in adjancency list
        vector<pair<int, int> > list[n];

        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;

            list[u].push_back({v, w});
            list[v].push_back({u, w});
        }

        for(int i = 0; i < n; i++){
            cout << i << " ->  ";
            for(int j = 0; j < list[i].size(); j++){
                cout <<" ( "<< list[i][j].first <<",  "<< list[i][j].second << " ),  ";
            }
            cout << endl;
        }

    */
    
}