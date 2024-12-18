#include <bits/stdc++.h>

/*
...........................................*...........................................................
..*....................................................................................................
.......................*.............................*.................................................
............................................................*..........................................
.........................*............................*................*...............................
..............................................................*........................................
.........*..........................................................................*..................
.............................*............*..*.....*...................................................
.......................................................................................................
...................................................................................*...................
.......................................................................................................
.......................................................................................................
..........................................*............................................................
.......................................................................................................
.................................................................................................*.....
.............*.................*..................*........................*...........................
........*.....................................*........................................................
......*..................................................................................*.............
............*..........................................................................................
..........................................................*..........*.................................
...............*..........................*........................**..................................
............................................*..........................................................
.....................................................*.................................................
.......*...............................................................................................
.........................................**............................................................
....................................................................*..............................*...
.......................................................................................................
.......................................................................................................
.......................................................................................................
............................................*..........................................................
..................................................................................................*....
.....*.................................................................................................
*......................................................................................*.*.............
.......................................................................................................
................................*......................................................................
........*................*.............................................................................
..............................................*......*....*.........*..................................
.......................................................................................................
.....**...........*......................................................*.............................
............*...........................................................*..............................
............*.......................................................................*..................
.......................*...............................................................................
.......................................................................*...............................
.......................................................................................................
...................................................................................*...................
..........................*.....*....*********************************...........*.............*.......
.....................*...............*...............................*.................................
.....................................*...............................*.............*...................
...................*.................*...............................*.................................
.....................................*...............................*.................................
.....................................*.......................*.......*.................................
.........................*...........*......................**.......*...........*.....................
.....................................*..................*..***.......*...................*.............
.....................................*.................**.****.......*..........................*......
.....................................*.............*..********.......*.................................
.*...................................*............**.*********.......*............................*....
.........................*...........*........*..*************.......*.................................
..........................*..........*.......**.**************.......*.................*...............
.....................................*......******************.......*.................................
.............*...................*...*.....**********************....*.................................
........*............................*....***********************....*.................................
................*....................*.....**********************....*.................................
....*.......................*........*......******************.......*...*.............................
.....*.................*.............*.......**.**************.......*.................................
.....................................*........*..*************.......*.................................
....................*................*............**.*********.......*.............*....*..............
.....................................*.............*..********.......*.......................*.........
..................*...............*..*.................**.****.......*............*...................*
............................*........*..................*..***.......*..............*..................
.....................................*......................**.......*.................................
.....................................*.......................*.......*.................................
.*...................................*...............................*................................*
.....................................*...............................*.*.............*................*
............*........................*...............................*.................................
...*.................................*...............................*.................................
.....................................*********************************.................................
..........*.........*.............................................................*.....*..............
.......................*............................................*..................................
.......................................*........................................................*......
.............*.........................................................................................
......*............................*......*.........*.....*..*.........................................
.......................................................................................................
.............................................................................*....*....................
..................................................................................................*....
..........................................................................*..................*.........
.........*..........*................................................*.................................
.......................................................................................................
.......................................................................................................
.......................................................................................................
.*...................................................................................................*.
...................................................*...................................................
..*....................................................................................................
.......................................................................................................
.......................................................................................................
...........................*...........................................................................
.*...............................................*.....................................................
*..........................................*...............*...........................................
...........*........*.......................................................*..........................
.....................................................................................*.................
....................................*..........*.......................................................
..............*.........................*..............................................................
*/

using namespace std;

#define x first
#define y second

typedef long long ll;
typedef __int128 LL;
typedef pair<ll, ll> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const ll N = 101, M = 103;
vector<ii> p, v;
int cnt[N][M];
int t;

void read() {
	string line;
	int i;

	auto parse = [&line, &i] () -> ll {
		ll val = 0;
		int sig = 1;
		bool f = false;
		while(i < (int)line.size()) {
			char c = line[i++];
			if (c == '-') {
				sig = -1;
			} else if (c >= '0' && c <= '9') {
				f = true;
				val = val*10 + c-'0';
			} else if (f) {
				return val*sig;
			}
		}
		return val*sig;
	};

	auto parse_pair = [&] () -> ii {
		ll x = parse();
		ll y = parse();
		return {x, y};
	};

	while(getline(cin, line)) {
		if (line.empty()) {
			return;
		}
		i = 0;
		ii pos = parse_pair();

		cnt[pos.x][pos.y]++;

		p.emplace_back(pos);
		v.emplace_back(parse_pair());
	}
}

void print() {
	t++;

	cout << endl << endl;
	cout << t << " seconds" << endl;

	int cur = 0, mx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cur = cnt[i][j] ? cur+1 : 0;
			mx = max(mx, cur);
		}
	}

	if (mx < 10) {
		return;
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << (cnt[i][j] ? '*' : '.');
		}
		cout << endl;
	}

	string bla;
	getline(cin, bla);

}
ii go(ii p, ii v) {
	cnt[p.x][p.y]--;

	ll x = (p.x + v.x)%N;
	ll y = (p.y + v.y)%M;

	if (x < 0) {
		x += N;
	}
	if (y < 0) {
		y += M;
	}

	cnt[x][y]++;

	return {x, y};
}

void go() {
	assert(v.size() == p.size());
	int n = v.size();

	for (int i = 0; i < n; i++) {
		p[i] = go(p[i], v[i]);
	}
}

int main (void) {
	ios_base::sync_with_stdio(false);

	read();
	while(1) {
		go();
		print();
	}

	return 0;
}
