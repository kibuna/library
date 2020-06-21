template <lint mod>
struct modint {
    lint v;
    constexpr modint(lint t = 0) noexcept {
        v = t % mod;
        if (v < 0)
            v += mod;
    }
    constexpr modint pow(lint k) noexcept {
        modint res(1), tmp(v);
        while (k) {
            if (k & 1)
                res *= tmp;
            tmp *= tmp;
            k >>= 1;
        }
        return res;
    }
    static modint add_identity() { return modint(0); }
    static modint mul_identity() { return modint(1); }
    constexpr modint inv() { return pow(mod - 2); }

    constexpr modint &operator+=(const modint a) noexcept {
        v += a.v;
        if (v >= mod)
            v -= mod;
        return *this;
    }
    constexpr modint &operator-=(const modint a) noexcept {
        v += mod - a.v;
        if (v >= mod)
            v -= mod;
        return *this;
    }
    constexpr modint &operator*=(const modint a) noexcept {
        v = v * a.v % mod;
        return *this;
    }
    constexpr modint &operator/=(const modint a) noexcept { return (*this) *= a.inv(); }

    constexpr modint operator+(const modint a) const noexcept { return modint(v) += a; };
    constexpr modint operator-(const modint a) const noexcept { return modint(v) -= a; };
    constexpr modint operator*(const modint a) const noexcept { return modint(v) *= a; };
    constexpr modint operator/(const modint a) const noexcept { return modint(v) /= a; };
    constexpr modint operator-() const noexcept { return v ? modint(mod - v) : modint(v); }

    constexpr bool operator==(const modint a) const noexcept { return v == a.v; }
    constexpr bool operator!=(const modint a) const noexcept { return v != a.v; }
    constexpr bool operator<(const modint a) const noexcept { return v < a.v; }
};
using mint = modint<mod>;
ostream &operator<<(ostream &os, mint m) { return os << m.v; }