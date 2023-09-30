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

const int N = 1e5 + 5, L = 62;
int n;
ll v[N];
bool vis[N];

int main (void) {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) 
		scanf("%lld", v+i);

	ll ans = 0;
	sort(v, v+n);
	reverse(v, v+n);

	vector<ll> vv;
	for(int i = L; i >= 0; i--) {
		for(int j = 0; j < n; j++) {
			if(!vis[j] and (v[j]>>i)&1) {
				for(int k = 0; k < n; k++) 
					if(k != j and (v[k]>>i)&1) 
						v[k] ^= v[j];
				vv.pb(v[j]);
				vis[j] = 1;
				break;
			}
		}
	}

	for(auto it : vv) 
		if((ans^it) > ans)
			ans ^= it;


	printf("%lld\n", ans);

	return 0;
}
