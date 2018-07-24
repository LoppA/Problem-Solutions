#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

struct point {
	ll x, y, id;

	point() {}

	point(ll x, ll y, ll id) : x(x), y(y), id(id) {}

	point operator - (const point &B) const {
		return {x-B.x, y-B.y, 0};
	}

	ll operator * (const point &B) const {
		return x*B.x + y*B.y;
	}

	ll operator ^ (const point &B) const {
		return x*B.y - y*B.x;
	}

	ll len2() const {
		return (*this)*(*this);
	}

	bool operator < (const point &B) const {
		if(x != B.x)
			return x < B.x;
		if(y != B.y)
			return y < B.y;
		return id < B.id;
	}
} v[8];

bool ret(const point &a, const point &b, const point &c, const point &d) {
	if((b-a)^(d-c))
		return false;

	if((c-a)^(d-b))
		return false;

	if((b-a)*(c-a))
		return false;

	return true;
}

bool quad(const point &a, const point &b, const point &c, const point &d) {
	if(!ret(a, b, c, d))
		return false;

	if((b-a).len2() != (c-a).len2())
		return false;

	return true;
}

int main (void) {
	ios_base::sync_with_stdio(false);

	for(int i = 0; i < 8; i++) {
		cin >> v[i].x >> v[i].y;
		v[i].id = i+1;
	}

	sort(v, v+8);
	do {
		if(quad(v[0], v[1], v[2], v[3]) and ret(v[4], v[5], v[6], v[7])) {
			cout << "YES" << endl;
			for(int i = 0; i < 4; i++)
				cout << v[i].id << " \n"[i==3];
			for(int i = 4; i < 8; i++)
				cout << v[i].id << " \n"[i==7];
			return 0;
		}
	} while(next_permutation(v, v+8));

	cout << "NO" << endl;

	return 0;
}
