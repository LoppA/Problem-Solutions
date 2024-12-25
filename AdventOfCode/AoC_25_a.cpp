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

const size_t N = 7, M = 5;

enum Type {
    UNDEF,
    LOCK,
    KEY,
};

vector<vector<int>> key, lck;

bool readBlock() {
    string line;
    vector<string> v;
    while(getline(cin, line) && !line.empty()) {
        v.push_back(line);
        assert(line.size() == M);
    }
    if (!v.size()) {
        return false;
    }
    assert(v.size() == N);

    Type type = Type::UNDEF;
    for (size_t j = 0; j < M && type == Type::UNDEF; j++) {
        char top = v.front()[j];
        char bot = v.back()[j];
        if (top == '#' && bot == '.') {
            type = Type::LOCK;
        } else if (top == '.' && bot == '#') {
            type = Type::KEY;
        }
    }
    assert(type != Type::UNDEF);

    if (type == Type::KEY) {
        reverse(v.begin(), v.end());
    }
    vector<int> t;
    for (size_t j = 0; j < M; j++) {
        size_t i = 0;
        for (i = 0; i < N && v[i][j] == '#'; i++) {}
        t.push_back(i);
    }

    if (type == Type::LOCK) {
        lck.push_back(t);
    } else {
        key.push_back(t);
    }

    return true;
}

void read() {
    while(readBlock()) {}
    cout << lck.size() << " " << key.size() << endl;
}

int go() {
    auto check = [](const vector<int> &u, const vector<int> &v) -> bool {
        for (size_t i = 0; i < M; i++) {
            if (u[i] + v[i] > (int)N) {
                return false;
            }
        }
        return true;
    };

    int ans = 0;
    for (const auto &u : lck) {
        for (const auto &v : key) {
            ans += check(u, v);
        }
    }

    return ans;
}

int main (void) {
    ios_base::sync_with_stdio(false);

    read();
    cout << go() << endl;

    return 0;
}
