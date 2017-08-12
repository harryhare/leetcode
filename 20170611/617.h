/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include<iostream>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if(t1==NULL && t2==NULL)
		{
			return NULL;
		}
		int v=0;
		if(t1==NULL)
		{
			v=t2->val;
			TreeNode* root=new TreeNode(v);
			root->left=mergeTrees(NULL,t2->left);
			root->right=mergeTrees(NULL,t2->right);
			return root;

		}
		if(t2==NULL)
		{
			v=t1->val;
			TreeNode* root=new TreeNode(v);
			root->left=mergeTrees(NULL,t1->left);
			root->right=mergeTrees(NULL,t1->right);
			return root;
		}
		if(t1!=NULL && t2!=NULL)
		{
			TreeNode* root=new TreeNode(t1->val+t2->val);
			root->left=mergeTrees(t1->left,t2->left);
			root->right=mergeTrees(t1->right,t2->right);
			return root;
		}
		
    }
};