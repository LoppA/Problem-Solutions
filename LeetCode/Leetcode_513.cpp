// https://leetcode.com/problems/find-bottom-left-tree-value/
class Solution {
  
  int depth = -1, value;
  
  void go(TreeNode* node, int d = 0) {
    if (!node) {
      return;
    }
    
    if (d > depth) {
      value = node->val;
      depth = d;
    }
    
    go(node->left, d+1);
    go(node->right, d+1);
  }
  
public:
    int findBottomLeftValue(TreeNode* root) {
      go(root);
      return value;
    }
};
