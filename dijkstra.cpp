#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];

    for (int i = 0; i < m; i++) {

        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);

    int src = 1;
    dist[src] = 0;

    for (int i = 1; i <= n; i++) {

        int u = -1;

        for (int j = 1; j <= n; j++) {

            if (!visited[j] &&
                (u == -1 || dist[j] < dist[u])) {

                u = j;
            }
        }

        if (u == -1 || dist[u] == INF)
            break;

        visited[u] = true;

        for (auto edge : adj[u]) {

            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << " = " << dist[i] << endl;
    }

    return 0;
}
