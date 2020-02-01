#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/graph/lowlink.cpp"

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
        edges[v].emplace_back(u);
    }
    LowLink graph(edges);
    graph.build();
    sort(graph.articulation.begin(), graph.articulation.end());
    for (auto &p : graph.articulation) {
        cout << p << "\n";
    }
    return 0;
}