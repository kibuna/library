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


# :heavy_check_mark: library/datastructure/unionfindpotential.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#94df14f08811b32e8e383a2a55f0c6c5">library/datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/datastructure/unionfindpotential.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-29 20:59:58+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/datastructure/potentialunionfind.test.cpp.html">test/datastructure/potentialunionfind.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <class Abel>
struct UnionFindPotential {
    vector<int> parent, rank;
    vector<Abel> diff_weight;

    UnionFindPotential(int n = 1, Abel SUM_UNITY = 0)
        : parent(n + 1), rank(n + 1, 0), diff_weight(n + 1, SUM_UNITY) {
        iota(parent.begin(), parent.end(), 0);
    }
    int root(int x) {
        if (parent[x] == x) {
            return x;
        } else {
            int r = root(parent[x]);
            diff_weight[x] += diff_weight[parent[x]];
            return parent[x] = r;
        }
    }
    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    }
    bool isSame(int x, int y) { return root(x) == root(y); }
    bool unite(int x, int y, Abel w) {
        w += weight(x);
        w -= weight(y);
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        if (rank[x] < rank[y])
            swap(x, y), w = -w;
        if (rank[x] == rank[y])
            ++rank[x];
        parent[y] = x;
        diff_weight[y] = w;
        return true;
    }
    Abel diff(int x, int y) { return weight(y) - weight(x); }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/datastructure/unionfindpotential.cpp"
template <class Abel>
struct UnionFindPotential {
    vector<int> parent, rank;
    vector<Abel> diff_weight;

    UnionFindPotential(int n = 1, Abel SUM_UNITY = 0)
        : parent(n + 1), rank(n + 1, 0), diff_weight(n + 1, SUM_UNITY) {
        iota(parent.begin(), parent.end(), 0);
    }
    int root(int x) {
        if (parent[x] == x) {
            return x;
        } else {
            int r = root(parent[x]);
            diff_weight[x] += diff_weight[parent[x]];
            return parent[x] = r;
        }
    }
    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    }
    bool isSame(int x, int y) { return root(x) == root(y); }
    bool unite(int x, int y, Abel w) {
        w += weight(x);
        w -= weight(y);
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        if (rank[x] < rank[y])
            swap(x, y), w = -w;
        if (rank[x] == rank[y])
            ++rank[x];
        parent[y] = x;
        diff_weight[y] = w;
        return true;
    }
    Abel diff(int x, int y) { return weight(y) - weight(x); }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

