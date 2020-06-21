// longest increasing subsequence
template <typename T>
int lis(vector<T> &v, T inf) {
    vector<T> a(v.size(), inf);
    for (int i = 0; i < v.size(); ++i) {
        *lower_bound(a.begin(), a.end(), v[i]) = v[i];
    }
    return lower_bound(a.begin(), a.end(), inf) - a.begin();
}
