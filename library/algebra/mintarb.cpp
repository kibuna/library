struct modint {
    lint v;
    static lint &mod() {
        static lint mod = 0;
        return mod;
    }
    static lint set_mod(lint md) { mod() = md; }
    modint() : v(0) {}
    modint(signed v) : v(v) {}
    modint(lint t) {
        assert(mod() != 0);
        v = t % mod();
        if (v < 0)
            v += mod();
    }

    modint pow(lint k) {
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
    modint inv() { return pow(mod() - 2); }

    modint &operator+=(modint a) {
        v += a.v;
        if (v >= mod())
            v -= mod();
        return *this;
    }
    modint &operator-=(modint a) {
        v += mod() - a.v;
        if (v >= mod())
            v -= mod();
        return *this;
    }
    modint &operator*=(modint a) {
        v = v * a.v % mod();
        return *this;
    }
    modint &operator/=(modint a) { return (*this) *= a.inv(); }

    modint operator+(modint a) const { return modint(v) += a; };
    modint operator-(modint a) const { return modint(v) -= a; };
    modint operator*(modint a) const { return modint(v) *= a; };
    modint operator/(modint a) const { return modint(v) /= a; };

    modint operator-() const { return v ? modint(mod - v) : modint(v); }

    bool operator==(const modint a) const { return v == a.v; }
    bool operator!=(const modint a) const { return v != a.v; }
    bool operator<(const modint a) const { return v < a.v; }
};
using mint = modint;
ostream &operator<<(ostream &os, mint m) { return os << m.v; }
// DO CALL mint::set_mod()