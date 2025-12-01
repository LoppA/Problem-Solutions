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

map<string, tuple<string, string, string>> m;
map<tuple<string, string, string>, string> rm;

void read() {
    string line;
    while(getline(cin, line) && !line.empty()) {}

    auto parse = [](string s, int &i) -> string {
        int n = s.size();
        string ret;
        while(i < n) {
            char c = s[i++];
            if (isalnum(c)) {
                ret += c;
            } else {
                if (!ret.empty()) {
                    return ret;
                }
            }
        }
        return ret;
    };

    while(getline(cin, line)) {
        int i = 0;
        string u = parse(line, i);
        string op = parse(line, i);
        string v = parse(line, i);
        string r = parse(line, i);

        auto tp = make_tuple(op, u, v);
        m[r] = tp;
        rm[tp] = r;
    }
}

string build(char c, int i) {
    return {c, '0'+(i/10), '0'+(i%10)};
}

string find(string op, string u, string v) {
    if (rm.count(make_tuple(op, u, v))) {
        return rm[make_tuple(op, u, v)];
    } else if (rm.count(make_tuple(op, v, u))) {
        return rm[make_tuple(op, v, u)];
    }
    return "";
}

int go() {
    int i = 0;
    string cN;
    while(m.count(build('z', i))) {
        string zN = build('z', i);
        string xN = build('x', i);
        string yN = build('y', i);

        string rzN = find("XOR", xN, yN);

        // cout << zN << " = " << cN << " ^ " << rzN << endl;

        string lcN = find("AND", rzN, cN);
        string rcN = find("AND", xN, yN);
        if (lcN.empty()) {
            if (i) {
                return i;
            }
            cN = rcN;
        } else {
            cN = find("OR", lcN, rcN);
        }
        cN = lcN.empty() ? rcN : find("OR", lcN, rcN);

        // cout << cN << " = " << lcN << " | " << rcN << endl;

        i++;
    }

    return i;
}

int main (void) {
	ios_base::sync_with_stdio(false);

    read();

    int curr = go();

    set<string> ans;
    while(m.count(build('z', curr+1))) {
        cout << curr << endl;
        int tmp = curr;
        pair<string, string> swp;
        for (auto &i : rm) {
            for (auto &j : rm) {
                swap(i.se, j.se);
                int r = go();
                if (r > tmp) {
                    tmp = r;
                    swp = make_pair(i.se, j.se);
                    cout << i.se << " " << j.se << " " << r << endl;
                }
                swap(i.se, j.se);
            }
        }
        auto a = m[swp.fi];
        auto b = m[swp.se];
        swap(m[swp.fi], m[swp.se]);
        swap(rm[a], rm[b]);
        curr = tmp;
        ans.insert(swp.fi);
        ans.insert(swp.se);
    }

    for (const string &s : ans) {
        cout << s << ',';
    }

	return 0;
}
