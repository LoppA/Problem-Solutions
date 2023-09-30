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
 
const int N = 2e5 + 5;
int n, m;
set<ii> cicle;
vector<ii> g[N];
vector<ii> edg;
int vis[N], pai[N];
 
void ciclo(int a, int b) {
    cicle.emplace(a, b);
    for(auto &it : g[a]) 
        if(edg[it.fi].se == b)
            it.se = 1;
 
    cicle.emplace(b, a);
    for(auto &it : g[b]) 
        if(edg[it.fi].se == a)
            it.se = 1;
}
 
void go(int at) {
    vis[at] = 1;
 
    for(auto it : g[at]) {
        int next =  edg[it.fi].se;
        if(next == pai[at]) continue;
 
        if(!vis[next]) {
            pai[next] = at;
            go(next);
        } else if(vis[next] == 1) {
            int u = at;
 
            ciclo(u, next);
            while(u != next) {
                ciclo(u, pai[u]);
                u = pai[u];
            }
        }
    }
 
    vis[at] = 2;
}
 
ll go(int at, int pai, int cnt) {
    ll r = 1;
 
    for(auto it : g[at]) {
        int next = edg[it.fi].se;
 
        if(next == pai)
            continue;
 
        if(cnt + it.se <= 1) 
            r += go(next, at, cnt + it.se);
    }
 
    return r;
}
 
ll *dp;
ll go(int id, int cnt) {
    ll &r = dp[edg.size() * cnt + id];
    if(r != -1)
        return r;
 
    r = 1;
 
    int u = edg[id].fi;
    int v = edg[id].se;
 
    for(auto it : g[v]) {
        int next = edg[it.fi].se;
        if(next == u)   continue;
 
        if(cnt + it.se <= 1)
            r += go(it.fi, cnt + it.se);
    }
 
    return r;
}
 
int main (void) {
 
    int T;  scanf("%d", &T);
    while(T--) {
        for(int i = 1; i <= n; i++)
            g[i].clear();
        edg.clear();
        cicle.clear();
        memset(vis, 0, sizeof vis);
 
        scanf("%d %d", &n, &m);
        for(int i = 0; i < m; i++) {
            int a, b;   scanf("%d %d", &a, &b);
            g[a].eb(edg.size(), 0);
            edg.eb(a, b);
            g[b].eb(edg.size(), 0);
            edg.eb(b, a);
        }
 
        for(int i = 1; i <= n; i++)
            if(!vis[i])
                go(i);
/*
        for(int i = 1; i <= n; i++) 
            for(auto it : g[i])
                cout << i << " " << it.fi << " " << it.se << endl;
        cout << endl;
*/
        dp = new ll[2*edg.size()];
        for(int i = 0; i < 2 * (int)edg.size(); i++)
            dp[i] = -1;
        for(int i = 0; i < (int)edg.size(); i+=2) {
            auto it = edg[i];
            ll res = 0;
            if(cicle.count(it)) {
                //res = (go(it.fi, it.se, 1)) * go(it.se, it.fi, 1);
                res = (go(i, 1)) * go(i+1, 1);
            } else {
                //res = (go(it.fi, it.se, 1)) * go(it.se, it.fi, 0);
                res = (go(i, 1)) * go(i+1, 0);
                //res += (go(it.fi, it.se, 0) - go(it.fi, it.se, 1)) * go(it.se, it.fi, 1);
                res += (go(i, 0) - go(i, 1)) * go(i+1, 1);
            }
 
            printf("%lld\n", res);
        }
        delete[] dp;
    }
 
	return 0;
}
