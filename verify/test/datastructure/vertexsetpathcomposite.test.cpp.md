---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/datastructure/vertexsetpathcomposite.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#dd2863e470d2af8ee92181d6e8c27bbc">test/datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/datastructure/vertexsetpathcomposite.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-21 13:48:11+09:00


* see: <a href="https://judge.yosupo.jp/problem/vertex_set_path_composite">https://judge.yosupo.jp/problem/vertex_set_path_composite</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/library/algebra/mint.cpp.html">library/algebra/mint.cpp</a>
* :heavy_check_mark: <a href="../../../library/library/datastructure/hldnoncommutative.cpp.html">library/datastructure/hldnoncommutative.cpp</a>
* :heavy_check_mark: <a href="../../../library/library/datastructure/segmenttree.cpp.html">library/datastructure/segmenttree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/datastructure/vertexsetpathcomposite.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include <bits/stdc++.h>
using namespace std;
using lint         = long long;
constexpr lint mod = 998244353;

#line 1 "library/algebra/mint.cpp"
template <lint mod>
struct modint {
    lint v;
    constexpr modint(lint t = 0) noexcept {
        v = t % mod;
        if (v < 0)
            v += mod;
    }
    constexpr modint pow(lint k) noexcept {
        modint res(1), tmp(v);
        while (k) {
            if (k & 1)
                res *= tmp;
            tmp *= tmp;
            k >>= 1;
        }
        return res;
    }
    static modint add_identity() { return modint(0); }
    static modint mul_identity() { return modint(1); }
    constexpr modint inv() { return pow(mod - 2); }

    constexpr modint &operator+=(const modint a) noexcept {
        v += a.v;
        if (v >= mod)
            v -= mod;
        return *this;
    }
    constexpr modint &operator-=(const modint a) noexcept {
        v += mod - a.v;
        if (v >= mod)
            v -= mod;
        return *this;
    }
    constexpr modint &operator*=(const modint a) noexcept {
        v = v * a.v % mod;
        return *this;
    }
    constexpr modint &operator/=(const modint a) noexcept { return (*this) *= a.inv(); }

    constexpr modint operator+(const modint a) const noexcept { return modint(v) += a; };
    constexpr modint operator-(const modint a) const noexcept { return modint(v) -= a; };
    constexpr modint operator*(const modint a) const noexcept { return modint(v) *= a; };
    constexpr modint operator/(const modint a) const noexcept { return modint(v) /= a; };
    constexpr modint operator-() const noexcept { return v ? modint(mod - v) : modint(v); }

    constexpr bool operator==(const modint a) const noexcept { return v == a.v; }
    constexpr bool operator!=(const modint a) const noexcept { return v != a.v; }
    constexpr bool operator<(const modint a) const noexcept { return v < a.v; }
};
using mint = modint<mod>;
ostream &operator<<(ostream &os, mint m) { return os << m.v; }
#line 1 "library/datastructure/segmenttree.cpp"
// 0-indexed bottom up Segment Tree
// UNIT is the identity element of operation func
template <typename T = int>
struct SegmentTree {
    using F = function<T(T, T)>;
    int n;
    vector<T> dat;
    F func;
    T UNIT;

