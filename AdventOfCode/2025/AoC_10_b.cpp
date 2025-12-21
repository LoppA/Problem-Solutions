// Solution based on this post https://www.reddit.com/r/adventofcode/comments/1pk87hl/2025_day_10_part_2_bifurcate_your_way_to_victory/
// Thanks u/tenthmascot

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

vector<int> parse (const string &s, size_t &i) {
    auto isNumber = [] (const char c) -> bool {
        return '0' <= c && c <= '9';
    };
    auto parseInt = [&] (const string &s, size_t &i) -> int {
        int x = 0;
        while(i < s.size() && isNumber(s[i])) {
            x = x*10 + s[i++]-'0';
        }
        return x;
    };

    vector<int> v;
    while(i < s.size() && s[i] != ')'&& s[i] != '}') {
        if (isNumber(s[i])) {
            v.pb(parseInt(s, i));
        } else {
            i++;
        }
    }

    return v;
};

bool allZero(const vector<int> &v) {
    for (int x : v) {
        if (x != 0) {
            return false;
        }
    }
    return true;
}

bool allEven(const vector<int> &v) {
    for (int x : v) {
        if (x%2 != 0) {
            return false;
        }
    }
    return true;
}

void div(vector<int> &v) {
    for (int &x : v) {
        x /= 2;
    }
}

void mult(vector<int> &v) {
    for (int &x : v) {
        x *= 2;
    }
}

vector<vector<int>> v;
map<vector<int>, int> vis;
int go(vector<int> &curr) {
    for (int x : curr) {
        if (x < 0) {
            return INF;
        }
    }
    if (allZero(curr)) {
        return 0;
    }

    if(vis.count(curr)) {
        return vis[curr];
    }

    int &r = vis[curr];
    r = INF;

    int mm = (1<<v.size());
    for (int k = 0; k < mm; k++) {
        int cnt = 0;
        for (size_t i = 0; i < v.size(); i++) {
            if (k & (1<<i)) {
                for (auto j : v[i]) {
                    curr[j]--;
                }
                cnt++;
            }
        }
        if (allEven(curr)) {
            div(curr);
            r = min(r, 2*go(curr) + cnt);
            mult(curr);
        }
        for (size_t i = 0; i < v.size(); i++) {
            if (k & (1<<i)) {
                for (auto j : v[i]) {
                    curr[j]++;
                }
            }
        }
    }

    return r;
}

int solve(string s) {
    size_t i = 1;
    v.clear();
    vis.clear();

    while(s[i] != ']') {
        i++;
    }
    i++;

    while(s[i] != '{') {
        if (s[i] == '(') {
            v.push_back(parse(s, i));
        }
        i++;
    }

    i++;
    vector<int> vv = parse(s, i);

    return go(vv);
}

int main (void) {
    ios_base::sync_with_stdio(false);

    string s;
    int ans = 0;
    while(getline(cin, s)) {
        ans += solve(s);
    }

    cout << ans << endl;

    return 0;
}

