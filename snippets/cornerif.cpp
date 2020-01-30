template <typename T>
void cornerif(bool cond, const T &ret) {
    if (cond) {
        cout << ret << "\n";
        exit(0);
    }
}