    SegmentTree(int n_, F func_, T UNIT_) : func(func_), UNIT(UNIT_) {
        n = 1;
        // full binary tree: num of leaves = n = 2^k >= n_
        while (n < n_)
            n *= 2;
        dat.assign(2 * n - 1, UNIT);
    }
    SegmentTree(vector<T> v_, F func_, T UNIT_) : func(func_), UNIT(UNIT_) {
        n      = 1;
        int nv = v_.size();
        while (n < nv)
            n *= 2;
        dat.assign(2 * n - 1, UNIT);
        for (int i = 0; i < nv; ++i) {
            dat[n - 1 + i] = v_[i];
        }
        for (int i = n - 2; i >= 0; --i) {
            dat[i] = func(dat[2 * i + 1], dat[2 * i + 2]);
        }
    }
    void update(int k, T a) {
        // leaves are at index n-1 to 2*n-2
        k += n - 1;
        dat[k] = a;
        while (k > 0) {
            // k -> parent node
            k = (k - 1) / 2;
            // func(child nodes)
            dat[k] = func(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }
    // get result of func() in [l, r)
    T query(int l, int r) {
        l += n - 1;
        r += n - 1;
        T retl = UNIT, retr = UNIT;
        while (l < r) {
            if ((l & 1) == 0)
                retl = func(retl, dat[l]);
            if ((r & 1) == 0)
                retr = func(dat[r - 1], retr);
            l = l / 2;
            r = (r - 1) / 2;
        }
        return func(retl, retr);
    }
};
#line 2 "library/datastructure/hldnoncommutative.cpp"

template <typename T>
class HLDNonCommutative {
    using F = function<T(T, T)>;
    void dfs_sz(int v) {
        for (int &u : edges[v])
            if (u == par[v])
                swap(u, edges[v].back());
        if (~par[v])
            edges[v].pop_back();

        for (int &u : edges[v]) {
            par[u] = v;
            dep[u] = dep[v] + 1;
            dfs_sz(u);
            sub[v] += sub[u];
            if (sub[u] > sub[edges[v][0]])
                swap(u, edges[v][0]);
        }
    }
    void dfs_hld(int v, int c, int &pos) {
        vid[v]      = pos++;
        inv[vid[v]] = v;
        type[v]     = c;
        for (int u : edges[v]) {
            if (u == par[v])
                continue;
            head[u] = (u == edges[v][0] ? head[v] : u);
            dfs_hld(u, c, pos);
        }
        out[v] = pos;
    }

  public:
    bool built;
    int n;
    vector<vector<int>> edges;
    vector<int> vid, head, sub, par, dep, inv, type, out;
    F f;
    T unit;
    SegmentTree<T> segTree, segTreeRev;

    HLDNonCommutative(int n, F f, T unit)
        : built(false), n(n), edges(n), vid(n, -1), head(n), sub(n, 1), par(n, -1), dep(n, 0), inv(n), type(n), out(n),
          f(f), unit(unit), segTree(n, f, unit), segTreeRev(n, f, unit) {}

    void add_edge(int u, int v) {
        edges[u].emplace_back(v);
        edges[v].emplace_back(u);
    }

    void build(vector<int> rs = {0}) {
        int c = 0, pos = 0;
        for (int r : rs) {
            dfs_sz(r);
            head[r] = r;
            dfs_hld(r, c++, pos);
        }
        built = true;
    }

    void assign(vector<T> nodes) {
        assert((int)nodes.size() == n);
        vector<T> v(n);
        for (int i = 0; i < n; ++i) {
            v[vid[i]] = nodes[i];
        }
        segTree = SegmentTree<T>(v, f, unit);
        reverse(v.begin(), v.end());
        segTreeRev = SegmentTree<T>(v, f, unit);
    }

    int lca(int u, int v) {
        assert(built);
        while (1) {
            if (vid[u] > vid[v])
                swap(u, v);
            if (head[u] == head[v])
                return u;
            v = par[head[v]];
        }
    }

    int distance(int u, int v) { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }

    void update(int k, T x) {
        segTree.update(vid[k], x);
        segTreeRev.update(n - 1 - vid[k], x);
    }

    // query for each vertex
    // [l, r] <- attention!! closed section (path) on the tree
    T query(int u, int v) {
        assert(built);
        T retr = unit, retl = unit;
        int p = lca(u, v);
        while (1) {
            if (head[p] != head[v]) {
                retr = f(segTree.query(vid[head[v]], vid[v] + 1), retr);
                v    = par[head[v]];
            } else {
                retr = f(segTree.query(vid[p], vid[v] + 1), retr);
                break;
            }
        }
        while (1) {
            if (head[p] != head[u]) {
                retl = f(retl, segTreeRev.query(n - 1 - vid[u], n - 1 - vid[head[u]] + 1));
                u    = par[head[u]];
            } else {
                retl = f(retl, segTreeRev.query(n - 1 - vid[u], n - 1 - vid[p]));
                break;
            }
        }
        return f(retl, retr);
    }
};
#line 10 "test/datastructure/vertexsetpathcomposite.test.cpp"

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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

