using ulint = unsigned long long;
struct RandomNumberGenerator {
    mt19937_64 mt;
    RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    ulint operator()(ulint a, ulint b) { // [a, b)
        uniform_int_distribution<ulint> dist(a, b - 1);
        return dist(mt);
    }
    ulint operator()(ulint b) { // [0, b)
        return (*this)(0, b);
    }
    ulint operator()() { return mt(); }
};
