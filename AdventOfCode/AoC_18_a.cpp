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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int X = 70, Y = 70;
const int N = X+1, M = Y+1;
vector<ii> v;
bool block[N][N];
int dist[N][N];

const int dir[4][2] = {
    {1, 0},
    {0, -1},
    {-1, 0},
    {0, 1}
};

int go(int t) {
    memset(dist, -1, sizeof dist);

    for (int i = 0; i < t; i++) {
        block[v[i].fi][v[i].se] = true;
    }

    auto can = [&](int i, int j) -> bool {
        auto check = [&](int i, int n) -> bool {
            return i >= 0 && i < n;
        };
        return check(i, N) && check(j, M) && !block[i][j];
    };

    queue<ii> q;
    q.emplace(0, 0);
    dist[0][0] = 0;
    while(q.size()) {
        int x = q.front().fi;
        int y = q.front().se;
        q.pop();

        if (x == X && y == Y) {
            return dist[x][y];
        }

        for (int d = 0; d < 4; d++) {
            int xx = x+dir[d][0];
            int yy = y+dir[d][1];

            if (can(xx, yy) && dist[xx][yy] == -1) {
                dist[xx][yy] = dist[x][y] + 1;
                q.emplace(xx, yy);
            }
        }
    }

    assert(0);
    return -1;
}

void read() {
    auto parse = [](string s, int &i) -> int {
        bool f = false;
        int val = 0;
        while(i < (int)s.size()) {
            char c = s[i++];
            if (c >= '0' && c <= '9') {
                val = val*10 + c-'0';
                f = true;
            } else if (f) {
                return val;
            }
        }
        return val;
    };

    string line;
    while(getline(cin, line)) {
        int i = 0;
        int x = parse(line, i);
        int y = parse(line, i);
        v.emplace_back(x, y);
    }
}

int main (void) {
	ios_base::sync_with_stdio(false);

    read();
    cout << go(1024) << endl;

	return 0;
}
