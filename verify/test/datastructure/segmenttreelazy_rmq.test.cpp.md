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


# :heavy_check_mark: test/datastructure/segmenttreelazy_rmq.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/datastructure/segmenttreelazy_rmq.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-29 20:59:07+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/library/datastructure/segmenttreelazy.cpp.html">library/datastructure/segmenttreelazy.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"
#define CXX "g++"

#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const lint inf = (1LL << 31) - 1;

#include "../../library/datastructure/segmenttreelazy.cpp"

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    auto f    = [](lint l, lint r) { return min(l, r); };
    lint unit = inf;
    SegmentTreeLazy<lint> sg(n, f, unit);
    for (int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        if (k == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            sg.update(s, t + 1, x);
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
#line 1 "test/datastructure/segmenttreelazy_rmq.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"
#define CXX "g++"

#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const lint inf = (1LL << 31) - 1;

#line 1 "test/datastructure/../../library/datastructure/segmenttreelazy.cpp"
template <typename T = lint>
struct SegmentTreeLazy {
  private:
    using F = function<T(T, T)>;
    int n;
    vector<T> node, lazy;
    vector<bool> lazyFlag;
    F func;
    T unit;

  public:
    SegmentTreeLazy(int sz, F func, T unit) : func(func), unit(unit) {
        n = 1;
        while (n < sz)
            n *= 2;
        node.assign(2 * n - 1, unit);
        lazy.assign(2 * n - 1, unit);
        lazyFlag.resize(2 * n - 1, false);
    }
    SegmentTreeLazy(vector<T> v, F func, T unit) : func(func), unit(unit) {
        int sz = int(v.size());
        n      = 1;
        while (n < sz)
            n *= 2;
        node.resize(2 * n - 1, unit);
        lazy.resize(2 * n - 1, unit);
        lazyFlag.resize(2 * n - 1, false);

        for (int i = 0; i < sz; i++)
            node[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--)
            node[i] = func(node[i * 2 + 1], node[i * 2 + 2]);
    }
    void lazyEvaluate(int k, int l, int r) {
        if (lazyFlag[k]) {
            node[k] = lazy[k];
            if (r - l > 1) {
                lazy[k * 2 + 1] = lazy[k * 2 + 2] = lazy[k];
                lazyFlag[k * 2 + 1] = lazyFlag[k * 2 + 2] = true;
            }
            lazyFlag[k] = false;
        }
    }
    // replace nodes with x in [a, b)
    void update(int a, int b, T x, int k = 0, int l = 0, int r = -1) {
        if (r < 0)
            r = n;
        lazyEvaluate(k, l, r);
        if (b <= l || r <= a)
            return;
        if (a <= l && r <= b) {
            lazy[k]     = x;
            lazyFlag[k] = true;
            lazyEvaluate(k, l, r);
        } else {
            const int mid = (l + r) / 2;
            update(a, b, x, 2 * k + 1, l, mid);
            update(a, b, x, 2 * k + 2, mid, r);
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
#line 10 "test/datastructure/segmenttreelazy_rmq.test.cpp"

int main() {
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    auto f    = [](lint l, lint r) { return min(l, r); };
    lint unit = inf;
    SegmentTreeLazy<lint> sg(n, f, unit);
    for (int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        if (k == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            sg.update(s, t + 1, x);
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

