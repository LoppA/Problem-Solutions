#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef __int128 LL;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

void print(ll x) {
    string s;

    while(x) {
        s += (x&1 ? '1' : '0');
        x >>= 1;
    }

    reverse(s.begin(), s.end());
    cout << s << endl;
}

int main (void) {
	ios_base::sync_with_stdio(false);

    ll A;
    ll B = 0, C = 0;
    cin >> A;

    print(A);

    while(A) {
        B = A&7;
        B = B^5;
        C = A>>B;
        C = C&7;
        A = A>>3;
        B = B^6;
        B = B^C;
        cout << B << ",";
    }
    cout << endl;

	return 0;
}
