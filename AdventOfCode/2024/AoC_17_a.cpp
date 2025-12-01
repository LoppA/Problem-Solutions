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

const int LOG = 30;
ll A, B, C;
vector<int> v;

int parse(const string &s, int& i) {
    bool f = false;
    int val = 0;
    while(i < (int)s.size()) {
        int c = s[i++];
        if (c >= '0' && c <= '9') {
            f = true;
            val = val*10 + c-'0';
        } else if (f) {
            return val;
        }
    }
    return val;
}

int read_line() {
    string line;
    getline(cin, line);
    int i = 0;
    return parse(line, i);
}

void read() {
    A = read_line();
    B = read_line();
    C = read_line();

    string line;
    getline(cin, line); // consume blank line

    getline(cin, line);
    int i = 0;
    while(i < (int)line.size()) {
        v.push_back(parse(line, i));
    }
}

int combo(int y) {
    if (0 <= y && y <= 3) {
        return y;
    }
    if (y == 4) {
        return A;
    }
    if (y == 5) {
        return B;
    }
    if (y == 6) {
        return C;
    }
    assert(0);
    return -1;
}

string go() {
    stringstream s;
    int i = 0;
    int n = v.size();

    auto adv = [&](int y) -> int {
        int pw = combo(y);
        int res = 0;
        if (pw < 30) {
            res = A / (1<<pw);
        }
        return res;
    };

    bool f = false;
    while(i+1 < n) {
        int x = v[i], y = v[i+1];
        i+=2;
        switch (x) {
            case 0:
                A = adv(y);
                break;
            case 1:
                B ^= y;
                break;
            case 2:
                B = combo(y)%8;
                break;
            case 3:
                if (!A) {
                    break;
                }
                i = y;
                break;
            case 4:
                B ^= C;
                break;
            case 5:
                if (f) {
                    s << ',';
                }
                s << (combo(y)%8);
                f = true;
                break;
            case 6:
                B = adv(y);
                break;
            case 7:
                C = adv(y);
                break;
            default:
                assert(0);
        }
    }

    return s.str();
}

int main (void) {
	ios_base::sync_with_stdio(false);

    read();
    cout << go() << endl;

	return 0;
}
