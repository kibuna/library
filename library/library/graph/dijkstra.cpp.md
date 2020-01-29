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


# :heavy_check_mark: library/graph/dijkstra.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c5878b56724fd1eb9362c2254e5c362f">library/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/graph/dijkstra.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-28 21:55:45+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/graph/dijkstra.test.cpp.html">test/graph/dijkstra.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <typename T>
vector<T> dijkstra(int s, vector<vector<pair<int, T>>> &G) {
    const T inf = numeric_limits<T>::max();
    using P     = pair<T, int>;
    int n       = G.size();
    vector<T> d(n, inf);
    priority_queue<P, vector<P>, greater<P>> q;
    d[s] = 0;
    q.emplace(d[s], s);
    while (!q.empty()) {
        P p = q.top();
        q.pop();
        int v = p.second;
        if (d[v] < p.first)
            continue;
        for (auto &e : G[v]) {
            int u = e.first;
            T c   = e.second;
            if (d[u] > d[v] + c) {
                d[u] = d[v] + c;
                q.emplace(d[u], u);
            }
        }
    }
    return d;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/graph/dijkstra.cpp"
template <typename T>
vector<T> dijkstra(int s, vector<vector<pair<int, T>>> &G) {
    const T inf = numeric_limits<T>::max();
    using P     = pair<T, int>;
    int n       = G.size();
    vector<T> d(n, inf);
    priority_queue<P, vector<P>, greater<P>> q;
    d[s] = 0;
    q.emplace(d[s], s);
    while (!q.empty()) {
        P p = q.top();
        q.pop();
        int v = p.second;
        if (d[v] < p.first)
            continue;
        for (auto &e : G[v]) {
            int u = e.first;
            T c   = e.second;
            if (d[u] > d[v] + c) {
                d[u] = d[v] + c;
                q.emplace(d[u], u);
            }
        }
    }
    return d;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

