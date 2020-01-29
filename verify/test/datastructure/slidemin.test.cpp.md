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


# :heavy_check_mark: test/datastructure/slidemin.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/datastructure/slidemin.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-29 21:32:59+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/library/datastructure/slidemin.cpp.html">library/datastructure/slidemin.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/datastructure/slidemin.cpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, l;
    cin >> n >> l;
    vector<lint> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    auto ret = slideMin(a, l);
    for (int i = 0; i <= n - l; ++i) {
        if (i)
            cout << " ";
        cout << ret[i];
    }
    cout << endl;
    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/datastructure/slidemin.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#line 1 "test/datastructure/../../library/datastructure/slidemin.cpp"
// return slide minimum
// original sequense seq, slide width w
// return [min[0,w), min[1,1+w), ...]
template <typename T>
vector<T> slideMin(const vector<T> &seq, int w) {
    vector<T> ret;
    ret.reserve(seq.size() - w);
    deque<int> q;
    int l(0), r(0), n(seq.size());
    while (r < w) {
        while (!q.empty() && seq[q.back()] >= seq[r])
            q.pop_back();
        q.push_back(r++);
    }
    ret.push_back(seq[q.front()]);
    while (r < n) {
        while (!q.empty() && seq[q.back()] >= seq[r])
            q.pop_back();
        q.push_back(r++);
        if (q.front() == l++)
            q.pop_front();
        ret.push_back(seq[q.front()]);
    }
    return ret;
}
#line 8 "test/datastructure/slidemin.test.cpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, l;
    cin >> n >> l;
    vector<lint> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    auto ret = slideMin(a, l);
    for (int i = 0; i <= n - l; ++i) {
        if (i)
            cout << " ";
        cout << ret[i];
    }
    cout << endl;
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

