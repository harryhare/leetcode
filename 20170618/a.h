#include<vector>
using namespace std;
class Solution {


public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini=0;
		int minx=arrays[0][0];
		int n=arrays.size();

		for(int i=0;i<arrays.size();i++)
		{
			if(arrays[i][0]<minx)
			{
				mini=i;
				minx=arrays[i][0];
			}
		}
		int maxi=-1;
		int maxx=0;
		for(int i=0;i<n;i++)
		{
			if(i==mini)
			{
				continue;
			}
			if(maxi==-1||arrays[i].back()>maxx)
			{
				maxi=i;
				maxx=arrays[i].back();
			}
		}
		int ans1=maxx-minx;
		 mini=0;
		 minx=arrays[0].back();

		for(int i=0;i<arrays.size();i++)
		{
			if(arrays[i].back()>minx)
			{
				mini=i;
				minx=arrays[i].back();
			}
		}
		maxi=-1;
		maxx=0;
		for(int i=0;i<n;i++)
		{
			if(i==mini)
			{
				continue;
			}
			if(maxi==-1||arrays[i][0]<maxx)
			{
				maxi=i;
				maxx=arrays[i][0];
			}
		}
		int ans2=minx-maxx;
		return max(ans1,ans2);
    }
};