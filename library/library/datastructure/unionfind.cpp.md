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


# :heavy_check_mark: library/datastructure/unionfind.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#94df14f08811b32e8e383a2a55f0c6c5">library/datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/datastructure/unionfind.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-25 23:38:43+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yosupo/unionfind.test.cpp.html">test/yosupo/unionfind.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct UnionFind {
    vector<int> rank, parent, size;

    // +1 for 1-indexed nodes
    UnionFind(int n) : rank(n + 1, 0), parent(n + 1), size(n + 1, 1) {
        iota(parent.begin(), parent.end(), 0); // parent is itself
    }
    int root(int x) {
        if (x != parent[x]) {
            parent[x] = root(parent[x]);
        }
        return parent[x];
    }
    bool isSame(int x, int y) { return root(x) == root(y); }
    bool unite(int x, int y) { return link(root(x), root(y)); }
    bool link(int x, int y) {
        if (x == y)
            return false;
        if (rank[x] > rank[y]) {
            parent[y] = x;
            size[x] += size[y];
        } else {
            parent[x] = y;
            size[y] += size[x];
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
        return true;
    }
    int getSize(int x) { return size[root(x)]; }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/datastructure/unionfind.cpp"
struct UnionFind {
    vector<int> rank, parent, size;

    // +1 for 1-indexed nodes
    UnionFind(int n) : rank(n + 1, 0), parent(n + 1), size(n + 1, 1) {
        iota(parent.begin(), parent.end(), 0); // parent is itself
    }
    int root(int x) {
        if (x != parent[x]) {
            parent[x] = root(parent[x]);
        }
        return parent[x];
    }
    bool isSame(int x, int y) { return root(x) == root(y); }
    bool unite(int x, int y) { return link(root(x), root(y)); }
    bool link(int x, int y) {
        if (x == y)
            return false;
        if (rank[x] > rank[y]) {
            parent[y] = x;
            size[x] += size[y];
        } else {
            parent[x] = y;
            size[y] += size[x];
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
        return true;
    }
    int getSize(int x) { return size[root(x)]; }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

