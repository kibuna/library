lint ok    = 0;
lint ng    = inf;
auto check = [&](lint mid) {

};
while (ok + 1 != ng) {
    lint mid               = (ok + ng);
    (check(mid) ? ok : ng) = mid;
}
cout << ok << "\n";
