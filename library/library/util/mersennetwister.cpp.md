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


# :warning: library/util/mersennetwister.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#a01cbb0d6e18d64f17c40364f01e4520">library/util</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/util/mersennetwister.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-03 23:33:32+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
using ulint = unsigned long long;
struct RandomNumberGenerator {
    mt19937_64 mt;
    RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    ulint operator()(ulint a, ulint b) { // [a, b)
        uniform_int_distribution<ulint> dist(a, b - 1);
        return dist(mt);
    }
    ulint operator()(ulint b) { // [0, b)
        return (*this)(0, b);
    }
    ulint operator()() { return mt(); }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/util/mersennetwister.cpp"
using ulint = unsigned long long;
struct RandomNumberGenerator {
    mt19937_64 mt;
    RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    ulint operator()(ulint a, ulint b) { // [a, b)
        uniform_int_distribution<ulint> dist(a, b - 1);
        return dist(mt);
    }
    ulint operator()(ulint b) { // [0, b)
        return (*this)(0, b);
    }
    ulint operator()() { return mt(); }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
