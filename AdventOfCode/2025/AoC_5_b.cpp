#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef __int128 LL;
typedef pair<ll, ll> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main (void) {
    ios_base::sync_with_stdio(false);

    auto parse = [](const string &s, int &i) -> ll {
        auto ctoi = [](char c) -> int {
            return c-'0';
        };

        ll x = 0;
        while(i < (int)s.size() && s[i] != '-') {
            x = x*10 + ctoi(s[i++]);
        }
        i++;
        return x;
    };

    string s;
    vector<ii> ev;
    while(getline(cin, s) && s.size()) {
        int i = 0;
        ll a = parse(s, i);
        ev.emplace_back(a, 0);
        ll b = parse(s, i);
        ev.emplace_back(b, 1);
    }
    sort(ev.begin(), ev.end());
    ll prev = 0;
    ll acc = 0;
    ll ans = 0;
    for (ii e : ev) {
        if (acc == 0) {
            assert(e.se == 0);
            prev = e.fi;
        }

        acc += !e.se ? 1 : -1;

        if (acc == 0) {
            assert(e.se == 1);
            ans += e.fi - prev + 1;
        }
    }

    cout << ans << endl;

    return 0;
}

