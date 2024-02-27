// https://leetcode.com/problems/diameter-of-binary-tree/
class Solution {
  int d = 0;
  
  int go(TreeNode* node) {
    if (node == NULL) {
      return 0;
    }
    
    int l = go(node->left);
    int r = go(node->right);
    
    d = max(d, l+r);
    
    return max(l, r) + 1;
  }
  
public:
  int diameterOfBinaryTree(TreeNode* root) {
    go(root);
    return d;
  }
};
