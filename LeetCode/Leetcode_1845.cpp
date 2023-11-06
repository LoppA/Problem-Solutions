// https://leetcode.com/problems/seat-reservation-manager/
class SeatManager {
  int n;
  set<int> s;
public:
    SeatManager(int n) : n(n) {
      for (int i = 1; i <= n; i++) {
        s.insert(i);
      }
    }
    
    int reserve() {
      int seat = *(s.begin());
      s.erase(s.begin());
      return seat;
    }
    
    void unreserve(int seatNumber) {
      s.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
