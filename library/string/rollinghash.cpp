// original: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
class RollingHash {
  private:
    using ulint                        = unsigned long long;
    static constexpr ulint mask30      = (1ULL << 30) - 1;
    static constexpr ulint mask31      = (1ULL << 31) - 1;
    static constexpr ulint mod         = (1ULL << 61) - 1;
    static constexpr ulint positivizer = mod * ((1ULL << 3) - 1);
    static constexpr unsigned int base = 1033;
    int len;
    std::vector<ulint> pow_b, hash;
    static ulint mul(ulint l, ulint r) {
        const ulint lu        = l >> 31;
        const ulint ld        = l & mask31;
        const ulint ru        = r >> 31;
        const ulint rd        = r & mask31;
        const ulint middleBit = ld * ru + lu * rd;
        return ((lu * ru) << 1) + ld * rd + ((middleBit & mask30) << 31) + (middleBit >> 30);
    }
    static ulint calcMod(ulint val) {
        val = (val & mod) + (val >> 61);
        if (val > mod)
            val -= mod;
        return val;
    }

  public:
    template <typename T>
    RollingHash(const T &s) : len(s.size()), pow_b(s.size() + 1), hash(s.size() + 1) {
        pow_b[0] = 1;
        hash[0]  = 1;
        for (int i = 0; i < len; ++i) {
            pow_b[i + 1] = calcMod(mul(pow_b[i], base));
            hash[i + 1]  = calcMod(mul(hash[i], base) + s[i]);
        }
    }
    // hash for [l, r)
    ulint get(int l, int r) const { return calcMod(hash[r] + positivizer - mul(hash[l], pow_b[r - l])); }
    // length of longest common prefix
    int lcp(const RollingHash &rhs, int l1, int r1, int l2, int r2) const {
        int lb = 0, ub = std::min(r1 - l1, r2 - l2) + 1;
        while (ub - lb > 1) {
            const int md                                         = (lb + ub) >> 1;
            (get(l1, l1 + md) == rhs.get(l2, l2 + md) ? lb : ub) = md;
        }
        return lb;
    }
};
