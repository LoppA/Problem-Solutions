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
bool vis[N];
int n, m;
vector<pair<int, int> > g[N];    // (adjacente, tempo)

void dfs(int at, int time) {
    vis[at] = 1;
    if(at == n - 1)
        return;
    
    for(int i = 0; i < (int)g[at].size(); i++) {
        int next = g[at][i].fi;
        int porta_explode = g[at][i].se;
        if(vis[next] or porta_explode > time)  continue;
        dfs(next, time);
    }
}

// true: chegou no n-1 
// false: n chega
bool magic(int time) {
    memset(vis, false, sizeof vis);
    dfs(0, time);
    return vis[n-1];
}

int main (void) {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    while(m--) {
        int a, b, c;    cin >> a >> b >> c;
        g[a].eb(b, c);
        g[b].eb(a, c);
    }
    
    int bot = 0, top = 1e9;
    int ans;
    while(bot <= top) {
        int mid = (bot + top)>>1;
        if(magic(mid)) {
            ans = mid;
            top = mid - 1;
        } else {
            bot = mid + 1;
        }
    }
    
    cout << ans << endl;

	return 0;
}
