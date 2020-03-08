#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/datastructure/hldecomposition.cpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<lint> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    auto f          = [](lint l, lint r) { return l + r; };
    const lint unit = 0;
    HLDecomposition<lint> tree(n, f, unit);
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        tree.add_edge(i, p);
    }
    tree.build();
    tree.assign(a);
    for (int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        if (k == 0) {
            int u, x;
            cin >> u >> x;
            tree.update(u, tree.query(u, u) + x);
        } else {
            int u;
            cin >> u;
            cout << tree.query_subtree(u) << "\n";
        }
    }
    return 0;
}
