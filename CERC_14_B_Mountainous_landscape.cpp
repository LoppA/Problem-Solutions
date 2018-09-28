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

const int N = 1e5 + 5;
struct point {
    ll x, y;

    point() {}
    point(ll x, ll y) : x(x), y(y) {}

    point operator -(const point &b) const {
        return {x-b.x, y-b.y};
    }

    ll operator ^(const point &b) const {
        return x*b.y - y*b.x;
    }

    void read() {
        scanf("%lld %lld", &x, &y);
    }
} p[N];

int n;

vector<point> seg[4*N+1];

vector<point> ch(int l, int r) {
    vector<point> h(r-l+1);
    int k = 0;

    for(int i = l; i <= r; i++) {
        while(k >= 2 and ((h[k-1]-h[k-2])^(p[i]-h[k-2])) >= 0) k--;
        h[k++] = p[i];
    }

    h.resize(k);

    return h;
}

void build(int r, int i, int j) {
    seg[r] = ch(i, j);
    if(i == j) 
        return;

    int mid = (i+j)>>1;
    build(2*r, i, mid);
    build(2*r+1, mid+1, j);
}

int a, b;
point p1, p2;

bool go(int r) {
    vector<point> &h = seg[r];
    int id = 0;
    int bot = 1, top = h.size() - 1;

    while(bot <= top) {
        int mid = (bot+top)>>1;

        if(((p2-p1)^(h[mid]-h[mid-1])) > 0) {
            id = mid;
            bot = mid+1;
        } else {
            top = mid-1;
        }
    }

    return ((p2-p1)^(h[id]-p1)) > 0;
}

int query(int r, int i, int j) {
    if(j < a or i > b)  return 0;

    if(i == j) {
        if(((p2-p1)^(p[i]-p1)) > 0)
            return i;
        return 0;
    }

    if(i >= a and j <= b) {
        if(!go(r))
            return 0;

        int mid = (i+j)>>1;
        int L = query(2*r, i, mid);
        if(L)   return L;
        return query(2*r+1, mid+1, j);
    } else {
        int mid = (i+j)>>1;
        int L = query(2*r, i, mid);
        if(L)   return L;
        return query(2*r+1, mid+1, j);
    }
}

int main (void) {

    int T;  scanf("%d", &T);
    while(T--) {
        for(int i = 0; i < 4*N + 1; i++)
            seg[i].clear();

        scanf("%d", &n);
        for(int i = 0; i < n; i++) 
            p[i].read();

        build(1, 0, n-1);

        for(int i = 1; i < n; i++) {
            a = i+1;
            b = n-1;
            p1 = p[i-1];
            p2 = p[i];
            int ans = query(1, 0, n-1);
            printf("%d ", ans);
        }
        printf("\n");
    }

	return 0;
}
