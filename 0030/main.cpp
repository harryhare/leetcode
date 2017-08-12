#include"0040.h"
#include<iostream>
#include<string>

using namespace std;
int main()
{
	//vector<string > a;
	//a.push_back("..9748...");
	//a.push_back("7........");
	//a.push_back(".2.1.9...");
	//a.push_back("..7...24.");
	//a.push_back(".64.1.59.");
	//a.push_back(".98...3..");
	//a.push_back("...8.3.2.");
	//a.push_back("........6");
	//a.push_back("...2759..");
	//vector<vector<char>> b;
	//for(int i=0;i<9;i++)
	//{
	//	vector<char> t;
	//	for(int j=0;j<9;j++)
	//	{
	//		t.push_back(a[i][j]);
	//	}
	//	b.push_back(t);
	//}
	//Solution s;
	//s.solveSudoku(b);
	//for(int i=0;i<b.size();i++)
	//{
	//	for(int j=0;j<9;j++)
	//	{
	//		cout<<b[i][j];
	//	}
	//	cout<<endl;
	//}


	//Solution s;
	//cout<<s.countAndSay(4)<<endl;

	Solution s;
	vector<int> a;
	a.push_back(10);
	a.push_back(1);
	a.push_back(2);
	a.push_back(7);
	a.push_back(6);
	a.push_back(1);
	a.push_back(5);
	vector<vector<int>> ans=s.combinationSum2(a,8);
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
		{
			printf("%d ",ans[i][j]);
		}
		putchar('\n');
	}


	system("pause");
	return 0;
}

