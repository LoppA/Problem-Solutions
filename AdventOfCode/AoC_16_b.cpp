#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef __int128 LL;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int dir[4][2] = {
    {0, 1},
    {-1, 0},
    {0, -1},
    {1, 0},
};
vector<string> g;
int n, m;
map<iii, int> dist[2];

void dij(map<iii, int> &dist, iii st, bool f = false) {
    priority_queue<
        pair<int, iii>,
        vector<pair<int, iii>>, 
        greater<pair<int, iii>> > pq;
    queue<iii> q;

    if (f) {
        int i, j, _;
        tie(i, j, _) = st;
        for (int k = 0; k < 4; k++) {
            st = iii(i, j, k);
            dist[st] = 0;
            pq.emplace(0, st);
        }
    } else {
        dist[st] = 0;
        pq.emplace(0, st);
    }
    auto inside = [](int i, int j) {
        auto check = [](int i, int n) {
            return i >= 0 && i < n;
        };
        bool ins = check(i, n) && check(j, m);
        if (!ins) {
            return false;
        }
        return g[i][j] != '#';
    };

    while(pq.size()) {
        iii curr = pq.top().se;
        int dst = pq.top().fi;
        int i, j, d;
        tie(i, j, d) = curr;
        pq.pop();

        if (dst > dist[curr]) {
            continue;
        }

        int ii = i + dir[d][0];
        int jj = j + dir[d][1];

        iii nxt = iii(ii, jj, d);

        if (inside(ii, jj) &&
            (!dist.count(nxt) || dist[nxt] > dst + 1)) {
            dist[nxt] = dist[curr]+1;
            pq.emplace(dist[nxt], nxt);
        }


        nxt = iii(i, j, (d+1)%4);
        if (!dist.count(nxt) || dist[nxt] > dst + 1000) {
            dist[nxt] = dist[curr]+1000;
            pq.emplace(dist[nxt], nxt);
        }

        nxt = iii(i, j, (d-1+4)%4);
        if (!dist.count(nxt) || dist[nxt] > dst + 1000) {
            dist[nxt] = dist[curr]+1000;
            pq.emplace(dist[nxt], nxt);
        }
    }
}

int get_dist(map<iii, int> &dist, int i, int j) {
    if (!dist.count(iii(i, j, 0))) {
        return -1;
    }
    int ret = dist[iii(i, j, 0)];
    for (int k = 1; k < 4; k++) {
        ret = min(ret, dist[iii(i, j, k)]);
    }
    return ret;
}

int go() {
    n  = g.size();
    m  = g[0].size();

    ii a, b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'S') {
                a = ii(i, j);
            } else if (g[i][j] == 'E') {
                b = ii(i, j);
            }
        }
    }

    dij(dist[0], iii(a.fi, a.se, 0));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            dir[i][j] *= -1;
        }
    }
    int ab = get_dist(dist[0], b.fi, b.se);
    dij(dist[1], iii(b.fi, b.se, 0), true);

    assert(ab == dist[1][iii(a.fi, a.se, 0)]);

    set<ii> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int d = 0; d < 4; d++) {
                int l = dist[0][iii(i, j, d)];
                int r = dist[1][iii(i, j, d)];
                if (l + r == ab) {
                    s.emplace(i, j);
                }
            }
        }
    }

    return s.size();
}

int main (void) {
    ios_base::sync_with_stdio(false);

    string line;
    while(cin >> line) {
        g.push_back(line);
    }
    cout << go() << endl;

    return 0;
}
