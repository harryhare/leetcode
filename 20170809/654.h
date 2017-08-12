#include<vector>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };



class Solution {
private:
	TreeNode* gettree(vector<int>&nums,int begin,int end)
	{
		if(end<=begin)
		{
			return NULL;
		}
		int maxi=begin;
		for(int i=begin+1;i<end;i++)
		{
			if(nums[i]>nums[maxi])
			{
				maxi=i;
			}
		}
		TreeNode*root=new TreeNode(nums[maxi]);
		root->left=gettree(nums,begin,maxi);
		root->right=gettree(nums,maxi+1,end);
		return root;
	}
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return gettree(nums,0,nums.size());      
    }
};