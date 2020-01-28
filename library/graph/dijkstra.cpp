template <typename T>
vector<T> dijkstra(int s, vector<vector<pair<int, T>>> &G) {
    const T inf = numeric_limits<T>::max();
    using P     = pair<T, int>;
    int n       = G.size();
    vector<T> d(n, inf);
    priority_queue<P, vector<P>, greater<P>> q;
    d[s] = 0;
    q.emplace(d[s], s);
    while (!q.empty()) {
        P p = q.top();
        q.pop();
        int v = p.second;
        if (d[v] < p.first)
            continue;
        for (auto &e : G[v]) {
            int u = e.first;
            T c   = e.second;
            if (d[u] > d[v] + c) {
                d[u] = d[v] + c;
                q.emplace(d[u], u);
            }
        }
    }
    return d;
}