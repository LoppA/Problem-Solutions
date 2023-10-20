// https://leetcode.com/problems/flatten-nested-list-iterator/
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
  vector<int> list;
  vector<int>::iterator it;
    
  void build(const vector<NestedInteger> &nestedList) {
    for (const NestedInteger &node : nestedList) {
      if (node.isInteger()) {
        list.push_back(node.getInteger());
      } else {
        build(node.getList());
      }
    }
  }
    
public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    list.clear();
    build(nestedList);
    it = list.begin();
  }
    
  int next() {
    if (!hasNext()) {
      return 0;
    }
    int ret = *it;
    it++;
    return ret;
  }
    
  bool hasNext() {
    return it != list.end();
  }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

