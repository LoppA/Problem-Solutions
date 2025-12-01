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

const int MOD = 16777216;
const int N = 40*40*40*40;

inline void go(ll &x, ll y) {
    x = (x^y)%MOD;
}

inline int go(ll &x) {
    int prev = x;
    go(x, x*64);
    go(x, x/32);
    go(x, x*2048);
    return (x%10) - (prev%10);
}

int hsh(const vector<int>& v) {
    int h = 0;
    for (auto x : v) {
        h = h*40 + x+20;
    }
    assert(h >= 0 && h < N);
    return h;
}

int cnt[N];

int main (void) {
	ios_base::sync_with_stdio(false);

    ll x;
    while(cin >> x) {
        vector<int> vis(N, false);
        vector<int> v(4);
        int i = 0;
        for (; i < 4; i++) {
            v[i] = go(x);
        }
        int h = hsh(v);
        vis[h] = true;
        cnt[h] += x%10;

        for (; i < 2000; i++) {
            v[0] = v[1];
            v[1] = v[2];
            v[2] = v[3];
            v[3] = go(x);
            h = hsh(v);
            if (!vis[h]) {
                vis[h] = true;
                cnt[h] += x%10;
            }
        }
    }


    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, cnt[i]);
    }
    cout << ans << endl;

	return 0;
}
