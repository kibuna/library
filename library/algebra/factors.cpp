// list up all factors
template <typename T>
set<T> factors(T a) {
    set<T> facs;
    for (T i = 1; i * i <= a; ++i) {
        if (a % i == 0) {
            facs.insert(i);
            facs.insert(a / i);
        }
    }
    return facs;
}