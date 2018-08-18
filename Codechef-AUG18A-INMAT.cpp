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

const int N = 1e3 + 3;
int n, k, v;
int a[N][N], lin[N], col[N];
bool vis[N][N][2];
vector<ii> vlin[N], vcol[N];

set<ii> s;

int seg[4*N*N + 1];

void build(int r, int i, int j) {
    if(i == j) {
        seg[r] = 1;
    } else {
        int mid = (i+j)>>1;

        build(2*r, i, mid);
        build(2*r+1, mid+1, j);

        seg[r] = seg[2*r] + seg[2*r+1];
    }
}

void update(int r, int i, int j, int p) {
    if(j < p or i > p)  return;

    if(i == j) {
        seg[r] = 0;
    } else {
        int mid = (i+j)>>1;

        update(2*r, i, mid, p);
        update(2*r+1, mid+1, j, p);
        
        seg[r] = seg[2*r] + seg[2*r+1];
    }
}

void update(int p) {
    update(1, 0, n*n-1, p);
}

ii getrand(int r, int i, int j) {
    if(!seg[r]) return ii(-1, -1);

    if(i == j) {
        return ii(i/n, i%n);
    } else { 
        int mid = (i + j)>>1;

        int val = rand()%seg[r];

        if(val < seg[2*r]) 
            return getrand(2*r, i, mid);
        else 
            return getrand(2*r+1, mid+1, j);
    }
}

ii getrand() {
    return getrand(1, 0, n*n-1);
}

void finish(int r, int c) {
    cout << "2 " << r+1 << " " << c+1 << endl;
    exit(0);
}

int ask(int r, int c) {
    assert(!s.count(ii(r, c)));
    s.emplace(r, c);
    update(r*n + c);
    cout << "1 " << r+1 << " " << c+1 << endl;
    int x;  cin >> x;
    if(x == v)  finish(r, c);
    return x;
}

void go(int i, int j, bool f) {
    if(i < 0 or j < 0 or i >= n or j >= n)
        return;

    if(vis[i][j][f])
        return;

    vis[i][j][f] = true;

    update(i*n + j);

    if(f) {
        go(i, j + lin[i], f);
        go(i + col[j], j, f);
    } else {
        go(i, j - lin[i], f);
        go(i - col[j], j, f);
    }
}

int main (void) {
	ios_base::sync_with_stdio(false);

    srand(time(NULL));

    cin >> n >> k >> v;

    if(n == 1) {
        ask(0, 0);
        finish(-2, -2);
    }

    build(1, 0, n*n-1);

    for(int i = 0; i < n; i++) {
        int j = i;
        a[i][j] = ask(i, j);

        vlin[i].eb(j, a[i][j]);
        vcol[j].eb(i, a[i][j]);

        j = n-1-i;
        if(i == j) {
            i++;
            a[i][j] = ask(i, j);
            vlin[i].eb(j, a[i][j]);
            vcol[j].eb(i, a[i][j]);
            i--;

            j++;
            a[i][j] = ask(i, j);
            vlin[i].eb(j, a[i][j]);
            vcol[j].eb(i, a[i][j]);
        } else {
            a[i][j] = ask(i, j);
            vlin[i].eb(j, a[i][j]);
            vcol[j].eb(i, a[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        sort(vlin[i].begin(), vlin[i].end());
        sort(vcol[i].begin(), vcol[i].end());

        if(vlin[i][0].se < vlin[i][1].se) lin[i] = 1;
        else    lin[i] = -1;

        if(vcol[i][0].se < vcol[i][1].se) col[i] = 1;
        else    col[i] = -1;
    }

    while(true) {
        ii q = getrand();

        if(q == ii(-1, -1))
            finish(-2, -2);

        int i = q.fi, j = q.se;
        a[i][j] = ask(i, j);

        go(i, j, a[i][j] > v);
    }

    finish(-2, -2);

	return 0;
}
