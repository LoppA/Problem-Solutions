class FirstUnique {
  vector<int> queue;
  unordered_set<int> cnt, rep;
  int firstUnique;
public:
    FirstUnique(vector<int>& nums) {
      firstUnique = 0;
      for(int value : nums)
        add(value);
    }
    
    int showFirstUnique() {
      return (firstUnique >= (int)queue.size() ? -1 : queue[firstUnique]);
    }
    
    void add(int value) {
      queue.push_back(value);
      if(cnt.insert(value).second == false) {
        rep.insert(value);
      }
      while(firstUnique < (int)queue.size() and rep.count(queue[firstUnique])) {
        firstUnique++;
      }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
