#include "lowlink.cpp"
// @see https://ei1333.github.io/luzhiled/snippets/graph/two-edge-connected-components.html
struct TwoEdgeConnectedComponents : LowLink {
    int k;
    vector<int> comp;
    vector<vector<int>> bridges;
    TwoEdgeConnectedComponents(const vector<vector<int>> &edges) : LowLink(edges), k(0) { build(); }
    int operator[](const int &k) { return comp[k]; }
    void dfs(int idx, int par, int &k) {
        if (~par && this->ord[par] >= this->low[idx])
            comp[idx] = comp[par];
        else
            comp[idx] = k++;
        for (auto &to : this->edges[idx]) {
            if (comp[to] == -1)
                dfs(to, idx, k);
        }
    }
    void build() {
        comp.assign(this->edges.size(), -1);
        for (int i = 0; i < int(comp.size()); ++i) {
            if (comp[i] == -1)
                dfs(i, -1, k);
        }
        bridges.resize(k);
        for (auto &e : this->bridge) {
            int x = comp[e.first], y = comp[e.second];
            bridges[x].push_back(y);
            bridges[y].push_back(x);
        }
    }
};