
#include<iostream>
#include"c.h"
using namespace std;
int main()
{
	vector<int> in;
	int a[]={1,12,-5,-6,50,3};
	for(int i=0;i<6;i++)
	{
		in.push_back(a[i]);
	}
	Solution s;
	auto ans=s.findMaxAverage(in,4);
	system("pause");
	return 0;
}