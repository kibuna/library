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


# :warning: library/util/compress.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#a01cbb0d6e18d64f17c40364f01e4520">library/util</a>
* <a href="{{ site.github.repository_url }}/blob/master/library/util/compress.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-21 13:49:22+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <typename T>
struct Compress {
    vector<T> data;
    Compress() = default;
    Compress(const vector<T> &dat) {
        add(dat);
        build();
    }
    void add(const vector<T> &dat) { copy(dat.begin(), dat.end(), back_inserter(data)); }
    void add(const T &d) { data.emplace_back(d); }
    void build() {
        sort(data.begin(), data.end());
        data.erase(unique(data.begin(), data.end()), data.end());
    }
    int size() const { return data.size(); }
    // round up
    int at(const T &x) const { return lower_bound(data.begin(), data.end(), x) - data.begin(); }
    // round down
    int rd(const T &x) const { return prev(upper_bound(data.begin(), data.end(), x)) - data.begin(); }
    // int ru(const T &x) const { return upper_bound(data.begin(), data.end(), x) - data.begin(); }
    const T &operator[](int k) const { return data[k]; }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "library/util/compress.cpp"
template <typename T>
struct Compress {
    vector<T> data;
    Compress() = default;
    Compress(const vector<T> &dat) {
        add(dat);
        build();
    }
    void add(const vector<T> &dat) { copy(dat.begin(), dat.end(), back_inserter(data)); }
    void add(const T &d) { data.emplace_back(d); }
    void build() {
        sort(data.begin(), data.end());
        data.erase(unique(data.begin(), data.end()), data.end());
    }
    int size() const { return data.size(); }
    // round up
    int at(const T &x) const { return lower_bound(data.begin(), data.end(), x) - data.begin(); }
    // round down
    int rd(const T &x) const { return prev(upper_bound(data.begin(), data.end(), x)) - data.begin(); }
    // int ru(const T &x) const { return upper_bound(data.begin(), data.end(), x) - data.begin(); }
    const T &operator[](int k) const { return data[k]; }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

