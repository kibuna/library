vector<vector<pair<int, lint>>> edges(n);
for (int i = 0; i < ${1 : n - 1}; ++i) {
    int u, v;
    lint w;
    cin >> u >> v >> w;
    // u--, v--;
    edges[u].emplace_back(v, w);
    edges[v].emplace_back(u, w);
}
