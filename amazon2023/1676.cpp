#include <vector>
#include <set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode*dfs(TreeNode *root, set<TreeNode *> &nodes){
        if(root==NULL){
            return NULL;
        }
        if(nodes.find(root)!=nodes.end()){
            return root;
        }
        TreeNode* left=dfs(root->left,nodes);
        TreeNode* right=dfs(root->right,nodes);
        if(left!=NULL && right!=NULL){
            return root;
        }
        if(left!=NULL){
            return left;
        }
        return right;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, vector<TreeNode *> &nodes) {
        set<TreeNode*> s;
        for(auto & node : nodes){
            s.insert(node);
        }
        return dfs(root,s);
    }
};