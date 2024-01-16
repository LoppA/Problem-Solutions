// https://leetcode.com/problems/insert-delete-getrandom-o1/
class RandomizedSet {
  static const int N = 2e5 + 5;
  int v[N];
  int n;
  unordered_map<int, int> id;
public:
    RandomizedSet() {
      n = 0;
    }
    
    bool insert(int val) {
      if (id.count(val)) {
        return false;
      }
      int i = n++;
      id[val] = i;
      v[i] = val;
      return true;
    }
    
    bool remove(int val) {
      if (!id.count(val)) {
        return false;
      }
      
      int i = id[val];
      id.erase(val);
      n--;
      
      if (i == n) {
        return true;
      }
      v[i] = v[n];
      id[v[i]] = i;
      
      return true;
    }
    
    int getRandom() {
      assert(n);
      int i = random()%n;
      return v[i];
    }
};
