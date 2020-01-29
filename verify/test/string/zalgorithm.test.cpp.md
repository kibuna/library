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


# :heavy_check_mark: test/string/zalgorithm.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/string/zalgorithm.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-28 21:56:32+09:00


* see: <a href="https://judge.yosupo.jp/problem/zalgorithm">https://judge.yosupo.jp/problem/zalgorithm</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/library/string/zalgorithm.cpp.html">library/string/zalgorithm.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include "../../library/string/zalgorithm.cpp"

int main() {
    string s;
    cin >> s;
    auto ret = ZAlgorithm(s);
    for (int i = 0; i < (int)s.size(); ++i) {
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
#line 1 "test/string/zalgorithm.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#line 1 "test/string/../../library/string/zalgorithm.cpp"
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
}#line 8 "test/string/zalgorithm.test.cpp"

int main() {
    string s;
    cin >> s;
    auto ret = ZAlgorithm(s);
    for (int i = 0; i < (int)s.size(); ++i) {
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

