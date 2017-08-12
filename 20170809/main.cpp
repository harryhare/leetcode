
#include<vector>
#include<string>
#include<iostream>
#include"655.h"
using namespace std;
int main()
{
	Solution s;
	TreeNode *root=new TreeNode(1);
	root->right=new TreeNode(2);
	s.printTree(root);
	system("pause");
	return 0;
}