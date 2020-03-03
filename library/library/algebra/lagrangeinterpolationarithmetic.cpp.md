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


# :warning: library/algebra/lagrangeinterpolationarithmetic.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#26c2ef729e4bca24cf34dda14fedd106">library/algebra</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/algebra/lagrangeinterpolationarithmetic.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-03 23:33:10+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// fast polynomial interpolation for arithmetic sequence O(n log mod)
// x_i = a + i*d : y_i, 0<=i<=n
template <typename T>
T LagrangeInterpolationArithmetic(T a, T d, vector<T> y, T x) {
    const lint n = y.size() - 1;
    T ret = 0, ft = 1;
    for (int i = 0; i < n + 1; ++i) {
        ft *= x - (a + d * i);
    }
    T f = 1;
    for (int i = 1; i < n + 1; ++i) {
        f *= -d * i;
    }
    ret += y[0] / f * ft / (x - a);
    for (int i = 0; i < n; ++i) {
        f *= d * (i + 1) / (d * (i - n));
        ret += y[i + 1] / f * ft / (x - a - d * (i + 1));
    }
    return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/algebra/lagrangeinterpolationarithmetic.cpp"
// fast polynomial interpolation for arithmetic sequence O(n log mod)
// x_i = a + i*d : y_i, 0<=i<=n
template <typename T>
T LagrangeInterpolationArithmetic(T a, T d, vector<T> y, T x) {
    const lint n = y.size() - 1;
    T ret = 0, ft = 1;
    for (int i = 0; i < n + 1; ++i) {
        ft *= x - (a + d * i);
    }
    T f = 1;
    for (int i = 1; i < n + 1; ++i) {
        f *= -d * i;
    }
    ret += y[0] / f * ft / (x - a);
    for (int i = 0; i < n; ++i) {
        f *= d * (i + 1) / (d * (i - n));
        ret += y[i + 1] / f * ft / (x - a - d * (i + 1));
    }
    return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

