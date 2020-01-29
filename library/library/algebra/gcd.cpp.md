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


# :heavy_check_mark: library/algebra/gcd.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#26c2ef729e4bca24cf34dda14fedd106">library/algebra</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/algebra/gcd.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-27 00:09:13+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/algebra/gcd.test.cpp.html">test/algebra/gcd.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// greatest common divisor and least common multiple
// gcd is calculated by Euclidean Algorithm
// lcm = m * n / gcd(m,n)
template <typename T = int>
T gcd(T a, T b) {
    if (a < b)
        return gcd(b, a);
    if (b == 0)
        return a;
    T r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

template <typename T = int>
T lcm(T m, T n) {
    if ((0 == m) || (0 == n))
        return 0;
    return ((m / gcd(m, n)) * n);
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/algebra/gcd.cpp"
// greatest common divisor and least common multiple
// gcd is calculated by Euclidean Algorithm
// lcm = m * n / gcd(m,n)
template <typename T = int>
T gcd(T a, T b) {
    if (a < b)
        return gcd(b, a);
    if (b == 0)
        return a;
    T r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

template <typename T = int>
T lcm(T m, T n) {
    if ((0 == m) || (0 == n))
        return 0;
    return ((m / gcd(m, n)) * n);
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

