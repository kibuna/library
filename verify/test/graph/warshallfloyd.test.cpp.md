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


# :heavy_check_mark: test/graph/warshallfloyd.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/graph/warshallfloyd.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-27 01:18:09+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=jp">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=jp</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/library/graph/warshallfloyd.cpp.html">library/graph/warshallfloyd.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=jp"

#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const lint inf = 1LL << 60;
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}

#include "../../library/graph/warshallfloyd.cpp"

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int v, e;
    cin >> v >> e;
    vector<vector<lint>> dist(v, vector<lint>(v, inf));
    for (int i = 0; i < v; ++i) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < e; ++i) {
        lint s, t, d;
        cin >> s >> t >> d;
        chmin(dist[s][t], d);
    }
    warshallFloyd<lint, true>(dist, inf);
    bool has_negative_loop = false;
    for (int i = 0; i < v; ++i) {
        if (dist[i][i] < 0) {
            has_negative_loop = true;
            break;
        }
    }
    if (has_negative_loop) {
        cout << "NEGATIVE CYCLE"
             << "\n";
    } else {
        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < v; ++j) {
                if (j != 0)
                    cout << " ";
                if (dist[i][j] == inf)
                    cout << "INF";
                else
                    cout << dist[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/graph/warshallfloyd.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=jp"

#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const lint inf = 1LL << 60;
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}

#line 1 "test/graph/../../library/graph/warshallfloyd.cpp"
// dist is adjacency matrix, no edge = inf
template <typename T, bool has_negative_edge = false>
void warshallFloyd(vector<vector<T>> &dist, T inf) {
    int n = dist.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (has_negative_edge) {
                    if (dist[j][i] != inf && dist[i][k] != inf)
                        chmin(dist[j][k], dist[j][i] + dist[i][k]);
                } else {
                    chmin(dist[j][k], dist[j][i] + dist[i][k]);
                }
            }
        }
    }
}
#line 13 "test/graph/warshallfloyd.test.cpp"

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int v, e;
    cin >> v >> e;
    vector<vector<lint>> dist(v, vector<lint>(v, inf));
    for (int i = 0; i < v; ++i) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < e; ++i) {
        lint s, t, d;
        cin >> s >> t >> d;
        chmin(dist[s][t], d);
    }
    warshallFloyd<lint, true>(dist, inf);
    bool has_negative_loop = false;
    for (int i = 0; i < v; ++i) {
        if (dist[i][i] < 0) {
            has_negative_loop = true;
            break;
        }
    }
    if (has_negative_loop) {
        cout << "NEGATIVE CYCLE"
             << "\n";
    } else {
        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < v; ++j) {
                if (j != 0)
                    cout << " ";
                if (dist[i][j] == inf)
                    cout << "INF";
                else
                    cout << dist[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

