#include <bits/stdc++.h>
using namespace std;

vector<int>adj[100];
bool visited[100];


void dfs(int node){

    visited[node]=true ;

    cout<<node<<" " ;

    for (int i=0 ; i<adj[node].size();i++){

        int nextnode = adj[node][i];

         if(visited[nextnode]==true){

        continue ;//skip
     }

     dfs(nextnode);

    }
    }
    


int main(){
 int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

}

dfs(1);