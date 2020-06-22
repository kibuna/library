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


# :heavy_check_mark: test/graph/stronglyconnectedcomponents.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baa37bfd168b079b758c0db816f7295f">test/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/graph/stronglyconnectedcomponents.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-22 21:13:14+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/library/graph/stronglyconnectedcomponents.cpp.html">library/graph/stronglyconnectedcomponents.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/graph/stronglyconnectedcomponents.cpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        // u--, v--;
        edges[u].emplace_back(v);
    }
    StronglyConnectedComponents scc(edges);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        if (scc[u] == scc[v])
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graph/stronglyconnectedcomponents.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

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
#line 8 "test/graph/stronglyconnectedcomponents.test.cpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        // u--, v--;
        edges[u].emplace_back(v);
    }
    StronglyConnectedComponents scc(edges);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        if (scc[u] == scc[v])
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

