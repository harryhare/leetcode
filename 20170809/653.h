#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


class Solution {
	vector<int> v;
	void fun(TreeNode*root)
	{
		if(root==NULL)
		{
			return;
		}
		fun(root->left);
		v.push_back(root->val);
		fun(root->right);
	}
public:
    bool findTarget(TreeNode* root, int k) {
		v.clear();
		fun(root);
        int i=0;
		int j=v.size()-1;
		while(i<j)
		{
			if(v[i]+v[j]==k)
			{
				return true;
			}
			if(v[i]+v[j]>k)
			{
				j--;
			}
			else
			{
				i++;
			}
		}
		return false;
    }
};