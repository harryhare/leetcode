#include<cstdio>
#include<iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
		long long y=0;
		while(x!=0)
		{
			y=y*10+x%10;
			x=x/10;
		}
		if(y>(long long)INT_MAX || y<(long long)INT_MIN)
		{
			return 0;
		}
		else
		{
			return (int)y;
		}
    }
};