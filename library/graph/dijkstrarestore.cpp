template <typename T>
struct Dijkstra {
    using P = pair<T, int>;
    int n;
    T inf;
    vector<T> dist;
    vector<int> rev;
    vector<vector<pair<int, T>>> G;

    Dijkstra(vector<vector<pair<int, T>>> &G_) : G(G_) {
        n   = G.size();
        inf = numeric_limits<T>::max();
    }
    void build(int s) {
        dist.clear();
        dist.resize(n, inf);
        rev.clear();
        rev.resize(n, -1);
        priority_queue<P, vector<P>, greater<P>> q;
        dist[s] = 0;
        q.emplace(dist[s], s);
        while (!q.empty()) {
            P p = q.top();
            q.pop();
            int v = p.second;
            if (dist[v] < p.first)
                continue;
            for (auto &e : G[v]) {
                int u = e.first;
                T c   = e.second;
                if (dist[u] > dist[v] + c) {
                    dist[u] = dist[v] + c;
                    rev[u]  = v;
                    q.emplace(dist[u], u);
                }
            }
        }
    }
    vector<int> restore_path(int t) {
        vector<int> path;
        for (; t != -1; t = rev[t])
            path.push_back(t);
        reverse(path.begin(), path.end());
        return path;
    }
};