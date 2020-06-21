template <typename T>
struct Compress {
    vector<T> data;
    Compress() = default;
    Compress(const vector<T> &dat) {
        add(dat);
        build();
    }
    void add(const vector<T> &dat) { copy(dat.begin(), dat.end(), back_inserter(data)); }
    void add(const T &d) { data.emplace_back(d); }
    void build() {
        sort(data.begin(), data.end());
        data.erase(unique(data.begin(), data.end()), data.end());
    }
    int size() const { return data.size(); }
    // round up
    int at(const T &x) const { return lower_bound(data.begin(), data.end(), x) - data.begin(); }
    // round down
    int rd(const T &x) const { return prev(upper_bound(data.begin(), data.end(), x)) - data.begin(); }
    // int ru(const T &x) const { return upper_bound(data.begin(), data.end(), x) - data.begin(); }
    const T &operator[](int k) const { return data[k]; }
};