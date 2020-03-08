#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include <bits/stdc++.h>
using namespace std;
using lint         = long long;
constexpr lint mod = 998244353;

#include "../../library/algebra/mint.cpp"
#include "../../library/datastructure/hldnoncommutative.cpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<pair<mint, mint>> ab;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        ab.emplace_back(a, b);
    }
    using pmm                 = pair<mint, mint>;
    function<pmm(pmm, pmm)> f = [](pmm l, pmm r) {
        return make_pair(r.first * l.first, r.first * l.second + r.second);
    };
    pmm unit = {1, 0};
    HLDNonCommutative<pmm> tree(n, f, unit);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree.add_edge(u, v);
    }
    tree.build();
    tree.assign(ab);
    for (int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        if (k == 0) {
            int p, c, d;
            cin >> p >> c >> d;
            pair<mint, mint> v = {c, d};
            tree.update(p, v);
        } else {
            int u, v, x;
            cin >> u >> v >> x;
            auto z = tree.query(u, v);
            cout << z.first * x + z.second << "\n";
        }
    }
    return 0;
}