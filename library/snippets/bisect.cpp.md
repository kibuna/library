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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: snippets/bisect.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#67be68a348da3b850fb7daa10b034528">snippets</a>
* <a href="{{ site.github.repository_url }}/blob/master/snippets/bisect.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-29 21:32:14+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
lint ok    = 0;
lint ng    = inf;
auto check = [&](lint mid) {

};
while (abs(ok - ng) != 1) {
    lint mid               = (ok + ng) / 2;
    (check(mid) ? ok : ng) = mid;
}
cout << ok << "\n";

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "snippets/bisect.cpp"
lint ok    = 0;
lint ng    = inf;
auto check = [&](lint mid) {

};
while (abs(ok - ng) != 1) {
    lint mid               = (ok + ng) / 2;
    (check(mid) ? ok : ng) = mid;
}
cout << ok << "\n";

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
