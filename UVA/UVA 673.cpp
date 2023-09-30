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

bool abre (char c) {
	return (c == '{' or c == '[' or c == '(');
}

char inv (char c) {
	if (c == ')') return '(';
	if (c == ']') return '[';
	if (c == '}') return '{';
	return '@';
}

int main (void) {
	ios_base::sync_with_stdio(false);

	string s;
	
	int n;	cin >> n;
	getline(cin, s);
	while (n--) {
		getline(cin, s);
//		cout << s.size() << endl;
		stack <char> st;

		for (int i = 0; i < (int)s.size(); i++) {
			if (abre(s[i])) {
				st.push(s[i]);
			} else {
				if (st.size() and st.top() == inv(s[i]) ) 
					st.pop();
				else 
					st.push(s[i]);
			}
		}
		
		if (st.empty()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}
