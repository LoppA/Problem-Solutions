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

const int N = 1<<11;
int v[8][8];

void print(int x, bool f = true, int sz = 3) {
    string s;

    while(x) {
        s += (x&1 ? '1' : '0');
        x >>= 1;
    }

    while((int)s.size() < sz) {
        s += '0';
    }

    reverse(s.begin(), s.end());
    cout << s << (f ? '\n' : ' ');
}

 void go(int A) {
    const int AA = A;
    int B = 0, C = 0;

    int i, j;

    B = A&7;
    B = B^5;
    C = A>>B;
    C = C&7;
    j = C;
    A = A>>3;
    B = B^6;
    B = B^C;
    i = B;

    v[i][j] = min(v[i][j], AA);
}

int main (void) {
	ios_base::sync_with_stdio(false);

    cout << N << " ";
    print(N);

    memset(v, INF, sizeof v);
    for (int i = 1; i < N; i++) {
        go(i);
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            print(i, false);
            print(j, false);
            print(v[i][j], false, 10);
            cout << "| " << i << " " << j << " " << v[i][j] << endl;
        }
    }

	return 0;
}
