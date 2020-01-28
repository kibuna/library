template <typename T>
vector<int> ZAlgorithm(const T &s) {
    const int ns = s.size();
    vector<int> prefix(ns);
    for (int i = 1, j = 0; i < ns; i++) {
        if (i + prefix[i - j] < j + prefix[j]) {
            prefix[i] = prefix[i - j];
        } else {
            int k = max(0, j + prefix[j] - i);
            while (i + k < ns && s[k] == s[i + k])
                ++k;
            prefix[i] = k;
            j         = i;
        }
    }
    prefix[0] = ns;
    return prefix;
}