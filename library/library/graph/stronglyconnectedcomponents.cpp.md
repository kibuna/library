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


# :heavy_check_mark: library/graph/stronglyconnectedcomponents.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c5878b56724fd1eb9362c2254e5c362f">library/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/graph/stronglyconnectedcomponents.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-22 21:13:14+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/graph/stronglyconnectedcomponents.test.cpp.html">test/graph/stronglyconnectedcomponents.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct StronglyConnectedComponents {
    vector<vector<int>> const &edges_in;
    vector<vector<int>> edges, rev, dag;
    vector<int> comp, order, used;
    vector<vector<int>> cs; // list of nodes in each component
    int ndag;

    StronglyConnectedComponents(vector<vector<int>> const &g)
        : edges_in(g), edges(g.size()), rev(g.size()), comp(g.size(), -1), used(g.size()), cs(g.size()) {
        for (int i = 0; i < (int)edges_in.size(); ++i) {
            for (auto &v : edges_in[i]) {
                edges[i].push_back(v);
                rev[v].push_back(i);
            }
        }
        build();
    }
    int operator[](int k) { return comp[k]; }
    void dfs(int c) {
        if (used[c])
            return;
        used[c] = true;
        for (auto &v : edges[c])
            dfs(v);
        order.push_back(c);
    }
    void rdfs(int c, int cnt) {
        if (comp[c] != -1)
            return;
        comp[c] = cnt;
        cs[cnt].emplace_back(c);
        for (auto &v : rev[c])
            rdfs(v, cnt);
    }
    int build() {
        for (int i = 0; i < (int)edges.size(); ++i)
            dfs(i);
        reverse(order.begin(), order.end());
        ndag = 0;
        for (auto &i : order) {
            if (comp[i] == -1)
                rdfs(i, ndag++);
        }
        cs.resize(ndag);
        dag.resize(ndag);
        for (int i = 0; i < (int)edges_in.size(); ++i) {
            int x = comp[i];
            for (auto &v : edges_in[i]) {
                int y = comp[v];
                if (x == y)
                    continue;
                dag[x].push_back(y);
            }
        }
        return ndag;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/graph/stronglyconnectedcomponents.cpp"
struct StronglyConnectedComponents {
    vector<vector<int>> const &edges_in;
    vector<vector<int>> edges, rev, dag;
    vector<int> comp, order, used;
    vector<vector<int>> cs; // list of nodes in each component
    int ndag;

    StronglyConnectedComponents(vector<vector<int>> const &g)
        : edges_in(g), edges(g.size()), rev(g.size()), comp(g.size(), -1), used(g.size()), cs(g.size()) {
        for (int i = 0; i < (int)edges_in.size(); ++i) {
            for (auto &v : edges_in[i]) {
                edges[i].push_back(v);
                rev[v].push_back(i);
            }
        }
        build();
    }
    int operator[](int k) { return comp[k]; }
    void dfs(int c) {
        if (used[c])
            return;
        used[c] = true;
        for (auto &v : edges[c])
            dfs(v);
        order.push_back(c);
    }
    void rdfs(int c, int cnt) {
        if (comp[c] != -1)
            return;
        comp[c] = cnt;
        cs[cnt].emplace_back(c);
        for (auto &v : rev[c])
            rdfs(v, cnt);
    }
    int build() {
        for (int i = 0; i < (int)edges.size(); ++i)
            dfs(i);
        reverse(order.begin(), order.end());
        ndag = 0;
        for (auto &i : order) {
            if (comp[i] == -1)
                rdfs(i, ndag++);
        }
        cs.resize(ndag);
        dag.resize(ndag);
        for (int i = 0; i < (int)edges_in.size(); ++i) {
            int x = comp[i];
            for (auto &v : edges_in[i]) {
                int y = comp[v];
                if (x == y)
                    continue;
                dag[x].push_back(y);
            }
        }
        return ndag;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

