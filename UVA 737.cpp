#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double E = exp(1);

class Ponto {
public:
	int x, y, z;

	Ponto() {
		x = 0;	y = 0;	z = 0;
	}

	Ponto (int a, int b, int c) {
		x = a;	y = b;	z = c;
	}
};

ostream &operator<<(ostream &os, Ponto const &p) {
	return os << p.x << " " << p.y << " " << p.z;
}

class Cubo {
public:
	Ponto p[2][2][2];

	Cubo() {
		for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		for (int k = 0; k < 2; k++)
			p[i][j][k] = Ponto();
	}

	void print() {
		for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		for (int k = 0; k < 2; k++)
			cout << i << " " << j << " " << k << ": " << p[i][j][k] << endl;;
		cout << endl;
	}
} a, b, c;

int n;

bool entra (int a, int b, int c, int d) {
	return ( (a <= c and c <= b) or (c <= a and a <= d));
}

void go () {
	c = Cubo();

	if (!entra(a.p[0][0][0].x, a.p[1][0][0].x, b.p[0][0][0].x, b.p[1][0][0].x) or
		!entra(a.p[0][0][0].y, a.p[0][1][0].y, b.p[0][0][0].y, b.p[0][1][0].y) or
		!entra(a.p[0][0][0].z, a.p[0][0][1].z, b.p[0][0][0].z, b.p[0][0][1].z) ) {
			a = Cubo();
			return;
	}

/* ____
  /|__/|
 | |_|_|
 |/__|/ 
 		*/

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				int x, y, z;
				if (!i) 
					x = max(a.p[0][0][0].x, b.p[0][0][0].x);
				else 
					x = min(a.p[1][0][0].x, b.p[1][0][0].x);

				if (!j) 
					y = max(a.p[0][0][0].y, b.p[0][0][0].y);
				else 
					y = min(a.p[0][1][0].y, b.p[0][1][0].y);

				if (!k) 
					z = max(a.p[0][0][0].z, b.p[0][0][0].z);
				else 
					z = min(a.p[0][0][1].z, b.p[0][0][1].z);

				c.p[i][j][k] = Ponto(x, y, z);
			}
		}
	}

//	c.print();

	a = c;
}

int ans () {
	ll res = 0;

//	a.print();

	res = a.p[1][0][0].x - a.p[0][0][0].x;
	res *= a.p[0][1][0].y - a.p[0][0][0].y;
	res *= a.p[0][0][1].z - a.p[0][0][0].z;

	return res;
}

int main (void) {
	ios_base::sync_with_stdio(false);

	while (cin >> n, n) {
		int x, y, z, p;
		cin >> x >> y >> z >> p;

		for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		for (int k = 0; k < 2; k++)
			a.p[i][j][k] = Ponto (x + p*i, y + p*j, z + p*k);

//		a.print();

		for (int t = 1; t < n; t++) {
			cin >> x >> y >> z >> p;
			for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				b.p[i][j][k] = Ponto (x + p*i, y + p*j, z + p*k);
//			b.print();
			go();
		}

		cout << ans() << endl;
	}

	return 0;
}
