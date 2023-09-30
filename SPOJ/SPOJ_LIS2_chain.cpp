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
int x[N], y[N], n;
 
struct chain{
    map<int, int> m;
 
    chain(){}
 
    bool get(int x, int y){
        map<int, int>::iterator it = m.lower_bound(x);
 
        if(it == m.begin())
            return false;
        it--;
        
        if(it->se >= y)
            return false;
 
        return true;
    }
 
    void add(int x, int y){
        map<int, int>::iterator l, r;
        l = r = m.upper_bound(x);
 
        while(r != m.end() and y <= r->se)
            r++;
 
        m.erase(l, r);
        if(!m.count(x))
            m[x] = y;
        m[x] = min(m[x], y);
    }
} v[N];
 
int main (void) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", x+i, y+i);
 
    v[1].add(x[0], y[0]);
    int ans = 1;
    for(int i = 1; i < n; i++){
 
        int bot = 1, top = ans;
        int val = 0;
        while(bot <= top){
            int mid = (bot+top)>>1;
 
            if(v[mid].get(x[i], y[i])){
                val = mid;
                bot = mid+1;
            } else {
                top = mid-1;
            }
        }
 
        v[val+1].add(x[i], y[i]);
        ans = max(ans, val+1);
    }
 
    printf("%d\n", ans);
 
	return 0;
}
