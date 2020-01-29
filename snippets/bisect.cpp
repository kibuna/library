lint ok    = 0;
lint ng    = inf;
auto check = [&](lint mid) {

};
while (abs(ok - ng) != 1) {
    lint mid               = (ok + ng) / 2;
    (check(mid) ? ok : ng) = mid;
}
cout << ok << "\n";
