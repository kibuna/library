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


# :heavy_check_mark: library/tree/lca.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8a0c4935c26bc3f080e3e86e308b2132">library/tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/tree/lca.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-29 10:16:05+09:00




## Depends on

* :heavy_check_mark: <a href="../datastructure/segmenttree.cpp.html">library/datastructure/segmenttree.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/tree/lca.test.cpp.html">test/tree/lca.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../datastructure/segmenttree.cpp"

// get LCA on the tree
// constructor: n = size of the graph
// addEdge:
// build: after adding all edge, build Euler tour and seg tree
struct LCA {
    int n, k;
    vector<int> depth, eulerTour, firstVisit;
    vector<vector<int>> edges;
    SegmentTree<pair<int, int>> segTree;
    bool isbuilt;
    static pair<int, int> pairComp(pair<int, int> a, pair<int, int> b) {
        if (a.first < b.first)
            return a;
        else
            return b;
    }
    LCA(int n)
        : n(n), k(0), depth(2 * n - 1), eulerTour(2 * n - 1), firstVisit(n), edges(n),
          segTree(2 * n, pairComp, make_pair(numeric_limits<int>::max(), 0)), isbuilt(false){};
    LCA(vector<vector<int>> &edges, int root = 0)
        : n(edges.size()), k(0), depth(2 * n - 1), eulerTour(2 * n - 1), firstVisit(n), edges(edges),
          segTree(2 * n, pairComp, make_pair(numeric_limits<int>::max(), 0)), isbuilt(false) {
        build(root);
    };
    void addEdge(int from, int to) {
        edges[from].push_back(to);
        edges[to].push_back(from);
    }
    void dfs(int curr = 0, int par = -1, int d = 0) {
        firstVisit[curr] = k;
        eulerTour[k]     = curr;
        depth[k++]       = d;
        for (auto &e : edges[curr]) {
            if (e != par) {
                dfs(e, curr, d + 1);
                eulerTour[k] = curr;
                depth[k++]   = d;
            }
        }
    }
    void build(int root = 0) {
        dfs(root);
        for (int i = 0; i < 2 * n - 1; ++i) {
            segTree.update(i, make_pair(depth[i], eulerTour[i]));
        }
        isbuilt = true;
    }
    // return LCA node of l and r
    int operator()(int l, int r) {
        assert(isbuilt);
        int left  = firstVisit[l];
        int right = firstVisit[r];
        if (left > right)
            swap(left, right);
        return segTree.query(left, right + 1).second;
    }
    int getDepth(int k) { return depth[firstVisit[k]]; }
    int dist(int l, int r) { return getDepth(l) + getDepth(r) - 2 * getDepth(operator()(l, r)); }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/datastructure/segmenttree.cpp"
// 0-indexed bottom up Segment Tree
// UNIT is the identity element of operation func
template <typename T = int>
struct SegmentTree {
    using F = function<T(T, T)>;
    int n;
    vector<T> dat;
    F func;
    T UNIT;

    SegmentTree(int n_, F func_, T UNIT_) : func(func_), UNIT(UNIT_) {
        n = 1;
        // full binary tree: num of leaves = n = 2^k >= n_
        while (n < n_)
            n *= 2;
        dat.assign(2 * n - 1, UNIT);
    }
    SegmentTree(vector<T> v_, F func_, T UNIT_) : func(func_), UNIT(UNIT_) {
        n      = 1;
        int nv = v_.size();
        while (n < nv)
            n *= 2;
        dat.assign(2 * n - 1, UNIT);
        for (int i = 0; i < nv; ++i) {
            dat[n - 1 + i] = v_[i];
        }
        for (int i = n - 2; i >= 0; --i) {
            dat[i] = func(dat[2 * i + 1], dat[2 * i + 2]);
        }
    }
    void update(int k, T a) {
        // leaves are at index n-1 to 2*n-2
        k += n - 1;
        dat[k] = a;
        while (k > 0) {
            // k -> parent node
            k = (k - 1) / 2;
            // func(child nodes)
            dat[k] = func(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }
    // get result of func() in [l, r)
    T query(int l, int r) {
        l += n - 1;
        r += n - 1;
        T retl = UNIT, retr = UNIT;
        while (l < r) {
            if ((l & 1) == 0)
                retl = func(retl, dat[l]);
            if ((r & 1) == 0)
                retr = func(dat[r - 1], retr);
            l = l / 2;
            r = (r - 1) / 2;
        }
        return func(retl, retr);
    }
};
#line 2 "library/tree/lca.cpp"

// get LCA on the tree
// constructor: n = size of the graph
// addEdge:
// build: after adding all edge, build Euler tour and seg tree
struct LCA {
    int n, k;
    vector<int> depth, eulerTour, firstVisit;
    vector<vector<int>> edges;
    SegmentTree<pair<int, int>> segTree;
    bool isbuilt;
    static pair<int, int> pairComp(pair<int, int> a, pair<int, int> b) {
        if (a.first < b.first)
            return a;
        else
            return b;
    }
    LCA(int n)
        : n(n), k(0), depth(2 * n - 1), eulerTour(2 * n - 1), firstVisit(n), edges(n),
          segTree(2 * n, pairComp, make_pair(numeric_limits<int>::max(), 0)), isbuilt(false){};
    LCA(vector<vector<int>> &edges, int root = 0)
        : n(edges.size()), k(0), depth(2 * n - 1), eulerTour(2 * n - 1), firstVisit(n), edges(edges),
          segTree(2 * n, pairComp, make_pair(numeric_limits<int>::max(), 0)), isbuilt(false) {
        build(root);
    };
    void addEdge(int from, int to) {
        edges[from].push_back(to);
        edges[to].push_back(from);
    }
    void dfs(int curr = 0, int par = -1, int d = 0) {
        firstVisit[curr] = k;
        eulerTour[k]     = curr;
        depth[k++]       = d;
        for (auto &e : edges[curr]) {
            if (e != par) {
                dfs(e, curr, d + 1);
                eulerTour[k] = curr;
                depth[k++]   = d;
            }
        }
    }
    void build(int root = 0) {
        dfs(root);
        for (int i = 0; i < 2 * n - 1; ++i) {
            segTree.update(i, make_pair(depth[i], eulerTour[i]));
        }
        isbuilt = true;
    }
    // return LCA node of l and r
    int operator()(int l, int r) {
        assert(isbuilt);
        int left  = firstVisit[l];
        int right = firstVisit[r];
        if (left > right)
            swap(left, right);
        return segTree.query(left, right + 1).second;
    }
    int getDepth(int k) { return depth[firstVisit[k]]; }
    int dist(int l, int r) { return getDepth(l) + getDepth(r) - 2 * getDepth(operator()(l, r)); }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

