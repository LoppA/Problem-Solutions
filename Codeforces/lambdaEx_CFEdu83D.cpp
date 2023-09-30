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
     
    const ll mod = 998244353;
    const int N = 2e5 + 123;
    ll fat[N];
    ll n, m;
     
    ll pot (ll x, ll y) {
    	ll ret = 1;
     
    	while (y) {
    		if (y & 1)
    			ret = (ret * x)%mod;
     
    		x = (x * x)%mod;
    		y >>= 1;
    	}
     
    	return ret;
    }
     
    int main (void) {
    	ios_base::sync_with_stdio(false);
     
    	fat[0] = 1;
    	for(ll i = 1; i < N; i++)
    		fat[i] = (fat[i-1] * i)%mod;
     
    	cin >> n >> m;
     
    	if(n == 2) {
    		cout << 0 << endl;
    		return 0;
    	}
     
    	auto choose = [](ll n, ll k) {
    		if(k > n)	return 0LL;
    		ll ret = (fat[n] * pot(fat[n-k], mod-2))%mod;
    		return (ret * pot(fat[k], mod-2))%mod;
    	};
     
    	ll ans = (pot(2, n-3) * (n-2))%mod;
    	ans = (ans * choose(m, n-1))%mod;
     
    	cout << ans << endl;
     
    	return 0;
    }
