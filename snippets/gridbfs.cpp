vector<string> s(h);
for (int i = 0; i < h; ++i) {
    cin >> s[i];
}
int sy, sx;
[&] {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (s[i][j] == '@') {
                sy = i;
                sx = j;
                return;
            }
        }
    }
}();
queue<pair<int, int>> q;
q.emplace(sy, sx);
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
auto inside     = [&](int y, int x) { return 0 <= y && y < h && 0 <= x && x < w; };
int ret         = 1;
while (q.size() != 0) {
    auto p = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i) {
        int nx = p.second + dx[i];
        int ny = p.first + dy[i];
        if (inside(ny, nx) && s[ny][nx] == '.') {
            ret++;
            s[ny][nx] = '#';
            q.emplace(ny, nx);
        }
    }
}