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


# :heavy_check_mark: library/algebra/combination.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#26c2ef729e4bca24cf34dda14fedd106">library/algebra</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/algebra/combination.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-28 21:57:08+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/algebra/combination.test.cpp.html">test/algebra/combination.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct Combination {
    vector<lint> fac, finv, inv;
    Combination(lint maxN) : fac(maxN + 100), finv(maxN + 100), inv(maxN + 100) {
        maxN += 100; // for safety
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1]            = 1;
        for (lint i = 2; i <= maxN; ++i) {
            fac[i]  = fac[i - 1] * i % mod;
            inv[i]  = mod - inv[mod % i] * (mod / i) % mod;
            finv[i] = finv[i - 1] * inv[i] % mod;
        }
    }
    lint operator()(lint n, lint k) {
        if (n < k)
            return 0;
        if (n < 0 || k < 0)
            return 0;
        return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/algebra/combination.cpp"
struct Combination {
    vector<lint> fac, finv, inv;
    Combination(lint maxN) : fac(maxN + 100), finv(maxN + 100), inv(maxN + 100) {
        maxN += 100; // for safety
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1]            = 1;
        for (lint i = 2; i <= maxN; ++i) {
            fac[i]  = fac[i - 1] * i % mod;
            inv[i]  = mod - inv[mod % i] * (mod / i) % mod;
            finv[i] = finv[i - 1] * inv[i] % mod;
        }
    }
    lint operator()(lint n, lint k) {
        if (n < k)
            return 0;
        if (n < 0 || k < 0)
            return 0;
        return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
