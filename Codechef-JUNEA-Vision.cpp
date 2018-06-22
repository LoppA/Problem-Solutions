/* Codechef JUNE18A Vision*/
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

struct Point {
	double x, y, z;

	Point() {}

	Point(double x, double y, double z) : x(x), y(y), z(z) {}

	void read() {
		scanf("%lf %lf %lf", &x, &y, &z);
	}

	Point operator * (const double t) const {
		return {x*t, y*t, z*t};
	}

	Point operator + (const Point &B) const {
		return {x+B.x, y+B.y, z+B.z};
	}

	Point operator - (const Point &B) const {
		return {x-B.x, y-B.y, z-B.z};
	}

	double operator * (const Point &B) const {
		return x*B.x + y*B.y + z*B.z;
	}

	double len() {
		return sqrt((*this)*(*this));
	}

	double dist(const Point &B) {
		return (B - (*this)).len();
	}

	void print() const {
		cout << x << " " << y << " " << z << endl;
	}
};

Point p, q, d, c;
double r;

bool dist(const Point &a, const Point &b, const Point &p, const double r) {
/*	a.print();
	b.print();
	p.print();
*/
	Point ab = b - a;
	Point ap = p - a;

	double prj = (ap*ab) / ab.len();
	prj /= ab.len();

	if(prj < 0 or prj > 1.0) 
		return true;

	Point c = a + (ab*prj);

	return c.dist(p) > r;
}

int main (void) {

	int T;	scanf("%d", &T);
	while(T--) {
		p.read();
		q.read();
		d.read();
		c.read();
		scanf("%lf", &r);

		double bot = 0.0, top = 1e9 + 1234;
		double ans = -1;
		int t = 300;
		while(t--) {
			double mid = (bot + top)/2.0;

			if(dist(p, q + (d*mid), c, r)) {
				ans = mid;
				top = mid;
			} else {
				bot = mid;
			}
		}

		printf("%.12lf\n", ans);
	}

	return 0;
}
