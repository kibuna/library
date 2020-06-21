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


# :heavy_check_mark: test/datastructure/vertesaddpathsum.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#dd2863e470d2af8ee92181d6e8c27bbc">test/datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/datastructure/vertesaddpathsum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-08 09:34:37+09:00


* see: <a href="https://judge.yosupo.jp/problem/vertex_add_path_sum">https://judge.yosupo.jp/problem/vertex_add_path_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/library/datastructure/hldecomposition.cpp.html">library/datastructure/hldecomposition.cpp</a>
* :heavy_check_mark: <a href="../../../library/library/datastructure/segmenttree.cpp.html">library/datastructure/segmenttree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/datastructure/vertesaddpathsum.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

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
#line 2 "library/datastructure/hldecomposition.cpp"

template <typename T = lint>
class HLDecomposition {
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
    bool built;

  public:
    vector<vector<int>> edges;
    vector<int> vid, head, sub, par, dep, inv, type, out;
    F f;
    T unit;
    SegmentTree<T> segTree;

    HLDecomposition(int n, F f, T unit)
        : built(false), edges(n), vid(n, -1), head(n), sub(n, 1), par(n, -1), dep(n, 0), inv(n), type(n), out(n), f(f),
          unit(unit), segTree(n, f, unit) {}

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
        assert(nodes.size() == vid.size());
        vector<T> v(nodes.size());
        for (int i = 0; i < (int)nodes.size(); ++i) {
            v[vid[i]] = nodes[i];
        }
        segTree = SegmentTree<T>(v, f, unit);
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

    void update(int k, T x) { segTree.update(vid[k], x); }

    // query for each vertex
    // [l, r] <- attention!! closed section (path) on the tree
    T query(int u, int v) {
        assert(built);
        T ret = unit;
        while (1) {
            if (vid[u] > vid[v])
                swap(u, v);
            ret = f(ret, segTree.query(max(vid[u], vid[head[v]]), vid[v] + 1));
            if (head[u] != head[v])
                v = par[head[v]];
            else
                return ret;
        }
    }

    // query for subtree whose root is u
    T query_subtree(int u) {
        assert(built);
        return segTree.query(vid[u], out[u]);
    }

    // query for each edge: exclude lca's value
    // [l, r] <- attention!! closed section (path) on the tree
    T query_edge(int u, int v) {
        assert(built);
        T ret = unit;
        while (1) {
            if (vid[u] > vid[v])
                swap(u, v);
            if (head[u] != head[v]) {
                ret = f(ret, segTree.query(vid[head[v]], vid[v] + 1));
                v   = par[head[v]];
            } else {
                if (u != v)
                    ret = f(ret, segTree.query(vid[u] + 1, vid[v] + 1));
                return ret;
            }
        }
    }
};
#line 8 "test/datastructure/vertesaddpathsum.test.cpp"

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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

