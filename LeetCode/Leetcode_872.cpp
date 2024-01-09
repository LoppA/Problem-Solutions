// https://leetcode.com/problems/leaf-similar-trees/
class Solution {
  vector<int> list;
  
  void dfs(TreeNode* node) {
    if (!node->left && !node->right) {
      list.push_back(node->val);
    }
    
    if (node->left) {
      dfs(node->left);
    }
    if (node->right) {
      dfs(node->right);
    }
  }
  
  vector<int> getList(TreeNode *root) {
    list = vector<int>();
    dfs(root);
    return list;
  }
  
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
      return getList(root1) == getList(root2);
    }
};
