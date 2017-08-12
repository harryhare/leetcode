#include<vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
		vector<int> maxheight;
        int max=-1;
		int maxi=-1;
		int n=height.size();

		for(int i=0;i<n;i++)
		{
			if(height[i]>=max)
			{
				max=height[i];
				maxi=i;
			}
			maxheight.push_back(max);
		}
		max=-1;
		for(int i=n-1;i>maxi;i--)
		{
			if(height[i]>max)
			{
				max=height[i];
			}
			maxheight[i]=max;
		}
		int count=0;
		for(int i=0;i<n;i++)
		{
			count+=maxheight[i]-height[i];
		}
		return count;
    }
};