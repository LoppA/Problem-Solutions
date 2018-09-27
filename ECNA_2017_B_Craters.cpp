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

const double EPS = 1e-9;

const int N = 212;

struct point {
    double x, y;
    int id;

    point() {}
    point(double x, double y) : x(x), y(y) {}
    point(double x, double y, int id) : x(x), y(y), id(id) {}

    point operator -(const point &b) const {
        return {x-b.x, y-b.y};
    }

    point operator +(const point &b) const {
        return {x+b.x, y+b.y};
    }

    double operator ^(const point &b) const {
        return x*b.y - y*b.x;
    }

    double operator *(const point &b) const {
        return x*b.x + y*b.y;
    }

    double operator <(const point &b) const {
        if(x != b.x)  return x < b.x;
        return y < b.y;
    }

    point operator *(double k) const  {
        return {x*k, y*k};
    }

    double len() {
        return sqrt(x*x + y*y);
    }

    double dist(const point &b) const {
        double dx = x-b.x;
        double dy = y-b.y;
        return sqrt(dx*dx + dy*dy);
    }
    
    double dist2(const point &b) const {
        double dx = x-b.x;
        double dy = y-b.y;
        return dx*dx + dy*dy;
    }

    point rot(double ang) {
        double c = cos(ang), s = sin(ang);
        return {x*c - y*s, x*s + y*c};
    }
};

struct circle {
    point c;
    double r;

    circle() {}
    circle(double x, double y, double r) : c(x,y), r(r) {}

    void read() {
        scanf("%lf %lf %lf", &c.x, &c.y, &r);
        r += 10.0;
    }

    bool operator <(const circle &b) const {
        return r > b.r;
    }
} c[N];

static vector <point> ch(vector <point> p) {
	if (p.size() <= 2) return p;

	int n = p.size(), k = 0;
	vector <point> H(2*n);

	sort(p.begin(), p.end());

	for (int i = 0; i < n; i++) {
		while (k >= 2 and ((H[k-1]-H[k-2])^(p[i]-H[k-2])) <= 0.0) k--;
		H[k++] = p[i];
	}

	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t and ((H[k-1]-H[k-2])^(p[i]-H[k-2])) <= 0.0) k--;
		H[k++] = p[i];
	}

	H.resize(k-1);

	return H;
}

vector<point> v;
void tan(circle a, circle b, int ida, int idb) {
    if(a.r < b.r) {
        swap(a, b);
        swap(ida, idb);
    }
    if(abs(a.r-b.r) < EPS) {
        double dist = a.c.dist(b.c);
        point vv = a.c-b.c;
        vv = point(vv.y, -vv.x);

        double len_ratio = a.r / dist;
        v.pb(a.c + vv*len_ratio);
        v.rbegin()->id = ida;
        v.pb(a.c - vv*len_ratio);
        v.rbegin()->id = ida;

        len_ratio = b.r / dist;
        v.pb(b.c + vv*len_ratio);
        v.rbegin()->id = idb;
        v.pb(b.c - vv*len_ratio);
        v.rbegin()->id = idb;

        return;
    }

    double dist = a.c.dist(b.c);
    double h = (dist * a.r) / (a.r - b.r);

    point p = a.c + ((b.c - a.c) * (h / dist));

    double len_ratio = sqrt(h*h - a.r*a.r) / h;
    v.pb( p + (a.c-p).rot(asin(a.r/h))*len_ratio);
    v.rbegin()->id = ida;
    v.pb( p + (a.c-p).rot(-asin(a.r/h))*len_ratio );
    v.rbegin()->id = ida;

    len_ratio = sqrt((h-dist)*(h-dist) - b.r*b.r) / (h-dist);
    v.pb( p + (b.c-p).rot(asin(b.r/(h-dist)))*len_ratio );
    v.rbegin()->id = idb;
    v.pb( p + (b.c-p).rot(-asin(b.r/(h-dist)))*len_ratio );
    v.rbegin()->id = idb;
}

bool dentro(const circle &a, const circle &b) {
    double d2 = a.c.dist2(b.c);
    return d2 <= (a.r-b.r)*(a.r-b.r);
}

double go(const point &a, const point &b) {
    if(a.id != b.id) 
        return a.dist(b);

    point u = a - c[a.id].c;
    point v = b - c[b.id].c;

    double ret = 2.0*PI*c[a.id].r;

    double ang = (u*v)/(u.len()*v.len());
    ang = acos(ang);
    double ratio = ang / (PI*2.0);

    if((u^v) < 0)
        ratio = 1-ratio;

    return ratio * ret;
}

int n;
bool fora[N];

int main (void) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        c[i].read();
    sort(c, c+n);

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += !fora[i];
        for(int j = i+1; j < n; j++) 
            if(dentro(c[i], c[j]))
                fora[j] = true;
    }

    if(cnt == 1) {
        for(int i = 0; i < n; i++)
            if(!fora[i])
                printf("%.14lf\n", 2.0*PI*c[i].r);
        return 0;
    }

    for(int i = 0; i < n; i++) {
        if(fora[i]) continue;
        for(int j = i+1; j < n; j++) {
            if(fora[j]) continue;
            tan(c[i], c[j], i, j);
        }
    }

    vector<point> vv;

    for(point p : v) {
        bool f = true;

        for(int i = 0; i < n; i++) {
            if(p.id == i)   continue;
            if(p.dist2(c[i].c) <= c[i].r*c[i].r)
                f = false;
        }

        if(f)
            vv.pb(p);
    }
    
    vector<point> h = ch(vv);

    double ans = 0;
    for(int i = 0; i < (int)h.size(); i++) {
        int j = (i+1)%h.size();
        ans += go(h[i], h[j]);
    }

    printf("%.14lf\n", ans);

	return 0;
}
