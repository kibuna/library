#include "segmenttree.cpp"

template <typename T>
class HLDNonCommutative {
    using F = function<T(T, T)>;
    void dfs_sz(int v) {
        for (int &u : edges[v])
            if (u == par[v])
                swap(u, edges[v].back());
        if (~par[v])
            edges[v].pop_back();

        for (int &u : edges[v]) {
            par[u] = v;
            dep[u] = dep[v] + 1;
            dfs_sz(u);
            sub[v] += sub[u];
            if (sub[u] > sub[edges[v][0]])
                swap(u, edges[v][0]);
        }
    }
    void dfs_hld(int v, int c, int &pos) {
        vid[v]      = pos++;
        inv[vid[v]] = v;
        type[v]     = c;
        for (int u : edges[v]) {
            if (u == par[v])
                continue;
            head[u] = (u == edges[v][0] ? head[v] : u);
            dfs_hld(u, c, pos);
        }
        out[v] = pos;
    }

  public:
    bool built;
    int n;
    vector<vector<int>> edges;
    vector<int> vid, head, sub, par, dep, inv, type, out;
    F f;
    T unit;
    SegmentTree<T> segTree, segTreeRev;

    HLDNonCommutative(int n, F f, T unit)
        : built(false), n(n), edges(n), vid(n, -1), head(n), sub(n, 1), par(n, -1), dep(n, 0), inv(n), type(n), out(n),
          f(f), unit(unit), segTree(n, f, unit), segTreeRev(n, f, unit) {}

    void add_edge(int u, int v) {
        edges[u].emplace_back(v);
        edges[v].emplace_back(u);
    }

    void build(vector<int> rs = {0}) {
        int c = 0, pos = 0;
        for (int r : rs) {
            dfs_sz(r);
            head[r] = r;
            dfs_hld(r, c++, pos);
        }
        built = true;
    }

    void assign(vector<T> nodes) {
        assert((int)nodes.size() == n);
        vector<T> v(n);
        for (int i = 0; i < n; ++i) {
            v[vid[i]] = nodes[i];
        }
        segTree = SegmentTree<T>(v, f, unit);
        reverse(v.begin(), v.end());
        segTreeRev = SegmentTree<T>(v, f, unit);
    }

    int lca(int u, int v) {
        assert(built);
        while (1) {
            if (vid[u] > vid[v])
                swap(u, v);
            if (head[u] == head[v])
                return u;
            v = par[head[v]];
        }
    }

    int distance(int u, int v) { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }

    void update(int k, T x) {
        segTree.update(vid[k], x);
        segTreeRev.update(n - 1 - vid[k], x);
    }

    // query for each vertex
    // [l, r] <- attention!! closed section (path) on the tree
    T query(int u, int v) {
        assert(built);
        T retr = unit, retl = unit;
        int p = lca(u, v);
        while (1) {
            if (head[p] != head[v]) {
                retr = f(segTree.query(vid[head[v]], vid[v] + 1), retr);
                v    = par[head[v]];
            } else {
                retr = f(segTree.query(vid[p], vid[v] + 1), retr);
                break;
            }
        }
        while (1) {
            if (head[p] != head[u]) {
                retl = f(retl, segTreeRev.query(n - 1 - vid[u], n - 1 - vid[head[u]] + 1));
                u    = par[head[u]];
            } else {
                retl = f(retl, segTreeRev.query(n - 1 - vid[u], n - 1 - vid[p]));
                break;
            }
        }
        return f(retl, retr);
    }
};