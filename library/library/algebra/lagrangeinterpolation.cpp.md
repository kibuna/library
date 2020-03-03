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


# :warning: library/algebra/lagrangeinterpolation.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#26c2ef729e4bca24cf34dda14fedd106">library/algebra</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/algebra/lagrangeinterpolation.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-03 23:33:10+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// O(n^2)
// https://ferin-tech.hatenablog.com/entry/2019/08/11/%E3%83%A9%E3%82%B0%E3%83%A9%E3%83%B3%E3%82%B8%E3%83%A5%E8%A3%9C%E9%96%93

template <typename T>
vector<T> lagrange_interpolation(vector<T> x, vector<T> y) {
    const int n = x.size();
    for (int i = 0; i < n; ++i) {
        T t = 1;
        for (int j = 0; j < n; ++j) {
            if (i != j)
                t *= x[i] - x[j];
        }
        y[i] /= t;
    }
    ll cur = 0, nxt = 1;
    vector<vector<T>> dp(2, vector<T>(n + 1));
    dp[0][0] = -x[0], dp[0][1] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            dp[nxt][j] = dp[cur][j] * -1 * x[i];
            if (j >= 1)
                dp[nxt][j] += dp[cur][j - 1];
        }
        swap(nxt, cur);
    }
    vector<T> xinv(n);
    for (int i = 0; i < n; ++i)
        xinv[i] = T(1) / x[i];
    vector<T> ret(n, 0); // f(x)
    for (int i = 0; i < n; ++i) {
        if (y[i] == 0)
            continue;
        if (x[i] == 0) {
            for (int j = 0; j < n; ++j) {
                ret[j] += dp[cur][j + 1] * y[i];
            }
        } else {
            ret[0] -= dp[cur][0] * xinv[i] * y[i];
            T pre = -dp[cur][0] * xinv[i];
            for (int j = 1; j < n; ++j) {
                ret[j] -= (dp[cur][j] - pre) * xinv[i] * y[i];
                pre = -(dp[cur][j] - pre) * xinv[i];
            }
        }
    }
    return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/algebra/lagrangeinterpolation.cpp"
// O(n^2)
// https://ferin-tech.hatenablog.com/entry/2019/08/11/%E3%83%A9%E3%82%B0%E3%83%A9%E3%83%B3%E3%82%B8%E3%83%A5%E8%A3%9C%E9%96%93

template <typename T>
vector<T> lagrange_interpolation(vector<T> x, vector<T> y) {
    const int n = x.size();
    for (int i = 0; i < n; ++i) {
        T t = 1;
        for (int j = 0; j < n; ++j) {
            if (i != j)
                t *= x[i] - x[j];
        }
        y[i] /= t;
    }
    ll cur = 0, nxt = 1;
    vector<vector<T>> dp(2, vector<T>(n + 1));
    dp[0][0] = -x[0], dp[0][1] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            dp[nxt][j] = dp[cur][j] * -1 * x[i];
            if (j >= 1)
                dp[nxt][j] += dp[cur][j - 1];
        }
        swap(nxt, cur);
    }
    vector<T> xinv(n);
    for (int i = 0; i < n; ++i)
        xinv[i] = T(1) / x[i];
    vector<T> ret(n, 0); // f(x)
    for (int i = 0; i < n; ++i) {
        if (y[i] == 0)
            continue;
        if (x[i] == 0) {
            for (int j = 0; j < n; ++j) {
                ret[j] += dp[cur][j + 1] * y[i];
            }
        } else {
            ret[0] -= dp[cur][0] * xinv[i] * y[i];
            T pre = -dp[cur][0] * xinv[i];
            for (int j = 1; j < n; ++j) {
                ret[j] -= (dp[cur][j] - pre) * xinv[i] * y[i];
                pre = -(dp[cur][j] - pre) * xinv[i];
            }
        }
    }
    return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

