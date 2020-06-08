/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int findLca(TreeNode *cur, int u, int v, bool &hasU, bool &hasV) {
    if(cur == NULL) return -1;
    
    bool hu = (cur->val == u);
    bool hv = (cur->val == v);
     
    int l = findLca(cur->left, u, v, hu, hv);
    int r = findLca(cur->right, u, v, hu, hv);
    hasU |= hu;
    hasV |= hv;
    
    if(l != -1) return l;
    if(r != -1) return r;
    
    if(hu and hv) {
        return cur->val;
    }
    
    return -1;
}
 
int Solution::lca(TreeNode* tree, int u, int v) {
    bool hu = false, hv = false;
    return findLca(tree, u, v, hu, hv);
}
