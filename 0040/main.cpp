#include"0047.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class A
{
	A(){}
	~A(){}
	static int i;
};


int main()
{
	cout<<sizeof(A)<<endl;
	Solution s;

	//vector<int> nums;
	//nums.push_back(3);
	//nums.push_back(4);
	//nums.push_back(3);
	//nums.push_back(2);
	//nums.push_back(5);
	//nums.push_back(4);
	//nums.push_back(3);
	//cout<<s.jump(nums)<<endl;
	
	//string x="";
	//
	//string a="111";
	//string b="11";
	//cout<<s.multiply(a,b).c_str()<<endl;

	//string ss="aa";
	//string p="aa";
	//cout<<s.isMatch(ss,p)<<endl;

	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(-1);
	nums.push_back(-1);
	nums.push_back(-1);
	vector<vector<int>> ans=s.permuteUnique(nums);
	for(int i=0;i<ans.size();i++)
	{
		cout<<"[";
		for(int j=0;j<nums.size();j++)
		{
			cout<<ans[i][j]<<",";
		}
		cout<<"]";
		cout<<endl;
	}


	system("pause");
	return 0;
}