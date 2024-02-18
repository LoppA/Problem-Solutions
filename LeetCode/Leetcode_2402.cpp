// https://leetcode.com/problems/meeting-rooms-iii/
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
      sort(meetings.begin(), meetings.end(),
           [](const vector<int> &a, const vector<int> &b) {
             return a[0] < b[0];
           });
      
      set<int> room;
      priority_queue<tuple<long long, int, int>,
        vector<tuple<long long, int, int>>,
        greater<tuple<long long, int, int>>> ev;
      priority_queue<pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>> waiting;
      
      vector<int> freq(n, 0);
      
      for (int i = 0; i < n; i++) {
        room.insert(i);
      }
      
      for (vector<int> meet : meetings) {
        int l = meet[0], r = meet[1];
        ev.emplace(l, 1, r-l);
      }
      
      while(!ev.empty()) {
        long long t;
        int op, val;
        tie(t, op, val) = ev.top();
        ev.pop();
        
        if (op == 1) {
          // New meeting should start at t, and last d minutes
          int d = val;
          if (room.empty()) {
            waiting.emplace(t, d);
          } else {
            int r = *room.begin();
            room.erase(room.begin());
            freq[r]++;
            ev.emplace(t+d, 0, r);
          }
        } else {
          // Room r is now free
          int r = val;
          if (waiting.empty()) {
            room.insert(r);
          } else {
            int d = waiting.top().second;
            waiting.pop();
            freq[r]++;
            ev.emplace(t+d, 0, r);
          }
        }
      }
      
      assert(room.size() == n);
      
      int ans = 0;
      for (int i = 0; i < n; i++) {
        if (freq[i] > freq[ans]) {
          ans = i;
        }
      }
      return ans;
    }
};
