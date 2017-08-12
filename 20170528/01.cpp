#include<vector>
using namespace std;
class Solution {
public:
	
    int maxCount(int m, int n, vector<vector<int>>& ops) {
		//static short a[40000][40000];
		//memset(a,0,sizeof(a));
		//      int max=0;
		//for(auto x:ops)
		//{
		//	x[0]
		//	
		//}
		int minx=40000;
		int miny=40000;
		for(auto x:ops)
		{
			if(x[0]<minx)
			{
				minx=x[0];
			}
			if(x[1]<miny)
			{
				miny=x[1];
			}
		}
		return minx*miny;
    }
};