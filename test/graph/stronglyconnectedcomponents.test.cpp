#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/graph/stronglyconnectedcomponents.cpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        // u--, v--;
        edges[u].emplace_back(v);
    }
    StronglyConnectedComponents scc(edges);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        if (scc[u] == scc[v])
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
    return 0;
}