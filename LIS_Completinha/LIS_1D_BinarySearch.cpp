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
int n, a[N], v[N];

int main (void) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", a+i);

    int ans = 1;
    memset(v, INF, sizeof v);
    v[1] = a[0];
    for(int i = 1; i < n; i++){
        int bot = 1, top = ans;
        int len = 1;
        while(bot <= top){
            int mid = (bot+top)>>1;

            if(a[i] > v[mid]){
                len = mid+1;
                bot = mid+1;
            } else {
                top = mid-1;
            }
        }

        v[len] = min(v[len], a[i]);
        ans = max(ans, len);

/*        for(int j = 1; j <= ans; j++)
            cout << v[j] << " ";    cout << endl;
*/    }

    printf("%d\n", ans);

	return 0;
}
