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


# :heavy_check_mark: test/flow/primaldual.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/flow/primaldual.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-01 23:15:14+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B&lang=jp">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B&lang=jp</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/library/flow/primaldual.cpp.html">library/flow/primaldual.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B&lang=jp"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/flow/primaldual.cpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, f;
    cin >> n >> m >> f;
    PrimalDual<int> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        graph.addEdge(u, v, c, d);
    }
    int ok    = 0;
    lint cost = graph.flow(0, n - 1, f, ok);
    if (!ok)
        cout << -1 << "\n";
    else
        cout << cost << "\n";
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/flow/primaldual.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B&lang=jp"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#line 1 "test/flow/../../library/flow/primaldual.cpp"
// @see https://ei1333.github.io/luzhiled/snippets/graph/primal-dual.html
template <typename T>
struct PrimalDual {
    struct edge {
        int to;
        T cap, cost;
        int rev;
        edge() {}
        edge(int to, T cap, T cost, int rev) : to(to), cap(cap), cost(cost), rev(rev) {}
    };
    const T inf = numeric_limits<T>::max() / 2;
    vector<vector<edge>> G;
    vector<T> h, dist;
    vector<int> prevv, preve;

    PrimalDual() {}
    PrimalDual(int n) : G(n), h(n), dist(n), prevv(n), preve(n) {}

    void addEdge(int from, int to, T cap, T cost) {
        G[from].emplace_back(to, cap, cost, G[to].size());
        G[to].emplace_back(from, 0, -cost, G[from].size() - 1);
    }

    void dijkstra(int s) {
        struct P {
            T first;
            int second;
            P(T first, int second) : first(first), second(second) {}
            bool operator<(const P &a) const { return first > a.first; }
        };
        priority_queue<P> que;
        fill(dist.begin(), dist.end(), inf);

        dist[s] = 0;
        que.emplace(dist[s], s);
        while (!que.empty()) {
            P p = que.top();
            que.pop();
            int v = p.second;
            if (dist[v] < p.first)
                continue;
            for (int i = 0; i < (int)G[v].size(); i++) {
                edge &e = G[v][i];
                if (e.cap == 0)
                    continue;
                if (dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                    dist[e.to]  = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    que.emplace(dist[e.to], e.to);
                }
            }
        }
    }

    T flow(int s, int t, T f, int &ok) {
        T res = 0;
        fill(h.begin(), h.end(), 0);
        while (f > 0) {
            dijkstra(s);
            if (dist[t] == inf)
                return ok = 0;

            for (int v = 0; v < (int)h.size(); v++)
                h[v] += dist[v];

            T d = f;
            for (int v = t; v != s; v = prevv[v])
                d = min(d, G[prevv[v]][preve[v]].cap);

            f -= d;
            res += d * h[t];
            for (int v = t; v != s; v = prevv[v]) {
                edge &e = G[prevv[v]][preve[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        ok = 1;
        return res;
    }
};
#line 8 "test/flow/primaldual.test.cpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, f;
    cin >> n >> m >> f;
    PrimalDual<int> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        graph.addEdge(u, v, c, d);
    }
    int ok    = 0;
    lint cost = graph.flow(0, n - 1, f, ok);
    if (!ok)
        cout << -1 << "\n";
    else
        cout << cost << "\n";
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

