// dist is adjacency matrix, no edge = inf
template <typename T, bool has_negative_edge = false>
void warshallFloyd(vector<vector<T>> &dist, T inf) {
    int n = dist.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (has_negative_edge) {
                    if (dist[j][i] != inf && dist[i][k] != inf)
                        chmin(dist[j][k], dist[j][i] + dist[i][k]);
                } else {
                    chmin(dist[j][k], dist[j][i] + dist[i][k]);
                }
            }
        }
    }
}