#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=jp"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/flow/dinic.cpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int v, e;
    cin >> v >> e;
    Dinic<lint, true> graph(v);
    for (int i = 0; i < e; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        graph.addEdge(u, v, c);
    }
    cout << graph.maxFlow(0, v - 1) << "\n";
    return 0;
}