#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"
#define CXX "g++"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/tree/kruskal.cpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int v, e;
    cin >> v >> e;
    Kruskal<int> tr(v);
    for (int i = 0; i < e; ++i) {
        int s, t, w;
        cin >> s >> t >> w;
        tr.addEdge(s, t, w);
    }
    cout << tr.build() << "\n";
    return 0;
}