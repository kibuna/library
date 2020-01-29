// return slide minimum
// original sequense seq, slide width w
// return [min[0,w), min[1,1+w), ...]
template <typename T>
vector<T> slideMin(const vector<T> &seq, int w) {
    vector<T> ret;
    ret.reserve(seq.size() - w);
    deque<int> q;
    int l(0), r(0), n(seq.size());
    while (r < w) {
        while (!q.empty() && seq[q.back()] >= seq[r])
            q.pop_back();
        q.push_back(r++);
    }
    ret.push_back(seq[q.front()]);
    while (r < n) {
        while (!q.empty() && seq[q.back()] >= seq[r])
            q.pop_back();
        q.push_back(r++);
        if (q.front() == l++)
            q.pop_front();
        ret.push_back(seq[q.front()]);
    }
    return ret;
}