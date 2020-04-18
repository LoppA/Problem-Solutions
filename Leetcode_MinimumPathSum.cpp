class Solution {
  bool inside(int i, int j, vector<vector<int>>& grid) {
    return (i >= 0 and i < grid.size() and j >= 0 and j < grid[i].size());
  }
public:
    int minPathSum(vector<vector<int>>& grid) {
      typedef tuple<int, int, int> tri;   
      priority_queue<tri, vector<tri>, greater<tri>> pq;
      
      vector<vector<int>> dist(grid.size());
      for(int i = 0; i < grid.size(); i++) {
        dist[i].resize(grid[i].size(), INT_MAX);
      }
      dist[0][0] = grid[0][0];
      pq.emplace(dist[0][0], 0, 0);
      
      while(pq.size()) {
        int cost, i, j;
        tie(cost, i, j) = pq.top();
        pq.pop();
        
        if(i == (int)grid.size()-1 and j == (int)grid[i].size()-1) {
          return dist[i][j];
        }
        
        if(inside(i+1, j, grid) and dist[i+1][j] > cost + grid[i+1][j]) {
          dist[i+1][j] = cost + grid[i+1][j];
          pq.emplace(dist[i+1][j], i+1, j);
        }
  
        if(inside(i, j+1, grid) and dist[i][j+1] > cost + grid[i][j+1]) {
          dist[i][j+1] = cost + grid[i][j+1];
          pq.emplace(dist[i][j+1], i, j+1);
        }
      }
      
      return INT_MAX;
    }
};
