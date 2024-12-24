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

map<string, function<bool(bool, bool)>> opMap = {
    { "AND", [](bool a, bool b) -> bool { return a&b; } },
    { "OR", [](bool a, bool b) -> bool { return a|b; } },
    { "XOR", [](bool a, bool b) -> bool { return a^b; } },
};

struct Wire;

struct Oper;

struct Wire {
    variant<bool, Oper*> value;

    Wire() {}

    Wire(bool val) : value(val) {}
    Wire(Oper *o) : value(o) {}
};

struct Oper {
    string op;
    using Par = variant<string, bool>;
    pair<Par, Par> par;

    Oper() {}

    Oper(string op, string l, string r) : op(op), par(l, r) {}

    bool solve(const string& p, bool val, bool &res) {
        if (par.fi.index() == 0 && get<string>(par.fi) == p) {
            par.fi = val;
        } else if (par.se.index() == 0 && get<string>(par.se) == p) {
            par.se = val;
        }
        if (par.fi.index() == 1 && par.se.index() == 1) {
            res = opMap[op](get<bool>(par.fi), get<bool>(par.se));
            return true;
        }
        return false;
    }
};

map<string, Wire> wire;
map<string, queue<string>> ch;

void read() {
    string line;
    while(getline(cin, line) && !line.empty()) {
        string u = line.substr(0, 3);
        bool val = line.back() == '1';
        wire[u] = Wire(val);
    }

    int i = 0;
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

    auto addCh = [](const string& p, const string& c) -> void {
        if (!ch.count(p)) {
            ch[p] = {};
        }
        ch[p].push(c);
    };

    while(getline(cin, line)) {
        i = 0;
        string u = parse(line, i);
        string op = parse(line, i);
        string v = parse(line, i);
        string r = parse(line, i);

        Oper *o = new Oper(op, u, v);
        wire[r] = Wire(o);
        addCh(u, r);
        addCh(v, r);
    }
}

ll go() {
    queue<string> q;
    for (const auto &it : wire) {
        const auto &val = it.se.value;
        if (val.index() == 0) {
            q.push(it.fi);
        }
    }

    set<string> z;

    while(q.size()) {
        string u = q.front();
        bool val = get<bool>(wire[u].value);
        q.pop();
        
        cout << u << " " << val << endl;

        if (u[0] == 'z') {
            z.insert(u);
        }

        queue<string> &chs = ch[u];
        while(chs.size()) {
            string v = chs.front();
            chs.pop();

            bool res;
            if (get<Oper*>(wire[v].value)->solve(u, val, res)) {
                q.push(v);
                wire[v].value = res;
            }
        }
    }

    ll ans = 0;
    for (auto it = z.rbegin(); it != z.rend(); ++it) {
        const string &u = *it;
        ans = (ans<<1) + get<bool>(wire[u].value);
    }

    return ans;
}

int main (void) {
	ios_base::sync_with_stdio(false);

    read();
    cout << go() << endl;

	return 0;
}
