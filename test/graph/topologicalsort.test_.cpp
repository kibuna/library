// verified: "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=jp"
// the results are not unique, so (perhaps) it cannot be handled by oj-verify

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/graph/topologicalsort.cpp"

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    int v, e;
    cin >> v >> e;
    TopologicalSort graph(v);
    for (int i = 0; i < e; ++i) {
        int s, t;
        cin >> s >> t;
        graph.addEdge(s, t);
    }
    auto ret = graph.build();
    for (auto &r : ret) {
        cout << r << "\n";
    }
    cout << flush;
    return 0;
}