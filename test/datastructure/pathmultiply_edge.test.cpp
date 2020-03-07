#define PROBLEM "https://www.hackerrank.com/contests/yfkpo3-1/challenges/bananas-multiplier-hard"

#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const lint mod = 1e9 + 7;

#include "../../library/algebra/mint.cpp"
#include "../../library/datastructure/hldecomposition.cpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    auto f    = [](mint l, mint r) { return l * r; };
    mint unit = 1;
    HLDecomposition<mint> tree(n, f, unit);
    vector<vector<pair<int, lint>>> edges(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        lint w;
        cin >> u >> v >> w;
        u--, v--;
        edges[u].emplace_back(v, w);
        edges[v].emplace_back(u, w);
        tree.add_edge(u, v);
    }
    tree.build();
    vector<mint> cs(n, unit);
    function<void(int, int)> dfs = [&](int c, int p) {
        for (auto &v : edges[c]) {
            if (v.first == p)
                continue;
            cs[v.first] = v.second;
            dfs(v.first, c);
        }
    };
    dfs(0, -1);
    tree.assign(cs);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int m, p, x;
        cin >> m >> p >> x;
        m--, p--;
        mint ret = tree.query_edge(m, p) * x;
        cout << ret << "\n";
    }
    return 0;
}