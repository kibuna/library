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


# :heavy_check_mark: test/graph/lowlink_articulation.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/graph/lowlink_articulation.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-01 14:32:37+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/library/graph/lowlink.cpp.html">library/graph/lowlink.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/graph/lowlink.cpp"

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
        edges[v].emplace_back(u);
    }
    LowLink graph(edges);
    graph.build();
    sort(graph.articulation.begin(), graph.articulation.end());
    for (auto &p : graph.articulation) {
        cout << p << "\n";
    }
    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graph/lowlink_articulation.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#line 1 "test/graph/../../library/graph/lowlink.cpp"
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
#line 8 "test/graph/lowlink_articulation.test.cpp"

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
        edges[v].emplace_back(u);
    }
    LowLink graph(edges);
    graph.build();
    sort(graph.articulation.begin(), graph.articulation.end());
    for (auto &p : graph.articulation) {
        cout << p << "\n";
    }
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

