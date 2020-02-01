#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B&lang=jp"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/flow/primaldual.cpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, f;
    cin >> n >> m >> f;
    PrimalDual<int> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        graph.addEdge(u, v, c, d);
    }
    int ok    = 0;
    lint cost = graph.flow(0, n - 1, f, ok);
    if (!ok)
        cout << -1 << "\n";
    else
        cout << cost << "\n";
    return 0;
}
