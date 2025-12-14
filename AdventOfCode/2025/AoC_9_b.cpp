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

const int N = 1000;

class Point {
public:
    ll x;
    ll y;

    int a;
    int b;

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

    bool operator == (const Point &p) const {
        return a == p.a && b == p.b;
	}

    bool operator != (const Point &p) const {
        return !(*this == p);
	}

    ll rect(const Point &p) {
        auto side = [](ll a, ll b) -> ll {
            return abs(a-b) + 1;
        };
        return side(x, p.x) * side(y, p.y);
    }

    void print () const {
        cout << x << " " << y << " | " << a << " " << b << endl;
    }

};

map<ll, int> id;
map<int, ll> rid;

const int OUT = 2;
int g[N][N];

void fill(int i, int j) {
    if (i < 0 or i >= N or j < 0 or j >= N) {
        return;
    }
    if (g[i][j]) {
        return;
    }

    g[i][j] = OUT;

    fill(i+1, j);
    fill(i-1, j);
    fill(i, j+1);
    fill(i, j-1);
}

bool check(const Point &p, const Point &q) {
    int x1 = min(p.a, q.a);
    int x2 = max(p.a, q.a);

    int y1 = min(p.b, q.b);
    int y2 = max(p.b, q.b);

    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            if (g[i][j] == OUT) {
                return false;
            }
        }
    }

    return true;
}

int main (void) {
    ios_base::sync_with_stdio(false);


    string s;
    vector<Point> v;
    vector<int> vals;
    while(cin >> s) {
        v.emplace_back(s);
        vals.pb(v.back().x);
        vals.pb(v.back().y);
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    for (int i = 0; i < (int)vals.size(); i++) {
        int l = vals[i], r = i+1;
        id[l]= r;
        rid[r] = l; 
    }

    for (auto &p : v) {
        p.a = id[p.x];
        p.b = id[p.y];
    }

    for (int i = 0; i < (int)v.size(); i++) {
        int j = i == 0 ? (int)v.size() - 1 : i-1;
        const Point &p = v[j];
        const Point &q = v[i];

        int dx = 0, dy = 0;

        if (p.a == q.a) {
            dx = 0;

            int diff = q.b-p.b;
            dy = diff/abs(diff);
        } else {
            assert(p.b == q.b);
            dy = 0;

            int diff = q.a-p.a;
            dx = diff/abs(diff);
        }

        Point curr = p;
        do {
            g[curr.a][curr.b] = 1;
            curr.a += dx;
            curr.b += dy;
        } while(curr != q);
    }

    fill(0, 0);

    ll ans = 0;
    for (int i = 0; i < (int)v.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (check(v[i], v[j])) {
                ans = max(ans, v[i].rect(v[j]));
            }
        }
    }

    cout << ans << endl;

    return 0;
}

