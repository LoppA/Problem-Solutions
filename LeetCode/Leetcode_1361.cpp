// https://leetcode.com/problems/validate-binary-tree-nodes/
class Solution {
    vector<int> l, r;
    vector<bool> vis;
    
    bool go(int u) {
        if (u == -1)    return true;
        if (vis[u]) return false;
        vis[u] = true;
        
        if(!go(l[u]))   return false;
        if(!go(r[u]))   return false;
        
        return true;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        this->l = leftChild;
        this->r = rightChild;
        this->vis = vector<bool>(n, false);
        
        vector<int> par(n, 0);
        for (int u : leftChild) if(u != -1) par[u]++;
        for (int u : rightChild) if(u != -1) par[u]++;
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!par[i]) {
                if (u != -1) {
                    return false;
                }
                u = i;
            }
        }
        if (u == -1) {
            return false;
        }
        
        if (!go(u)) return false;
        
        for (bool v : vis) {
            if (!v) return false;
        }
        
        return true;
    }
};
