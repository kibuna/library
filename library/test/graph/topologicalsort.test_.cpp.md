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


# :warning: test/graph/topologicalsort.test_.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#baa37bfd168b079b758c0db816f7295f">test/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/graph/topologicalsort.test_.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-28 22:22:59+09:00




## Depends on

* :warning: <a href="../../library/graph/topologicalsort.cpp.html">library/graph/topologicalsort.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// verified: "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=jp"
// the results are not unique, so (perhaps) it cannot be handled by oj-verify

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/graph/topologicalsort.cpp"

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    int v, e;
    cin >> v >> e;
    TopologicalSort graph(v);
    for (int i = 0; i < e; ++i) {
        int s, t;
        cin >> s >> t;
        graph.addEdge(s, t);
    }
    auto ret = graph.build();
    for (auto &r : ret) {
        cout << r << "\n";
    }
    cout << flush;
    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graph/topologicalsort.test_.cpp"
// verified: "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=jp"
// the results are not unique, so (perhaps) it cannot be handled by oj-verify

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#line 1 "library/graph/topologicalsort.cpp"
// topologically sort the directed graph
// 0-indexed
struct TopologicalSort {
    int n;
    vector<set<int>> G;
    vector<bool> used;
    vector<int> indeg, p;

    TopologicalSort(int size) : n(size), G(n), used(n), indeg(n), p(0) {}

    void addEdge(int s, int t) { G[s].insert(t); }
    void bfs(int s) {
        queue<int> q;
        q.push(s);
        used[s] = 1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            p.push_back(v);
            for (int u : G[v]) {
                indeg[u]--;
                if (indeg[u] == 0 && !used[u]) {
                    used[u] = 1;
                    q.push(u);
                }
            }
        }
    }
    // returns topologically sorted nodes
    // if p.size() < n, the graph cannot be sorted
    vector<int> build() {
        fill(used.begin(), used.end(), 0);
        fill(indeg.begin(), indeg.end(), 0);
        for (int i = 0; i < n; ++i) {
            for (int v : G[i])
                indeg[v]++;
        }
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0 && !used[i])
                bfs(i);
        }
        return p;
    }
};
#line 9 "test/graph/topologicalsort.test_.cpp"

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    int v, e;
    cin >> v >> e;
    TopologicalSort graph(v);
    for (int i = 0; i < e; ++i) {
        int s, t;
        cin >> s >> t;
        graph.addEdge(s, t);
    }
    auto ret = graph.build();
    for (auto &r : ret) {
        cout << r << "\n";
    }
    cout << flush;
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

