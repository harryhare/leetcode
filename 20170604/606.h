/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<string>
#include<sstream>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    string tree2str(TreeNode* t) {
        if(t==NULL)
		{
			return "";
		}
		stringstream ans;
		ans<<(t->val);
		if(t->left==NULL && t->right==NULL)
		{
			return ans.str();
		}
		ans<<'('<<(tree2str(t->left))<<')';
		if(t->right)
		{
			ans<<'('<<tree2str(t->right)<<')';
		}
		return ans.str();
    }
};