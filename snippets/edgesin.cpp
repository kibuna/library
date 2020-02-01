vector<vector<int>> edges(n);
for (int i = 0; i < ${1:n-1}; ++i) {
    int u, v;
    cin >> u >> v;
    // u--, v--;
    edges[u].emplace_back(v);
    edges[v].emplace_back(u);
}
