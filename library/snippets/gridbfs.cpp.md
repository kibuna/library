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


# :warning: snippets/gridbfs.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#67be68a348da3b850fb7daa10b034528">snippets</a>
* <a href="{{ site.github.repository_url }}/blob/master/snippets/gridbfs.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-07 14:45:20+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
vector<string> s(h);
for (int i = 0; i < h; ++i) {
    cin >> s[i];
}
int sy, sx;
[&] {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (s[i][j] == '@') {
                sy = i;
                sx = j;
                return;
            }
        }
    }
}();
queue<pair<int, int>> q;
q.emplace(sy, sx);
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
auto inside     = [&](int y, int x) { return 0 <= y && y < h && 0 <= x && x < w; };
int ret         = 1;
while (q.size() != 0) {
    auto p = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i) {
        int nx = p.second + dx[i];
        int ny = p.first + dy[i];
        if (inside(ny, nx) && s[ny][nx] == '.') {
            ret++;
            s[ny][nx] = '#';
            q.emplace(ny, nx);
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "snippets/gridbfs.cpp"
vector<string> s(h);
for (int i = 0; i < h; ++i) {
    cin >> s[i];
}
int sy, sx;
[&] {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (s[i][j] == '@') {
                sy = i;
                sx = j;
                return;
            }
        }
    }
}();
queue<pair<int, int>> q;
q.emplace(sy, sx);
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
auto inside     = [&](int y, int x) { return 0 <= y && y < h && 0 <= x && x < w; };
int ret         = 1;
while (q.size() != 0) {
    auto p = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i) {
        int nx = p.second + dx[i];
        int ny = p.first + dy[i];
        if (inside(ny, nx) && s[ny][nx] == '.') {
            ret++;
            s[ny][nx] = '#';
            q.emplace(ny, nx);
        }
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

