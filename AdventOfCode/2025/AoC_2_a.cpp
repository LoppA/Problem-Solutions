#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef __int128 LL;
typedef pair<ll, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

string s;
int n;

ll half(ll x, int y) {
    while(y--) {
        x /= 10;
    }
    return x;
}

int dig(ll x) {
    int y = 0;
    while(x) {
        x /= 10;
        y++;
    }
    return y;
}

ll build(ll x) {
    int y = dig(x);
    ll z = x;
    for (int i = 0; i < y; i++) {
        x *= 10;
    }
    return x + z;
}

ll exp(ll x, int y) {
    ll r = 1;
    while(y--) {
        r *= x;
    }
    return r;
}

ll go(int i, int j) {
    auto parse = [](int &i) -> ll {
        ll val = 0;
        while(i < n && s[i] != ',' && s[i] != '-') {
            val *= 10;
            val += s[i] - '0';
            i++;
        }
        i++;
        return val;
    };

    ll A = parse(i);
    ll B = parse(i);

    ll a = A;

    ll ans = 0;
    while(a <= B) {
        int d = dig(a);
        if (d%2) {
            a = exp(10, d);
            d++;

            continue;
        }
        
        ll a_ = half(a, d/2);
        a = build(a_);

        if (A <= a && a <= B) {
            ans += a;
        }

        a_ = half(a, d/2)+1;
        a = build(a_);
    }

    return ans;
}

int main (void) {
    ios_base::sync_with_stdio(false);

    cin >> s;
    n = s.size();

    int i = 0;
    ll ans = 0;
    for (int j = 1; j < n; j++) {
        if (s[j] == ',') {
            ans += go(i, j);
            i = j+1;
        }
    }

    ans += go(i, n);
    cout << ans << endl;

    return 0;
}

