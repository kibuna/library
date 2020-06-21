set<lint, greater<lint>> basis;
for (lint e : a) {
    for (lint b : basis)
        chmin(e, e ^ b);
    if (e)
        basis.insert(e);
}
