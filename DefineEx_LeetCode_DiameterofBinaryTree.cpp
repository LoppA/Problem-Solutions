/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define CHILD(x); if(x) { \
  currNode->addNode(buildGraph(x)); \
}

class Solution {
  struct Node {
    vector<Node*>adj;
    Node(){}
    void addNode(Node *neig) {
      adj.push_back(neig);
      neig->adj.push_back(this);
    }
  };
  
  Node* buildGraph(TreeNode* curr) {
    Node* currNode = new Node();
    
    CHILD(curr->left);
    CHILD(curr->right);
    
    return currNode;
  }
  
  Node *bfs(Node* beg, int &dist) {
    set<Node*> vis;
    queue<pair<Node*, int> > q;
    q.emplace(beg, 0);
    vis.insert(beg);
    dist = 0;
  
    Node *curr = beg;
    
    while(q.size()) {
      curr = q.front().first;
      int d = q.front().second;
      dist = max(dist, d);
      q.pop();
      
      for(auto nxt : curr->adj) {
        if(vis.count(nxt))  continue;
        q.emplace(nxt, d+1);
        vis.insert(nxt);
      }
    }
    
    return curr;
  }
public:
    int diameterOfBinaryTree(TreeNode* root) {
      if(!root) return 0;
      Node* rootNode = buildGraph(root);
      
      int dist = 0;
      Node* a = bfs(rootNode, dist);
      bfs(a, dist);
      
      return dist;
    }
};
