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


# :heavy_check_mark: test/tree/kruskal.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#fbbf052ef5fff5555a3604bb69ffe38a">test/tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/tree/kruskal.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-27 00:53:15+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/library/datastructure/unionfind.cpp.html">library/datastructure/unionfind.cpp</a>
* :heavy_check_mark: <a href="../../../library/library/tree/kruskal.cpp.html">library/tree/kruskal.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/tree/kruskal.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"
#define CXX "g++"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#line 1 "library/datastructure/unionfind.cpp"
struct UnionFind {
    vector<int> rank, parent, size;

    // +1 for 1-indexed nodes
    UnionFind(int n) : rank(n + 1, 0), parent(n + 1), size(n + 1, 1) {
        iota(parent.begin(), parent.end(), 0); // parent is itself
    }
    int root(int x) {
        if (x != parent[x]) {
            parent[x] = root(parent[x]);
        }
        return parent[x];
    }
    bool isSame(int x, int y) { return root(x) == root(y); }
    bool unite(int x, int y) { return link(root(x), root(y)); }
    bool link(int x, int y) {
        if (x == y)
            return false;
        if (rank[x] > rank[y]) {
            parent[y] = x;
            size[x] += size[y];
        } else {
            parent[x] = y;
            size[y] += size[x];
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
        return true;
    }
    int getSize(int x) { return size[root(x)]; }
};
#line 2 "library/tree/kruskal.cpp"

// Kruskal algorithm: build minimum spanning tree
template <typename T>
struct Kruskal {
    struct edge {
        int from, to, used;
        T cost;
        edge(int from_, int to_, T cost_) : from(from_), to(to_), used(0), cost(cost_) {}
        bool operator<(const edge &e) const { return cost < e.cost; }
    };
    vector<edge> es;
    UnionFind uf;
    Kruskal(int n) : uf(n + 1) {}
    void addEdge(int f, int t, T c) { es.emplace_back(f, t, c); }
    T build() {
        sort(es.begin(), es.end());
        T res = 0;
        for (auto &e : es) {
            if (!uf.isSame(e.from, e.to)) {
                res += e.cost;
                uf.unite(e.from, e.to);
                e.used = 1;
            }
        }
        return res;
    }
};
#line 9 "test/tree/kruskal.test.cpp"

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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

