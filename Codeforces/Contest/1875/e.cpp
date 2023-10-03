// g++ <fileName>.cpp -Wall -Wno-unused-value -DDEBUG
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

template <typename T>
std::ostream& operator<< (std::ostream& out, const vector<T>& v) {
    out << '[';
    bool f = false;
    for(auto& x:v){
      if (f)  out<<", ";
      f = true;
      out<<x;
    }
    out << "]";
    return out;
}
vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
  vector<string> __attribute__ ((unused)) args,
  __attribute__ ((unused)) int idx,
  __attribute__ ((unused)) int LINE_NUM) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}

#ifdef DEBUG 
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#define debug_endl() cout << endl;
#else
#define debug(...) 42
#define debug_endl(...) 42
#endif

const int N = 412345, X = 6, Y = 10;
int e[X][Y];
int dist[N];

int op(int u, function<int (bool, bool, bool)> op) {
  int v = 0;

  for(int i = 0; i < 8; i++) {
    int val = u%5;
    u /= 5;

    if (val == 4) {
      v += val*e[5][i];
      continue;
    } 

    bool x = val>>1;
    bool y = val&1;
    bool m = i&1;

    v += op(x, y, m)*e[5][i];
  }

  return v;
}


void build() {
  memset(dist, -1, sizeof dist);

  for (int x = 0; x < X; x++) {
    e[x][0] = 1;
    for (int y = 1; y < Y; y++) {
      e[x][y] = e[x][y-1] * x;
    }
  }

  queue<int> q;
  int m = 1<<8;
  for (int i = 0; i < m; i++) {
    int u = 0;
    for (int j = 0; j < 8; j++) {
      if ((i>>j)&1) {
        int val = j>>1;
        assert(val < 4);
        u += val*e[5][j];
      } else {
        u += 4*e[5][j];
      }
    }
    assert(u <= (e[5][8]-1));
    q.push(u);
    dist[u] = 0;
  }

  while(q.size()) {
    int u = q.front();
    q.pop();

    auto merge = [](bool x, bool y) -> int {
      return (x<<1) | y;
    };

    auto check = [&q, &u](int v) -> void {
      if (dist[v] == -1) {
        dist[v] = dist[u]+1;
        q.push(v);
      }
    };

    check(
      op(u, [&merge](bool x, bool y, bool m) -> int {
        return merge(x&y, y);
      })
    );

    check(
      op(u, [&merge](bool x, bool y, bool m) -> int {
        return merge(x|y, y);
      })
    );

    check(
      op(u, [&merge](bool x, bool y, bool m) -> int {
        return merge(x, x^y);
      })
    );

    check(
      op(u, [&merge](bool x, bool y, bool m) -> int {
        return merge(x, y^m);
      })
    );
  }

}

const int L = 30;
int a, b, c, d, m;

int go() {
  cin >> a >> b >> c >> d >> m;

  int u = e[5][8] - 1; // Todos setados como nao existe.
  for (int i = 0; i < L; i++) {
    bool x = (a>>i)&1;
    bool y = (b>>i)&1;
    bool z = (m>>i)&1;

    int j = (x<<2) | (y<<1) | z;

    bool _x = (c>>i)&1;
    bool _y = (d>>i)&1;
    int v = (_x<<1) | _y;

    int at = u;
    for (int k = 0; k < j; k++) {
      at /= 5;
    }
    at %= 5;


    if (at == 4) {
      u -= 4*e[5][j];
      u += v*e[5][j];
    } else if (at != v) {
      return -1;
    }
  }

  return dist[u];
}

int main (void) {
	ios_base::sync_with_stdio(false);

  build();

  int T;  cin >> T;
  while(T--) {
    cout << go() << endl;
  }

	return 0;
}

