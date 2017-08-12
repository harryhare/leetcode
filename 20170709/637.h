#include<vector>
#include<map>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
	vector<double> count;
	vector<double> sum;
	void dfs(TreeNode * root,int level)
	{
		if(root==NULL)
		{
			return;
		}
		if(count.size()<level)
		{
			count.push_back(1);
			sum.push_back(root->val);
		}
		else
		{
			count[level-1]+=1;
			sum[level-1]+=root->val;
		}
		dfs(root->left,level+1);
		dfs(root->right,level+1);
	}
public:
    vector<double> averageOfLevels(TreeNode* root) {
		count.clear();
		sum.clear();
		dfs(root,1);
		vector<double> ans;
		for(int i=0;i<count.size();i++)
		{
			ans.push_back((double)sum[i]/count[i]);
		}
		return ans;
    }
};