
#include<vector>
#include<string>
#include<iostream>
#include"c.h"
using namespace std;
int main()
{
	Solution s;
	vector<int> v;
	for(int i=1;i<=4;i++)
	{
		v.push_back(i);
	}
	for(int i=4;i<=5;i++)
	{
		v.push_back(i);
	}
	cout<<s.isPossible(v)<<endl;
	system("pause");
	return 0;
}