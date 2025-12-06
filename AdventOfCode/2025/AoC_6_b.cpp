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

bool simb(char c) {
    return c == '*' || c == '+';
}

int parse(string s, size_t &i) {
    auto ctoi = [] (char c) -> int {
        return c-'0';
    };

    const size_t n = s.size();
    while(i < n && s[i] == ' ') {
        i++;
    }

    int x = 0;
    while(i < n && s[i] != ' ') {
        x = x*10 + ctoi(s[i++]);
    }

    while(i < n && s[i] == ' ') {
        i++;
    }

    return x;
}

char getOp(string s, size_t &i) {
    const size_t n = s.size();

    while(i < n && s[i] == ' ') {
        i++;
    }

    assert(i < n);
    char c = s[i++];

    while(i < n && s[i] == ' ') {
        i++;
    }

    return c;
}

vector<vector<char>> line;

int main (void) {
    ios_base::sync_with_stdio(false);

    string s;
    while(getline(cin, s) && !simb(s[0])) {
        line.pb(vector<char>(s.begin(), s.end()));
    }

    ll ans = 0;
    size_t i = 0;
    for (size_t j = 0; j < s.size();) {
        auto parse = [](size_t i, ll &x) -> bool {
            auto ctoi = [] (char c) -> int {
                return c-'0';
            };
            const size_t n = line.size();
            x = 0;
            bool f = false;
            for (size_t j = 0; j < n; j++) {
                if (line[j][i] != ' ') {
                    x = x*10 + ctoi(line[j][i]);
                    f = true;
                }
            }

            return f;
        };

        char op = getOp(s, j);
        ll r = (op == '+') ? 0 : 1;
        ll x;
        while(i < line[0].size() && parse(i++, x)) {
            if (op == '+') {
                r += x;
            } else {
                r *= x;
            }
        }
        ans += r;
    }

    cout << ans << endl;

    return 0;
}

