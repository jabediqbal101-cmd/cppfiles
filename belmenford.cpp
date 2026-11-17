#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge {
    int u, v, w;
};

int main() {
    int n = 4;

    vector<Edge> edges = {
        {1, 2, 4},
        {1, 3, -5},
        {2, 3, -3},
        {3, 4, -2}
    };

    vector<int> dis(n + 1, INF);
    int src = 1;
    dis[src] = 0;

    // Relax all edges n - 1 times.
    for (int i = 1; i <= n - 1; ++i) {
        for (const auto& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;

            if (dis[u] != INF && dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << "Distance of node " << i << " = ";
        if (dis[i] == INF) {
            cout << "INF";
        } else {
            cout << dis[i];
        }
        cout << endl;
    }

    return 0;
}
