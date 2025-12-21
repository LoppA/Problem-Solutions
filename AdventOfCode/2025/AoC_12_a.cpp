// Following advice at https://www.reddit.com/r/adventofcode/comments/1pkjynl/comment/ntlq9n3/?utm_source=share&utm_medium=web3x&utm_name=web3xcss&utm_term=1&utm_content=share_button
// Thanks u/fireymike

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

int ctoi(char c) {
    return c-'0';
}

int main (void) {
    ios_base::sync_with_stdio(false);

    vector<int> v;
    string s;
    while(getline(cin, s) && s.size() == 2) {
        int cnt = 0;
        for (int i = 0; i < 3; i++) {
            getline(cin, s);
            for (char c : s) {
                cnt += c=='#';
            }
        }
        v.push_back(cnt);
        getline(cin, s);
    }

    auto parse = [] (const string &s, size_t &i) -> int {
        auto isNumber = [](char c) -> bool {
            return '0' <= c && c <= '9';
        };
        int x = 0;
        while(i < s.size() && isNumber(s[i])) {
            x = x*10 + s[i++]-'0';
        }
        i++;
        return x;
    };

    int ans = 0;
    do {
        int n = ctoi(s[0])*10 + ctoi(s[1]);
        int m = ctoi(s[3])*10 + ctoi(s[4]);

        size_t i = 7;

        int upper = 0, lower = 0;
        int j = 0;
        while(i < s.size()) {
            int x = parse(s, i);
            upper += x*9;
            lower += x*v[j++];
        }

        if (upper <= n*m) {
            ans++;
        } else {
            assert(lower > n*m);
        }
    } while(getline(cin, s));

    cout << ans << endl;

    return 0;
}

