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

const int N = (1<<11), M = 20;
ll dp[N][M];
const vector<int> v = {2,4,1,5,7,5,0,3,1,6,4,3,5,5,3,0};
// const vector<int> v = {6,5,7,4,5,7,3,1,0};

ll go(int A, int i) {
    if (i == (int)v.size()) {
        if (!A) {
            cout << "A " << A << " " << i << endl;
            return 0;
        } else {
            return -2;
        }
    }
    int B = 0, C = 0;
    int rA = A&7;

    ll &r = dp[A][i];
    if (r != -1) {
        return r;
    }
    r = -2;

    B = A&7;
    B = B^5;
    C = A>>B;
    C = C&7;
    A = A>>3;
    B = B^6;
    B = B^C;

    if (B != v[i]) {
        return -2;
    }

    for (int j = 0; j < 8; j++) {
        ll nxt = go((j<<7) + A, i+1);
        nxt = (nxt<<3) + rA;
        if (nxt >= 0) {
            if (r < 0)    r = nxt;
            r = min(r, nxt);
        }
    }

    return r;
}

int main (void) {
	ios_base::sync_with_stdio(false);

    memset(dp, -1, sizeof dp);

    ll r = -1;
    for (int i = 0; i < N; i++) {
        ll nxt = go(i, 0);
        if (nxt != -2) {
            if (r == -1)    r = nxt;
            r = min(r, nxt);
        }
    }
    cout << r << endl;

	return 0;
}
