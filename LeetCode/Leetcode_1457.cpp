// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
class Solution {
  int dfs(TreeNode* node, int mask) {
    int val = node->val - 1;
    assert(0 <= val && val <= 9);
    mask ^= (1<<val);
    
    if (!node->left && !node->right) {
      return __builtin_popcount(mask) <= 1;
    }
    
    auto visit = [this, &mask](TreeNode* child) -> int {
      if (!child) {
        return 0;
      }
      return dfs(child, mask);
    };
    
    return visit(node->left) + visit(node->right);
  }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
      return dfs(root, 0);
    }
};
