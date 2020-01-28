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


# :warning: library/algebra/combinationprob.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#26c2ef729e4bca24cf34dda14fedd106">library/algebra</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/algebra/combinationprob.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-28 21:57:08+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// calculates nCk / 2^n
// https://www.slideshare.net/chokudai/abc011
// editorial D
struct CombinationProb {
    vector<vector<long double>> fac;
    CombinationProb(int maxN) {
        fac.resize(maxN + 2, vector<long double>(maxN + 2, 0.0));
        fac[0][0] = 1.0;
        for (int i = 1; i <= maxN; ++i) {
            fac[i][0] = fac[i - 1][0] / 2.0;
            for (int j = 1; j <= i + 1; ++j) {
                fac[i][j] = (fac[i - 1][j] + fac[i - 1][j - 1]) / 2.0;
            }
        }
    }
    long double operator()(int n, int k) { return fac[n][k]; }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/algebra/combinationprob.cpp"
// calculates nCk / 2^n
// https://www.slideshare.net/chokudai/abc011
// editorial D
struct CombinationProb {
    vector<vector<long double>> fac;
    CombinationProb(int maxN) {
        fac.resize(maxN + 2, vector<long double>(maxN + 2, 0.0));
        fac[0][0] = 1.0;
        for (int i = 1; i <= maxN; ++i) {
            fac[i][0] = fac[i - 1][0] / 2.0;
            for (int j = 1; j <= i + 1; ++j) {
                fac[i][j] = (fac[i - 1][j] + fac[i - 1][j - 1]) / 2.0;
            }
        }
    }
    long double operator()(int n, int k) { return fac[n][k]; }
};
```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

