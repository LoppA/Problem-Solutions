#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;

class Point {
public:
    ll x, y, z;

    Point () {}

    Point (ll x, ll y, ll z) : x(x), y(y), z(z) {}

    Point (const string &s) {
        auto parse = [](const string &s, size_t &i) -> int {
            auto ctoi = [](char c) -> int {
                return c-'0';
            };
            int x = 0;
            while(i < s.size() && s[i] != ',') {
                x = x*10 + ctoi(s[i++]);
            }
            i++;
            return x;
        };

        size_t i = 0;
        this->x = parse(s, i);
        this->y = parse(s, i);
        this->z = parse(s, i);
    };

    ll dist2(const Point &p) {
        auto sq = [](ll x) -> ll {
            return x*x;
        };

        return
            sq(x - p.x) +
            sq(y - p.y) +
            sq(z - p.z);
    }
};

class uni {
public:
	vector<int> pai, size;

	uni(int n) {
        pai = vector<int>(n, -1);
        size = vector<int>(n);
		for(int i = 0; i < n; i++)
			size[i] = 1;
	}

	int find (int u) {
		if (pai[u] == -1)
			return u;
		else
			return pai[u] = find(pai[u]);
	}

	bool une (int u, int v) {
		u = find(u);	v = find(v);
		if (u == v) return false;

		if (size[u] < size[v])
			swap(u, v);

		pai[v] = u;
		size[u] += size[v];
		size[v] = 0;
		return size[u] == (int)size.size();
	}
};


vector<Point> v;
typedef tuple<ll, int, int> lii;
priority_queue <lii, vector <lii>, greater<lii> > pq;

int main (void) {
    ios_base::sync_with_stdio(false);

    string s;
    while(cin >> s) {
        Point q(s);

        for (int i = 0; i < (int)v.size(); i++) {
            pq.emplace(q.dist2(v[i]), v.size(), i);
        }

        v.pb(q);
    }

    uni u(v.size());

    while(pq.size()) {
        lii t = pq.top();
        pq.pop();

        int i = std::get<1>(t);
        int j = std::get<2>(t);

        if (u.une(i,j)) {
            ll a = v[i].x;
            ll b = v[j].x;
            cout << a * b << endl;
            return 0;
        }
    }

    assert(0);

    return 0;
}

