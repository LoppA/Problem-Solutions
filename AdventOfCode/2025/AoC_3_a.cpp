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

int main (void) {
    ios_base::sync_with_stdio(false);

    auto ctoi = [](char c) -> int {
        return c-'0';
    };

    string s;
    ll ans = 0;
    while(cin >> s) {
        auto c = s.begin();
        char a = *(c++);
        int val = 0;
        while (c != s.end()) {
            char &b = *(c++);
            val = max(val, ctoi(a)*10 + ctoi(b));
            if (b > a) {
                a = b;
            }
        }
        ans += val;
    }

    cout << ans << endl;

    return 0;
}

