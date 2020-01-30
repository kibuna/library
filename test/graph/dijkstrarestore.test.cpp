#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/graph/dijkstrarestore.cpp"

// TODO: find a testcase for restore_path
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int v, e, r;
    cin >> v >> e >> r;
    vector<vector<pair<int, lint>>> edges(v);
    for (int i = 0; i < e; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        edges[s].emplace_back(t, d);
    }
    Dijkstra graph(edges);
    graph.build(r);
    for (auto &d : graph.dist) {
        if (d == numeric_limits<lint>::max())
            cout << "INF"
                 << "\n";
        else
            cout << d << "\n";
    }
    return 0;
}