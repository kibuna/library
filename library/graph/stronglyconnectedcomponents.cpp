struct StronglyConnectedComponents {
    vector<vector<int>> const &edges_in;
    vector<vector<int>> edges, rev, dag;
    vector<int> comp, order, used;
    vector<vector<int>> cs; // list of nodes in each component
    int ndag;

    StronglyConnectedComponents(vector<vector<int>> const &g)
        : edges_in(g), edges(g.size()), rev(g.size()), comp(g.size(), -1), used(g.size()), cs(g.size()) {
        for (int i = 0; i < (int)edges_in.size(); ++i) {
            for (auto &v : edges_in[i]) {
                edges[i].push_back(v);
                rev[v].push_back(i);
            }
        }
        build();
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
        cs[cnt].emplace_back(c);
        for (auto &v : rev[c])
            rdfs(v, cnt);
    }
    int build() {
        for (int i = 0; i < (int)edges.size(); ++i)
            dfs(i);
        reverse(order.begin(), order.end());
        ndag = 0;
        for (auto &i : order) {
            if (comp[i] == -1)
                rdfs(i, ndag++);
        }
        cs.resize(ndag);
        dag.resize(ndag);
        for (int i = 0; i < (int)edges_in.size(); ++i) {
            int x = comp[i];
            for (auto &v : edges_in[i]) {
                int y = comp[v];
                if (x == y)
                    continue;
                dag[x].push_back(y);
            }
        }
        return ndag;
    }
};