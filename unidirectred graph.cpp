#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];
bool visited[100];

bool hasCycle(int node, int parent)
{
    visited[node] = true;

    for(int i = 0; i < adj[node].size(); i++)
    {
        int nextnode = adj[node][i];

        // Parent হলে ignore করবো
        if(nextnode == parent)
        {
            continue;
        }

        // Already visited এবং parent না হলে cycle
        if(visited[nextnode] == true)
        {
            return true;
        }

        // DFS দিয়ে সামনে যাই
        bool result = hasCycle(nextnode, node);

        if(result == true)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool cycleFound = false;

    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == false)
        {
            bool result = hasCycle(i, -1);

            if(result == true)
            {
                cycleFound = true;
                break;
            }
        }
    }

    if(cycleFound == true)
    {
        cout << "Cycle exists" << endl;
    }
    else
    {
        cout << "No cycle" << endl;
    }

    return 0;
}