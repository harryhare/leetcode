#include "0054.h"
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cassert>
#include <algorithm>
int main()
{
	//int a[][3]={{1,2,3},{4,5,6},{7,8,9}};
	int a[][2]={{2,3}};
	vector<vector<int>> v;
	for(int i=0;i<1;i++)
	{
		v.push_back(vector<int>());
		for(int j=0;j<2;j++)
		{
			v[i].push_back(a[i][j]);
		}
	}
	Solution s;
	vector<int> ans=s.spiralOrder(v);
	for(int x:ans)
	{
		cout<<x<<endl;
	}
	system("pause");
	return 0;
}