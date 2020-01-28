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


# :heavy_check_mark: library/graph/bellmanford.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c5878b56724fd1eb9362c2254e5c362f">library/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/graph/bellmanford.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-28 21:56:13+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/graph/bellmanford.test.cpp.html">test/graph/bellmanford.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <typename T> // T : type of cost
struct BellmanFord {
    T inf = numeric_limits<T>::max(); // initial value, reused when clear() is called
    int n;                            // number of nodes
    vector<bool> negative;
    vector<T> dist; // distance from start node
    struct edge {
        int from, to;
        T cost;
        edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
    };
    vector<edge> edges;

    BellmanFord(int n) : n(n), negative(n, false), dist(n, inf){};

    // 0-indexed!
    void addEdge(int from, int to, T cost) { edges.emplace_back(from, to, cost); }

    // calculate dist[i] as a shortest distance from start to each node
    void build(int start) {
        dist[start] = 0;
        for (int i = 0; i < n; ++i) {
            for (auto &e : edges) {
                if (dist[e.from] != inf && dist[e.to] > dist[e.from] + e.cost) {
                    dist[e.to] = dist[e.from] + e.cost;
                }
            }
        }
    }

    // check whether there are negative cycles along the path of interest
    bool hasNegativeCycle(int end = -1) {
        for (int i = 0; i < n; ++i) {
            for (auto &e : edges) {
                if (dist[e.from] != inf && dist[e.to] > dist[e.from] + e.cost) {
                    dist[e.to]     = dist[e.from] + e.cost;
                    negative[e.to] = true;
                }
                negative[e.to] = negative[e.to] | negative[e.from];
            }
        }
        if (end != -1)
            return negative[end];
        else {
            bool neg = false;
            for (int i = 0; i < n; ++i) {
                neg = neg | negative[i];
            }
            return neg;
        }
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/graph/bellmanford.cpp"
template <typename T> // T : type of cost
struct BellmanFord {
    T inf = numeric_limits<T>::max(); // initial value, reused when clear() is called
    int n;                            // number of nodes
    vector<bool> negative;
    vector<T> dist; // distance from start node
    struct edge {
        int from, to;
        T cost;
        edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
    };
    vector<edge> edges;

    BellmanFord(int n) : n(n), negative(n, false), dist(n, inf){};

    // 0-indexed!
    void addEdge(int from, int to, T cost) { edges.emplace_back(from, to, cost); }

    // calculate dist[i] as a shortest distance from start to each node
    void build(int start) {
        dist[start] = 0;
        for (int i = 0; i < n; ++i) {
            for (auto &e : edges) {
                if (dist[e.from] != inf && dist[e.to] > dist[e.from] + e.cost) {
                    dist[e.to] = dist[e.from] + e.cost;
                }
            }
        }
    }

    // check whether there are negative cycles along the path of interest
    bool hasNegativeCycle(int end = -1) {
        for (int i = 0; i < n; ++i) {
            for (auto &e : edges) {
                if (dist[e.from] != inf && dist[e.to] > dist[e.from] + e.cost) {
                    dist[e.to]     = dist[e.from] + e.cost;
                    negative[e.to] = true;
                }
                negative[e.to] = negative[e.to] | negative[e.from];
            }
        }
        if (end != -1)
            return negative[end];
        else {
            bool neg = false;
            for (int i = 0; i < n; ++i) {
                neg = neg | negative[i];
            }
            return neg;
        }
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

