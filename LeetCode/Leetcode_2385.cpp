// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
class Solution {
  
  map<TreeNode*, TreeNode*> par;
  
  TreeNode* getNode(TreeNode* node, int value) {
    if (node == NULL) {
      return NULL;
    }
    if (node->val == value) {
      return node;
    }
    
    auto addParent = [this](TreeNode* node, TreeNode* parent) -> void {
      if (node == NULL) {
        return;
      }
      par[node] = parent;
    };
    
    TreeNode* left = getNode(node->left, value);
    if (left) {
      addParent(node->left, node);
      return left;
    }
  
    TreeNode* right = getNode(node->right, value);
    if (right) {
      addParent(node->right, node);
      return right;
    }
  
    return NULL;
  }

  int dfs(TreeNode* node, TreeNode* prev=NULL) {
    int len = 0;
    
    auto check = [this, &len, &prev] (TreeNode* nxt, TreeNode* curr) -> void {
      if (!nxt || nxt == prev) {
        return;
      }
      
      len = max(len, dfs(nxt, curr) + 1);
    };
    
    check(par[node], node);
    check(node->left, node);
    check(node->right, node);
    
    return len;
  }
  
public:
    int amountOfTime(TreeNode* root, int start) {
      TreeNode* node = getNode(root, start);
      
      return dfs(node);
    }
};
