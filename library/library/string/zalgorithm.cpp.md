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


# :heavy_check_mark: library/string/zalgorithm.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7c4d7dea78114de72b5d81eacef966cd">library/string</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/string/zalgorithm.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-28 21:56:32+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/string/zalgorithm.test.cpp.html">test/string/zalgorithm.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <typename T>
vector<int> ZAlgorithm(const T &s) {
    const int ns = s.size();
    vector<int> prefix(ns);
    for (int i = 1, j = 0; i < ns; i++) {
        if (i + prefix[i - j] < j + prefix[j]) {
            prefix[i] = prefix[i - j];
        } else {
            int k = max(0, j + prefix[j] - i);
            while (i + k < ns && s[k] == s[i + k])
                ++k;
            prefix[i] = k;
            j         = i;
        }
    }
    prefix[0] = ns;
    return prefix;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/string/zalgorithm.cpp"
template <typename T>
vector<int> ZAlgorithm(const T &s) {
    const int ns = s.size();
    vector<int> prefix(ns);
    for (int i = 1, j = 0; i < ns; i++) {
        if (i + prefix[i - j] < j + prefix[j]) {
            prefix[i] = prefix[i - j];
        } else {
            int k = max(0, j + prefix[j] - i);
            while (i + k < ns && s[k] == s[i + k])
                ++k;
            prefix[i] = k;
            j         = i;
        }
    }
    prefix[0] = ns;
    return prefix;
}
```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
