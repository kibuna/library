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


# :warning: library/graph/twoedgeconnectedcomponents.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c5878b56724fd1eb9362c2254e5c362f">library/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/graph/twoedgeconnectedcomponents.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 10:20:45+09:00


* see: <a href="https://ei1333.github.io/luzhiled/snippets/graph/two-edge-connected-components.html">https://ei1333.github.io/luzhiled/snippets/graph/two-edge-connected-components.html</a>


## Depends on

* :heavy_check_mark: <a href="lowlink.cpp.html">library/graph/lowlink.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "lowlink.cpp"
// @see https://ei1333.github.io/luzhiled/snippets/graph/two-edge-connected-components.html
struct TwoEdgeConnectedComponents : LowLink {
    int k;
    vector<int> comp;
    vector<vector<int>> bridges;
    TwoEdgeConnectedComponents(const vector<vector<int>> &edges) : LowLink(edges), k(0) { build(); }
    int operator[](const int &k) { return comp[k]; }
    void dfs(int idx, int par, int &k) {
        if (~par && this->ord[par] >= this->low[idx])
            comp[idx] = comp[par];
        else
            comp[idx] = k++;
        for (auto &to : this->edges[idx]) {
            if (comp[to] == -1)
                dfs(to, idx, k);
        }
    }
    void build() {
        comp.assign(this->edges.size(), -1);
        for (int i = 0; i < int(comp.size()); ++i) {
            if (comp[i] == -1)
                dfs(i, -1, k);
        }
        bridges.resize(k);
        for (auto &e : this->bridge) {
            int x = comp[e.first], y = comp[e.second];
            bridges[x].push_back(y);
            bridges[y].push_back(x);
        }
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/graph/lowlink.cpp"
// @see https://ei1333.github.io/luzhiled/snippets/graph/lowlink.html
struct LowLink {
    int n;
    vector<int> used, ord, low, articulation;
    vector<pair<int, int>> bridge;
    vector<vector<int>> edges;
    LowLink(const vector<vector<int>> &edges) : n(edges.size()), used(n, 0), ord(n, 0), low(n, 0), edges(edges) {}

    int dfs(int c, int p, int i) {
        used[c] = true;
        ord[c] = low[c]      = i++;
        bool is_articulation = false;
        int cnt              = 0;
        for (auto &v : edges[c]) {
            if (v == p)
                continue;
            if (!used[v]) {
                cnt++;
                i      = dfs(v, c, i);
                low[c] = min(low[c], low[v]);
                is_articulation |= ~p && low[v] >= ord[c];
                if (ord[c] < low[v])
                    bridge.emplace_back(min(c, v), max(c, v));
            } else {
                low[c] = min(low[c], ord[v]);
            }
        }
        is_articulation |= p == -1 && cnt > 1;
        if (is_articulation)
            articulation.push_back(c);
        return i;
    }
    void build() {
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (!used[i])
                k = dfs(i, -1, k);
        }
    }
};
#line 2 "library/graph/twoedgeconnectedcomponents.cpp"
// @see https://ei1333.github.io/luzhiled/snippets/graph/two-edge-connected-components.html
struct TwoEdgeConnectedComponents : LowLink {
    int k;
    vector<int> comp;
    vector<vector<int>> bridges;
    TwoEdgeConnectedComponents(const vector<vector<int>> &edges) : LowLink(edges), k(0) { build(); }
    int operator[](const int &k) { return comp[k]; }
    void dfs(int idx, int par, int &k) {
        if (~par && this->ord[par] >= this->low[idx])
            comp[idx] = comp[par];
        else
            comp[idx] = k++;
        for (auto &to : this->edges[idx]) {
            if (comp[to] == -1)
                dfs(to, idx, k);
        }
    }
    void build() {
        comp.assign(this->edges.size(), -1);
        for (int i = 0; i < int(comp.size()); ++i) {
            if (comp[i] == -1)
                dfs(i, -1, k);
        }
        bridges.resize(k);
        for (auto &e : this->bridge) {
            int x = comp[e.first], y = comp[e.second];
            bridges[x].push_back(y);
            bridges[y].push_back(x);
        }
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

