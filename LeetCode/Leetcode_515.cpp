// https://leetcode.com/problems/find-largest-value-in-each-tree-row/
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
  typedef pair<int, TreeNode*> ii;
public:
    vector<int> largestValues(TreeNode* root) {
      if (!root) {
        return vector<int>();
      }
      vector<int> v;
      
      queue<ii> q;
      q.emplace(0, root);
      while(q.size()) {
        int lvl = q.front().first;
        TreeNode* node = q.front().second;
        q.pop();
        
        if (v.size() <= lvl) {
          v.push_back(node->val);
        } else {
          v.back() = max(v.back(), node->val);
        }
        
        auto add = [&lvl, &q](TreeNode *node) -> void {
          if (node) {
            q.emplace(lvl+1, node);
          }
        };
        
        add(node->left);
        add(node->right);
      }
      
      return v;
    }
};
