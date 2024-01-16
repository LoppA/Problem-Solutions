// https://leetcode.com/problems/insert-delete-getrandom-o1/
class RandomizedSet {
  vector<int> v;
  unordered_map<int, int> id;
public:
    RandomizedSet() {}

    bool insert(int val) {
      if (id.count(val)) {
        return false;
      }
      id[val] = v.size();
      v.push_back(val);
      return true;
    }

    bool remove(int val) {
      if (!id.count(val)) {
        return false;
      }

      int i = id[val];
      v[i] = v.back();
      id[v[i]] = i;

      v.pop_back();
      id.erase(val);

      return true;
    }

    int getRandom() {
      assert(!v.empty());
      int i = random()%v.size();
      return v[i];
    }
};
