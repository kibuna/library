#include "../datastructure/segmenttree.cpp"

// get LCA on the tree
// constructor: n = size of the graph
// addEdge:
// build: after adding all edge, build Euler tour and seg tree
struct LCA {
    int n, k;
    vector<int> depth, eulerTour, firstVisit;
    vector<vector<int>> edges;
    SegmentTree<pair<int, int>> segTree;
    bool isbuilt;
    static pair<int, int> pairComp(pair<int, int> a, pair<int, int> b) {
        if (a.first < b.first)
            return a;
        else
            return b;
    }
    LCA(int n)
        : n(n), k(0), depth(2 * n - 1), eulerTour(2 * n - 1), firstVisit(n), edges(n),
          segTree(2 * n, pairComp, make_pair(numeric_limits<int>::max(), 0)), isbuilt(false){};
    LCA(vector<vector<int>> &edges, int root = 0)
        : n(edges.size()), k(0), depth(2 * n - 1), eulerTour(2 * n - 1), firstVisit(n), edges(edges),
          segTree(2 * n, pairComp, make_pair(numeric_limits<int>::max(), 0)), isbuilt(false) {
        build(root);
    };
    void addEdge(int from, int to) {
        edges[from].push_back(to);
        edges[to].push_back(from);
    }
    void dfs(int curr = 0, int par = -1, int d = 0) {
        firstVisit[curr] = k;
        eulerTour[k]     = curr;
        depth[k++]       = d;
        for (auto &e : edges[curr]) {
            if (e != par) {
                dfs(e, curr, d + 1);
                eulerTour[k] = curr;
                depth[k++]   = d;
            }
        }
    }
    void build(int root = 0) {
        dfs(root);
        for (int i = 0; i < 2 * n - 1; ++i) {
            segTree.update(i, make_pair(depth[i], eulerTour[i]));
        }
        isbuilt = true;
    }
    // return LCA node of l and r
    int operator()(int l, int r) {
        assert(isbuilt);
        int left  = firstVisit[l];
        int right = firstVisit[r];
        if (left > right)
            swap(left, right);
        return segTree.query(left, right + 1).second;
    }
    int getDepth(int k) { return depth[firstVisit[k]]; }
    int dist(int l, int r) { return getDepth(l) + getDepth(r) - 2 * getDepth(operator()(l, r)); }
};