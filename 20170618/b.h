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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1)
		{
			TreeNode * newroot=new TreeNode(v);
			newroot->left=root;
			return newroot;
		}
		if(root==NULL)
		{
			return NULL;
		}
		if(root->left!=NULL)
		{
			root->left=addOneRow(root->left,v,d-1);
		}
		if(root->right!=NULL)
		{
			root->right=addOneRow(root->right,v,d-1);
		}
    }
};