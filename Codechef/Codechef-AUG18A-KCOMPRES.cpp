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
int n, a[N];
ll s;
vector<int> pos[N];
 
int b[N];
int seg[4*N+1];
 
int A, B;
int query(int r, int i, int j, int val) {
    if(j < A or i > B)  return 0;
 
    if(i >= A and j <= B) {
        if(val != INF)
            seg[r] = val;
        return seg[r];
    } else {
        int mid = (i+j)>>1;
 
        int L = query(2*r, i, mid, val);
        int R = query(2*r+1, mid+1, j, val);
 
        seg[r] = max(seg[2*r], seg[2*r+1]);
        return max(L, R);
    }
}
 
int query(int l, int r) {
    A = l;
    B = r;
    return query(1, 0, N-1, INF);
}
 
void update(int p, int val) {
    A = B = p;
    query(1, 0, N-1, val);
}
 
ll go(int k) {
    memset(seg, 0, sizeof seg);
    ll sum = 0;
 
    for(int i = 0; i < n; i++) {
        int l = 0;
        while(l < (int)pos[i].size()) {
            int r = l;
            while(r+1 < (int)pos[i].size() and pos[i][r+1]-pos[i][r] <= k)
                r++;
 
            int val = query(pos[i][l] - k, pos[i][r] + k);
 
            for(int j = l; j <= r; j++) {
                b[pos[i][j]] = val+1;
                update(pos[i][j], val+1);
                sum += val+1;
            }
 
            l = r+1;
        }
    }
 
    return sum;
}
 
void go() {
    for(int i = 0; i < N; i++)
        pos[i].clear();
 
    vector<int> v;
    map<int, int> m;
 
    for(int i = 0; i < n; i++)
        v.pb(a[i]);
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for(int i = 0; i < (int)v.size(); i++)
        m[v[i]] = i;
    for(int i = 0; i < n; i++) 
        pos[m[a[i]]].pb(i);
 
    int bot = 0, top = n;
    int ans = -1;
    while(bot <= top) {
        int mid = (bot + top)>>1;
        if(go(mid) <= s) {
            ans = mid;
            bot = mid+1;
        } else {
            top = mid-1;
        }
    }
 
    cout << ans+1 << endl;
}
 
int main (void) {
	ios_base::sync_with_stdio(false);
 
    int T;  cin >> T;
    while(T--) {
        cin >> n >> s;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        go();
    }
 
	return 0;
}
