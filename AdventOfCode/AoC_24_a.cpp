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

struct Wire {
    using Formula = tuple<string, Wire*, Wire*>;

    string label;
    variant<bool, Formula> value;
    queue<Wire*> ch;

    Wire() {}

    Wire(string label) : label(label) {}
    Wire(string label, bool val) : label(label), value(val) {}
    Wire(string label, Formula f) : label(label), value(f) {}

    bool solve() {
        if (value.index() == 0) {
            return get<bool>(value);
        }

        Formula f = get<Formula>(value);
        string op;
        Wire *L, *R;
        tie(op, L, R) = f;

        if (L->value.index() == 0 && R->value.index() == 0) {
            this->value = opMap[op](get<bool>(L->value), get<bool>(R->value));
            return true;
        }
        return false;
    }
};

map<string, Wire*> wire;

void read() {
    string line;
    while(getline(cin, line) && !line.empty()) {
        string u = line.substr(0, 3);
        bool val = line.back() == '1';
        wire[u] = new Wire(u, val);
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

    auto addWire = [](const string &s) -> void {
        if (wire.count(s)) {
            return;
        }
        wire[s] = new Wire(s);
    };

    while(getline(cin, line)) {
        i = 0;
        string u = parse(line, i);
        string op = parse(line, i);
        string v = parse(line, i);
        string r = parse(line, i);

        addWire(u);
        addWire(v);
        addWire(r);

        wire[r]->value = Wire::Formula(op, wire[u], wire[v]);
        wire[u]->ch.push(wire[r]);
        wire[v]->ch.push(wire[r]);
    }
}

ll go() {
    queue<Wire*> q;
    for (const auto &it : wire) {
        const auto &val = it.se->value;
        if (val.index() == 0) {
            q.push(it.se);
        }
    }

    set<string> z;

    while(q.size()) {
        Wire *u = q.front();
        q.pop();
        
        // cout << u->label << " " << get<bool>(u->value) << endl;

        if (u->label[0] == 'z') {
            z.insert(u->label);
        }

        queue<Wire*> &ch = u->ch;
        while(ch.size()) {
            Wire *v = ch.front();
            ch.pop();

            if (v->solve()) {
                q.push(v);
            }
        }
    }

    ll ans = 0;
    for (auto it = z.rbegin(); it != z.rend(); ++it) {
        const string &u = *it;
        ans = (ans<<1) + get<bool>(wire[u]->value);
    }

    return ans;
}

int main (void) {
    ios_base::sync_with_stdio(false);

    read();
    cout << go() << endl;

    return 0;
}
