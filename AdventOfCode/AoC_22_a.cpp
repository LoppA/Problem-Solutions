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

void go(ll &x, ll y) {
    x = (x^y)%MOD;
}

void go(ll &x) {
    go(x, x*64);
    go(x, x/32);
    go(x, x*2048);
}

int main (void) {
	ios_base::sync_with_stdio(false);

    ll x;
    ll ans = 0;
    while(cin >> x) {
        for (int i = 0; i < 2000; i++) {
            go(x);
        }
        ans += x;
        assert(ans >= 0);
    }
    cout << ans << endl;

	return 0;
}
