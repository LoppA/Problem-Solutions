// https://leetcode.com/problems/insert-interval/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      auto l = lower_bound(intervals.begin(), intervals.end(), newInterval,
                           [](const vector<int> &it, const vector<int> &newIt) {
                             return it[1] < newIt[0];
                           });
      auto r = upper_bound(intervals.begin(), intervals.end(), newInterval,
                           [](const vector<int> &newIt, const vector<int> &it) {
                             return newIt[1] < it[0];
                           });
      
      if (l != intervals.end()) {
        newInterval[0] = min(newInterval[0], l->at(0));
      }
      if (r != intervals.begin()) {
        newInterval[1] = max(newInterval[1], prev(r)->at(1));
      }
      
      auto pos = intervals.erase(l, r);
      
      intervals.insert(pos, newInterval);
      
      return intervals;
    }
};
