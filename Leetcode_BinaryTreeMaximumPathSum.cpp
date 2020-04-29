/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  pair<int,int> pathSum(TreeNode* root) {
    if(root == NULL) {
      const int INF = 0x3f3f3f3f;
      return {-INF, -INF};
    }
    pair<int,int> L = pathSum(root->left);
    pair<int,int> R = pathSum(root->right);
    
    int line = max(0, max(L.second, R.second)) + root->val;
    int path = max(L.first, R.first);
    path = max({path, line, root->val + L.second + R.second});
    
    
    return {path, line};
  }
public:
    int maxPathSum(TreeNode* root) {
      return pathSum(root).first;
    }
};
