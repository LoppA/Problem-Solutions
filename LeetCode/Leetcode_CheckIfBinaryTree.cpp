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
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
      if(root == NULL) {
        return arr.size() == 0;
      }
      
      typedef pair<TreeNode*, int> state;
      queue<state> q;
      q.emplace(root, 0);
      
      while(!q.empty()) {
        state cur = q.front();
        q.pop();
        
        TreeNode* node = cur.first;
        int idx = cur.second;
        
        if(idx >= (int)arr.size() or node == NULL or node->val != arr[idx]) {
          continue;
        }
        
        if(node->left == NULL and node->right == NULL and idx == (int)arr.size()-1) {
          return true;
        }
        
        q.emplace(node->left, idx+1);
        q.emplace(node->right, idx+1);
      }
      return false;
    }
};
