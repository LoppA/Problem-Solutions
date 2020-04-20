/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* build(vector<int>& preorder, int &i, int upVal = INT_MAX) {
      if(i >= (int)preorder.size()) return NULL;
      if(preorder[i] > upVal) return NULL;
      TreeNode *curr = new TreeNode(preorder[i++]);
      
      curr->left = build(preorder, i, curr->val);
      curr->right = build(preorder, i, upVal);
      return curr;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
      int i = 0;
      return build(preorder, i);
    }
};
