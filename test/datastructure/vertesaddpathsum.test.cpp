#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

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
    auto f    = [](lint l, lint r) { return l + r; };
    lint unit = 0;
    HLDecomposition<lint> tree(n, f, unit);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree.add_edge(u, v);
    }
    tree.build();
    tree.assign(a);
    for (int i = 0; i < q; ++i) {
        lint k, u, v;
        cin >> k >> u >> v;
        if (k == 0) {
            v += tree.query(u, u);
            tree.update(u, v);
        } else if (k == 1) {
            cout << tree.query(u, v) << "\n";
        }
    }
    return 0;
}