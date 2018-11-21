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

const int N = 3e4 + 4;
int n, a[N];
vector<int> v;
int seg[4*N+1];

int A, B;
int query(int r, int i, int j, int val){
    if(v[j] < A or v[i] > B)  return 0;

    if(v[i] >= A and v[j] <= B){
        seg[r] = max(seg[r], val);
        return seg[r];
    } else {
        int mid = (i+j)>>1;

        int L = query(2*r, i, mid, val);
        int R = query(2*r+1, mid+1, j, val);

        seg[r] = max(seg[2*r], seg[2*r+1]);
        return max(L, R);
    }
}

int query(int l, int r){
    A = l;  B = r;
    return query(1, 0, v.size()-1, 0);
}

void update(int l, int r, int val){
    A = l;  B = r;
    query(1, 0, v.size()-1, val);
}

int main (void) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", a+i);
        v.pb(a[i]);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());

    int ans = 0;
    for(int i = 0; i < n; i++){
        int len = query(0, a[i]-1);

        update(a[i], a[i], len+1);
        ans = max(ans, len+1);

/*        for(auto it : v)
            cout << query(it, it) << " ";   cout << endl;
*/    }

    printf("%d\n", ans);

	return 0;
}
