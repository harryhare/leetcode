
#include<iostream>
#include"0074.h"
int main()
{
	Solution s;
	vector<vector<int>> v;
	vector<int> v1;
	v1.push_back(1);
	v.push_back(v1);
	v1[0]=3;
	v.push_back(v1);
	v1[0]=5;
	v.push_back(v1);
	cout<<s.searchMatrix(v,3)<<endl;
	system("pause");
	return 0;
}