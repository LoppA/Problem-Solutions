#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 LL;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

struct Node {
	int i;
	int n;
	Node *L;
	Node *R;

	void prop() {
		this->i = L->i;
		this->n = max(L->n, R->n);
	}

	Node(int i, int n) : i(i), n(n), L(NULL), R(NULL) {}

	Node(Node *L, Node *R) : L(L), R(R) {
		this->prop();
	}
};

vector<pair<int, int>> gap;

Node* build(int i, int j) {
	if (i == j) {
		return new Node(gap[i].first, gap[i].second);
	}
	int mid = (i+j)>>1;
	Node *L = build(i, mid);
	Node *R = build(mid+1, j);

	return new Node(L, R);
}

int update(Node *node, int i, int n) {
	if (node->n < n || node->i > i) {
		return -1;
	}
	if (node->L == NULL) {
		assert(node->R == NULL);
		int j = node->i;
		node->i += n;
		node->n -= n;
		return j;
	}

	auto search = [&i, &n](Node *child, Node *par) -> int {
		int j = update(child, i, n);
		par->prop();
		return j;
	};

	int L = search(node->L, node);
	if (L != -1) {
		return L;
	}

	return search(node->R, node);
}

ll process(const string &S) {
	set<tuple<int, int, int>> res;
	stack<tuple<int, int, int>> st;

	int id = 0;
	int i = 0, j = 0;
	while(i < (int)S.size()) {
		auto parse = [](char c) -> int {
			return c-'0';
		};

		int n = parse(S[i++]);
		res.emplace(j, n, id);
		st.emplace(j, n, id);
		id++;
		j += n;
		if (i == (int)S.size()) { break; }
		n = parse(S[i++]);
		gap.emplace_back(j, n);
		j += n;
	}

	Node* root = build(0, (int)gap.size()-1);

	while(st.size()) {
		auto tp = st.top();
		st.pop();

		int i, n, id;
		tie(i, n, id) = tp;

		int j = update(root, i, n);

		if (j == -1) {
			continue;
		}

		assert(j < i);

		assert(res.erase(tp) == 1);

		res.emplace(j, n, id);
	}

	assert(res.size() == (1+S.size())/2);

	ll ans = 0;
	for (auto it : res) {
		int i, n, id;
		tie(i, n, id) = it;

		ll j = i;
		while(n--) {
			ans += j*id;
			assert(ans >= 0);
			j++;
		}
	}

	return ans;
}

int main (void) {
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	cout << process(s) << endl;

	return 0;
}
