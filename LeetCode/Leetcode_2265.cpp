// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
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
  typedef pair<int,int> ii;
  int ans;
  
  static void sum(ii &a, const ii &b) {
    a.first += b.first;
    a.second += b.second;
  }
  
  pair<int, int> go(TreeNode* node) {
    pair<int, int> curr(1, node->val);
    
    auto visit = [this, &curr](TreeNode *nxt) -> void {
      if (!nxt)  return;
      this->sum(curr, go(nxt));
    };
    
    visit(node->left);
    visit(node->right);
    
    ans += curr.second/curr.first == node->val;
    
    return curr;
  }
public:
    int averageOfSubtree(TreeNode* root) {
      go(root);
      return ans;
    }
};
