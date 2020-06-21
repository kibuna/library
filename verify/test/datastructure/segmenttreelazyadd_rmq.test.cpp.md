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


# :heavy_check_mark: test/datastructure/segmenttreelazyadd_rmq.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#dd2863e470d2af8ee92181d6e8c27bbc">test/datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/datastructure/segmenttreelazyadd_rmq.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-29 20:59:33+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/library/datastructure/segmenttreelazyadd.cpp.html">library/datastructure/segmenttreelazyadd.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"
#define CXX "g++"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/datastructure/segmenttreelazyadd.cpp"

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    auto f    = [](lint l, lint r) { return min(l, r); };
    auto g    = [](lint l, lint r) { return 1; };
    lint unit = 1LL << 60;
    vector<lint> init(n + 1, 0);
    SegmentTreeLazyAdd<lint> sg(init, f, g, unit);
    for (int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        if (k == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            sg.add(s, t + 1, x);
        } else {
            int s, t;
            cin >> s >> t;
            cout << sg.query(s, t + 1) << "\n";
        }
    }
    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/datastructure/segmenttreelazyadd_rmq.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"
#define CXX "g++"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#line 1 "library/datastructure/segmenttreelazyadd.cpp"
template <typename T = lint>
struct SegmentTreeLazyAdd {
  private:
    using F = function<T(T, T)>;
    using G = function<int(int, int)>;
    int n;
    vector<T> node, lazy, width;
    vector<bool> lazyFlag;
    F func;
    G funcw;
    T unit;

  public:
    SegmentTreeLazyAdd(int sz, F func, G funcw, T unit) : func(func), funcw(funcw), unit(unit) {
        n = 1;
        while (n < sz)
            n *= 2;
        node.assign(2 * n - 1, unit);
        lazy.assign(2 * n - 1, 0);
        lazyFlag.assign(2 * n - 1, false);
        width.assign(2 * n - 1, 1);
        for (int i = n - 2; i >= 0; --i) {
            width[i] = funcw(width[i * 2 + 1], width[i * 2 + 2]);
        }
    }
    SegmentTreeLazyAdd(vector<T> v, F func, G funcw, T unit) : func(func), funcw(funcw), unit(unit) {
        int sz = int(v.size());
        n      = 1;
        while (n < sz)
            n *= 2;
        node.assign(2 * n - 1, unit);
        lazy.assign(2 * n - 1, 0);
        lazyFlag.assign(2 * n - 1, false);
        for (int i = 0; i < sz; i++)
            node[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--)
            node[i] = func(node[i * 2 + 1], node[i * 2 + 2]);
        width.assign(2 * n - 1, 1);
        for (int i = n - 2; i >= 0; --i) {
            width[i] = funcw(width[i * 2 + 1], width[i * 2 + 2]);
        }
    }
    void lazyEvaluate(int k, int l, int r) {
        if (lazyFlag[k]) {
            node[k] += lazy[k] * width[k];
            if (r - l > 1) {
                lazy[k * 2 + 1] += lazy[k];
                lazy[k * 2 + 2] += lazy[k];
                lazyFlag[k * 2 + 1] = lazyFlag[k * 2 + 2] = true;
            }
            lazyFlag[k] = false;
            lazy[k]     = 0;
        }
    }
    // add x to nodes in [a, b)
    void add(int a, int b, T x, int k = 0, int l = 0, int r = -1) {
        if (r < 0)
            r = n;
        lazyEvaluate(k, l, r);
        if (b <= l || r <= a) {
            return;
        }
        if (a <= l && r <= b) {
            lazy[k] += x; // +=
            lazyFlag[k] = true;
            lazyEvaluate(k, l, r);
            return;
        } else {
            const int mid = (l + r) / 2;
            add(a, b, x, k * 2 + 1, l, mid);
            add(a, b, x, k * 2 + 2, mid, r);
            node[k] = func(node[2 * k + 1], node[2 * k + 2]);
        }
    }
    // get func() in [a, b)
    T query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0)
            r = n;
        lazyEvaluate(k, l, r);
        if (b <= l || r <= a)
            return unit;
        if (a <= l && r <= b)
            return node[k];
        T vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return func(vl, vr);
    }
};
#line 9 "test/datastructure/segmenttreelazyadd_rmq.test.cpp"

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    auto f    = [](lint l, lint r) { return min(l, r); };
    auto g    = [](lint l, lint r) { return 1; };
    lint unit = 1LL << 60;
    vector<lint> init(n + 1, 0);
    SegmentTreeLazyAdd<lint> sg(init, f, g, unit);
    for (int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        if (k == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            sg.add(s, t + 1, x);
        } else {
            int s, t;
            cin >> s >> t;
            cout << sg.query(s, t + 1) << "\n";
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

