function<void(int, int)> dfs = [&](int c, int p) {
    for (auto &v : edges[c]) {
        if (v == p)
            continue;
        dfs(v, c);
    }
};
