#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#define CXX "g++"

#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
using pii      = pair<lint, lint>;
const lint mod = 998244353;

#include "../../library/datastructure/segmenttree.cpp"

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<pii> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    auto f = [](pii l, pii r) {
        lint a = r.first * l.first % mod;
        lint b = (r.first * l.second % mod + r.second) % mod;
        return make_pair(a, b);
    };
    const pii unit = {1, 0};
    SegmentTree<pii> sg(a, f, unit);
    for (int i = 0; i < q; ++i) {
        lint t;
        cin >> t;
        if (t == 1) {
            lint l, r, x;
            cin >> l >> r >> x;
            auto p = sg.query(l, r);
            cout << (p.first * x % mod + p.second) % mod << "\n";
        } else {
            lint p, c, d;
            cin >> p >> c >> d;
            sg.update(p, {c, d});
        }
    }
    return 0;
}