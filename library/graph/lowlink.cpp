// @see https://ei1333.github.io/luzhiled/snippets/graph/lowlink.html
struct LowLink {
    int n;
    vector<int> used, ord, low;
    vector<int> articulation;
    vector<pair<int, int>> bridge;
    vector<vector<int>> edges;
    LowLink(const vector<vector<int>> &edges) : n(edges.size()), used(n, 0), ord(n, 0), low(n, 0), edges(edges) {}

    int dfs(int c, int p, int i) {
        used[c]              = true;
        ord[c]               = i++;
        low[c]               = ord[c];
        bool is_articulation = false;
        int cnt              = 0;
        for (auto &v : edges[c]) {
            if (v == p)
                continue;
            if (!used[v]) {
                cnt++;
                i      = dfs(v, c, i);
                low[c] = min(low[c], low[v]);
                is_articulation |= ~p && low[v] >= ord[c];
                if (ord[c] < low[v])
                    bridge.emplace_back(min(c, v), max(c, v));
            } else {
                low[c] = min(low[c], ord[v]);
            }
        }
        is_articulation |= p == -1 && cnt > 1;
        if (is_articulation)
            articulation.push_back(c);
        return i;
    }
    void build() {
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (!used[i])
                k = dfs(i, -1, k);
        }
    }
};
