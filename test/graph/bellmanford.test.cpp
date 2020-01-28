#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=jp"

#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const lint inf = 1LL << 60;

#include "../../library/graph/bellmanford.cpp"

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int v, e, r;
    cin >> v >> e >> r;
    BellmanFord<lint> graph(v);
    for (int i = 0; i < e; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        graph.addEdge(s, t, d);
    }
    graph.build(r);
    if (graph.hasNegativeCycle()) {
        cout << "NEGATIVE CYCLE"
             << "\n";
        return 0;
    }
    for (int i = 0; i < v; ++i) {
        if (graph.dist[i] == graph.inf)
            cout << "INF"
                 << "\n";
        else
            cout << graph.dist[i] << "\n";
    }
    return 0;
}