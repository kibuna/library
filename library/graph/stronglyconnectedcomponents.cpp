struct StronglyConnectedComponents {
    vector<vector<int>> const &edges_in;
    vector<vector<int>> edges, rev;
    vector<int> comp, order, used;

    StronglyConnectedComponents(vector<vector<int>> const &g)
        : edges_in(g), edges(g.size()), rev(g.size()), comp(g.size(), -1), used(g.size()) {
        for (int i = 0; i < (int)edges_in.size(); ++i) {
            for (auto &v : edges_in[i]) {
                edges[i].push_back(v);
                rev[v].push_back(i);
            }
        }
    }
    int operator[](int k) { return comp[k]; }
    void dfs(int c) {
        if (used[c])
            return;
        used[c] = true;
        for (auto &v : edges[c])
            dfs(v);
        order.push_back(c);
    }
    void rdfs(int c, int cnt) {
        if (comp[c] != -1)
            return;
        comp[c] = cnt;
        for (auto &v : rev[c])
            rdfs(v, cnt);
    }
    vector<vector<int>> build() {
        for (int i = 0; i < (int)edges.size(); ++i)
            dfs(i);
        reverse(order.begin(), order.end());
        int ptr = 0;
        for (auto &i : order) {
            if (comp[i] == -1)
                rdfs(i, ptr++);
        }
        vector<vector<int>> ret(ptr);
        for (int i = 0; i < (int)edges_in.size(); ++i) {
            int x = comp[i];
            for (auto &v : edges_in[i]) {
                int y = comp[v];
                if (x == y)
                    continue;
                ret[x].push_back(y);
            }
        }
        return ret;
    }
};
