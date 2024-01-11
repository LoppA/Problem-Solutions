// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
class Solution {
  int v = 0;
  
  pair<int, int> dfs(TreeNode* node) {
    pair<int, int> val(node->val, node->val);
    
    auto visit = [this, &val](TreeNode* child) {
      if(!child) {
        return;
      }
      pair<int, int> childVal = dfs(child);
      val.first = min(val.first, childVal.first);
      val.second = max(val.second, childVal.second);
    };
    
    visit(node->left);
    visit(node->right);
    
    int _v = max(node->val - val.first, val.second - node->val);
    v = max(v, _v);
    
    return val;
  }
public:
    int maxAncestorDiff(TreeNode* root) {
      dfs(root);
      return v;
    }
};
