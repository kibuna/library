#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <bits/stdc++.h>
using namespace std;

#include "../../library/datastructure/unionfind.cpp"

signed main() {
    int n, q;
    cin >> n >> q;

    UnionFind uf(n);
    for (int i = 0; i < q; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0)
            uf.unite(u, v);
        if (t == 1)
            cout << uf.isSame(u, v) << "\n";
    }
    cout << flush;
    return 0;
}