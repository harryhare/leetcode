#include<vector>
#include<string>
#include<map>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
private:
    map<string,int> m;
	vector<TreeNode*> ans;
	string dfs(TreeNode* root)
	{
		if(root==NULL)
		{
			return "";
		}
		string str= "("+dfs(root->left)+to_string(root->val)+dfs(root->right)+")";
		m[str]++;
		if(m[str]==2)
		{
			ans.push_back(root);
		}
		return str;
	}
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		m.clear();
		ans.clear();
		dfs(root);
		return ans;
    }
};