
#include<iostream>
#include"638.h"
using namespace std;
int main()
{
	Solution s;
/*
	vector<int> v1;
	v1.push_back(2);
	v1.push_back(5);
	vector<vector<int>> v2;
	v2.push_back(vector<int>());
	v2.back().push_back(3);
	v2.back().push_back(0);
	v2.back().push_back(5);
	v2.push_back(vector<int>());
	v2.back().push_back(1);
	v2.back().push_back(2);
	v2.back().push_back(10);
	vector<int> v3;
	v3.push_back(3);
	v3.push_back(2);
	*/
	vector<int> v1;
	v1.push_back(4);
	v1.push_back(10);
	v1.push_back(1);
	v1.push_back(5);
	v1.push_back(5);
	v1.push_back(3);
	vector<vector<int>> v2;
	v2.push_back(vector<int>());
	v2.back().push_back(1);
	v2.back().push_back(2);
	v2.back().push_back(3);
	v2.back().push_back(3);
	v2.back().push_back(4);
	v2.back().push_back(1);
	v2.back().push_back(8);
	v2.push_back(vector<int>());
	v2.back().push_back(3);
	v2.back().push_back(4);
	v2.back().push_back(5);
	v2.back().push_back(5);
	v2.back().push_back(5);
	v2.back().push_back(2);
	v2.back().push_back(14);
	v2.push_back(vector<int>());
	v2.back().push_back(2);
	v2.back().push_back(4);
	v2.back().push_back(5);
	v2.back().push_back(1);
	v2.back().push_back(1);
	v2.back().push_back(3);
	v2.back().push_back(22);
	vector<int> v3;
	v3.push_back(1);
	v3.push_back(6);
	v3.push_back(5);
	v3.push_back(1);
	v3.push_back(1);
	v3.push_back(4);
	cout<<s.shoppingOffers(v1,v2,v3)<<endl;
	system("pause");
	return 0;
}