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

const int N = 150;
vector<string> g;
int n, m;
int dist[N][N];

const int dir[4][2] = {
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};

inline bool inside (int i, int j) {
    auto check = [](int i, int n) {
        return i >= 0 && i < n;
    };
    return check(i, n) && check(j, m);
}

inline int go(int i, int j) {
    int cnt = 0;
    for (int k = -20; k <= 20; k++) {
        for (int l = -20; l <= 20; l++) {
            int ii = i + k;
            int jj = j + l;

            if (!inside(ii, jj) || g[ii][jj] == '#') {
                continue;
            }

            int t = abs(k) + abs(l);
            if (t > 20) {
                continue;
            }
            int save = dist[ii][jj] - (dist[i][j]+t);
            cnt += (save >= 100);
        }
    }
    return cnt;
}

int go() {
    memset(dist, -1, sizeof dist);

    n = g.size();
    m = g[0].size();
    queue<ii> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'S') {
                q.emplace(i, j);
                dist[i][j] = 0;
            }
        }
    }


    while(q.size()) {
        int i = q.front().fi;
        int j = q.front().se;

        q.pop();

        if (g[i][j] == 'E') {
            break;
        }

        for (int d = 0; d < 4; d++) {
            int ii = i + dir[d][0];
            int jj = j + dir[d][1];

            if (inside(ii, jj) && g[ii][jj] != '#' && dist[ii][jj] == -1) {
                dist[ii][jj] = dist[i][j]+1;
                q.emplace(ii, jj);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '#') {
                continue;
            }
            ans += go(i, j);
        }
    }

    return ans;
}

int main (void) {
	ios_base::sync_with_stdio(false);

    string line;
    while(getline(cin, line)) {
        g.push_back(line);
    }
    cout << go() << endl;

	return 0;
}
