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

class Point {
public:
    ll x;
    ll y;

    Point(const string &s) {
        auto parse = [] (const string &s, size_t &i) -> ll {
            auto ctoi = [] (const char c) -> int {
                return c-'0';
            };

            int x = 0;
            while(i < s.size() && s[i++] != ',') {
                x = x*10 + ctoi(s[i-1]);
            }
            return x;
        };

        size_t i = 0;
        this->x = parse(s, i);
        this->y = parse(s, i);
    }

    ll rect(const Point &p) {
        auto side = [](ll a, ll b) -> ll {
            return abs(a-b) + 1;
        };
        return side(x, p.x) * side(y, p.y);
    }

};

int main (void) {
    ios_base::sync_with_stdio(false);


    string s;
    ll ans = 0;
    vector<Point> v;
    while(cin >> s) {
        Point p(s);

        for (const Point &q : v) {
            ans = max(ans, p.rect(q));
        }

        v.pb(p);
    }

    cout << ans << endl;

    return 0;
}

