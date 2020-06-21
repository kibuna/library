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


# :heavy_check_mark: test/graph/dijkstrarestore.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baa37bfd168b079b758c0db816f7295f">test/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/graph/dijkstrarestore.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-30 20:35:55+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/library/graph/dijkstrarestore.cpp.html">library/graph/dijkstrarestore.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/graph/dijkstrarestore.cpp"

// TODO: find a testcase for restore_path
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int v, e, r;
    cin >> v >> e >> r;
    vector<vector<pair<int, lint>>> edges(v);
    for (int i = 0; i < e; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        edges[s].emplace_back(t, d);
    }
    Dijkstra graph(edges);
    graph.build(r);
    for (auto &d : graph.dist) {
        if (d == numeric_limits<lint>::max())
            cout << "INF"
                 << "\n";
        else
            cout << d << "\n";
    }
    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graph/dijkstrarestore.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#line 1 "library/graph/dijkstrarestore.cpp"
template <typename T>
struct Dijkstra {
    using P = pair<T, int>;
    int n;
    T inf;
    vector<T> dist;
    vector<int> rev;
    vector<vector<pair<int, T>>> G;

    Dijkstra(vector<vector<pair<int, T>>> &G_) : G(G_) {
        n   = G.size();
        inf = numeric_limits<T>::max();
    }
    void build(int s) {
        dist.clear();
        dist.resize(n, inf);
        rev.clear();
        rev.resize(n, -1);
        priority_queue<P, vector<P>, greater<P>> q;
        dist[s] = 0;
        q.emplace(dist[s], s);
        while (!q.empty()) {
            P p = q.top();
            q.pop();
            int v = p.second;
            if (dist[v] < p.first)
                continue;
            for (auto &e : G[v]) {
                int u = e.first;
                T c   = e.second;
                if (dist[u] > dist[v] + c) {
                    dist[u] = dist[v] + c;
                    rev[u]  = v;
                    q.emplace(dist[u], u);
                }
            }
        }
    }
    vector<int> restore_path(int t) {
        vector<int> path;
        for (; t != -1; t = rev[t])
            path.push_back(t);
        reverse(path.begin(), path.end());
        return path;
    }
};
#line 8 "test/graph/dijkstrarestore.test.cpp"

// TODO: find a testcase for restore_path
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int v, e, r;
    cin >> v >> e >> r;
    vector<vector<pair<int, lint>>> edges(v);
    for (int i = 0; i < e; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        edges[s].emplace_back(t, d);
    }
    Dijkstra graph(edges);
    graph.build(r);
    for (auto &d : graph.dist) {
        if (d == numeric_limits<lint>::max())
            cout << "INF"
                 << "\n";
        else
            cout << d << "\n";
    }
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

