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
int n, q, v[N];
vector<int> seg[4*N + 1];
 
void build(int r, int i, int j){
	seg[r].resize(j - i + 1);
 
	if(i == j){
		seg[r][0] = v[i];
	} else {
		int mid = (i+j)>>1;
		build(2*r, i, mid);
		build(2*r+1, mid+1, j);
 
		merge(seg[2*r].begin(), seg[2*r].end(),
		seg[2*r+1].begin(), seg[2*r+1].end(), seg[r].begin());
	}
}
 
int a, b;
int query(int r, int i, int j, int val){
	if(j < a or i > b)	return 0;
 
	if(i >= a and j <= b){
		return upper_bound(seg[r].begin(), seg[r].end(), val) - seg[r].begin();
	} else {
		int mid = (i+j)>>1;
 
		int L = query(2*r, i, mid, val);
		int R = query(2*r+1, mid+1, j, val);
 
		return L + R;
	}
}
 
int main (void) {
 
	scanf("%d", &n);
	scanf("%d", &q);
	for(int i = 0; i < n; i++)
		scanf("%d", v+i);
 
	build(1, 0, n-1);
 
	while(q--){
		int k;	scanf("%d %d %d", &a, &b, &k);
		a--;	b--;
 
		int bot = -INF, top = INF;
		int ans;
		while(bot <= top){
			int mid = (bot+top)>>1;
 
			if(query(1, 0, n-1, mid) < k){
				bot = mid + 1;
			} else {
				ans = mid;
				top = mid - 1;
			}
		}
		printf("%d\n", ans);
	}
 
	return 0;
}
