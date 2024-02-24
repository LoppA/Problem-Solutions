// https://leetcode.com/problems/find-all-people-with-secret/
class Solution {
  static const int N = 1e5 + 5;
  
  typedef pair<int, int> ii;
  
  int pai[N], size[N];
  vector<ii> ev[N];
  
  int find(int u) {
    if (pai[u] == -1) {
      return u;
    }
    return pai[u] = find(pai[u]);
  }
  
  void une(int u, int v) {
    u = find(u);	v = find(v);
		if (u == v) return;

		if (size[u] < size[v])
			swap(u, v);

		pai[v] = u;
		size[u] += size[v];
  }
  
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
      memset(pai, -1, sizeof pai);
      for (int i = 0; i < n; i++) size[i] = 1;
      
      for (auto meet : meetings) {
        int x = meet[0], y = meet[1], t = meet[2];
        ev[t].emplace_back(x, y);
      }
      
      une(0, firstPerson);
      
      for (const vector<ii> &v : ev) {
        for (auto edg : v) {
          int x = edg.first, y = edg.second;
          
          une(x, y);
        }
        
        for (auto edg : v) {
          int x = edg.first, y = edg.second;
          
          if (find(x) != find(0)) {
            pai[x] = pai[y] = -1;
            size[x] = size[y] = 0;
          }
        }
        
      }
      
      vector<int> ans;
      for (int i = 0; i < n; i++)
        if (find(i) == find(0))
          ans.push_back(i);
      
      return ans;
    }

};
