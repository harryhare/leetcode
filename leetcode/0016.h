#include<vector>
#include<algorithm>
using namespace std;

inline int fmin(int a,int b)
{
	return a<b?a:b;
}


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
		int n=nums.size();
		int min=INT_MAX;
		int r=0;
		for(int i=0;i<n-2&&min!=0;i++)
		{
		    if(i>=1 && nums[i-1]==nums[i])
		    {
		        continue;
		    }
			int j=i+1;
			int k=n-1;
			int target1=target-nums[i];
			while(j<k)
			{
				int t=nums[j]+nums[k];
				if(t==target1)
				{
					min=0;
					r=target;
					break;
				}
				else if(t>target1)
				{
					if(t-target1<min)
					{
						min=t-target1;
						r=nums[i]+nums[j]+nums[k];
					}
					for(k--;j<k&&nums[k]==nums[k+1];k--);
				}
				else
				{
					if(target1-t<min)
					{
						min=target1-t;
						r=nums[i]+nums[j]+nums[k];
					}					
					for(j++;j<k&&nums[j]==nums[j-1];j++);
				}
			}
		}
		return r;
    }
};