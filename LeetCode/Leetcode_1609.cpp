// https://leetcode.com/problems/even-odd-tree/
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
      
      vector<TreeNode*> v;
      bool lvl = 0;
      v.push_back(root);
      
      auto checkCond = [](int a, int b, function<bool(int,int)> cmp) -> bool {
        return cmp(a, b);
      };
      
      auto check = [&checkCond](bool lvl, TreeNode* prev, TreeNode* node) -> bool {
        return checkCond(
          prev->val,
          node->val,
          lvl ? ([](int a, int b) {return a > b;} ): ([](int a, int b) {return a < b;}));
      };
      
      while(v.size()) {
        vector<TreeNode*> tmp;
        
        if (v[0]->val%2 == lvl) {
          return false;
        }
        
        for (int i = 1; i < (int)v.size(); i++) {
          auto node = v[i];
          auto prev = v[i-1];
          
          if (node->val%2 == lvl) {
            return false;
          }
          
          if (!check(lvl, prev, node)) {
            return false;
          }
        }
        
        for (auto node : v) {
          if (node->left) tmp.push_back(node->left);
          if (node->right) tmp.push_back(node->right);
        }
        
        v = move(tmp);
        lvl = !lvl;
      }
          
      return true;
    }
};
