// https://leetcode.com/problems/range-sum-of-bst/
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
      int total =
          (root->val >= low && root->val <= high) ?
          root->val : 0;
      
      auto check = [this, low, high](TreeNode* node) -> int {
        return node == nullptr ? 0 : rangeSumBST(node, low, high);
      };
      
      return total + check(root->left) + check(root->right);
    }
};
