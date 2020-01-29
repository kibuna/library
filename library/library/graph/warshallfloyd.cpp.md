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


# :heavy_check_mark: library/graph/warshallfloyd.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c5878b56724fd1eb9362c2254e5c362f">library/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/graph/warshallfloyd.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-27 01:18:09+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/graph/warshallfloyd.test.cpp.html">test/graph/warshallfloyd.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/graph/warshallfloyd.cpp"
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

