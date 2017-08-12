#include<vector>
#include<string>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

int findheight(TreeNode* root)
{
	if(root==NULL)
	{
		return 0;
	}
	return 1+max(findheight(root->left),findheight(root->right));
}

class Solution {
	void dfs(vector<vector<string>> & ans,int layer,int pos,int offset,TreeNode*root)
	{
		if(root==NULL)
		{
			return;
		}
		ans[layer][offset+pos]=to_string(root->val);
		dfs(ans,layer+1,pos/2,offset,root->left);
		dfs(ans,layer+1,pos/2,offset+pos+1,root->right);
	}
public:
    vector<vector<string>> printTree(TreeNode* root) {
		int n=findheight(root);
		int l=(1<<n)-1;
		vector<string> x(l,"");
		vector<vector<string>> ans(n,x);
		dfs(ans,0,l/2,0,root);
		return ans;
    }
};