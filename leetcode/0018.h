#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	vector<vector<int> > fourSum(vector<int>& nums, int target) {
		vector<vector<int> > result;
		if(nums.size()<4)
		{
			return result;
		}
        sort(nums.begin(),nums.end());
		int n=nums.size();
		int count=0;
		for(int h=0;h<n-3;)
		{
			for(int i=h+1;i<n-2;)
			{
				int j=i+1;
				int k=n-1;
				int target1=target-nums[i]-nums[h];
				while(j<k)
				{
					int t=nums[j]+nums[k];
					if(t==target1)
					{
						vector<int> temp;
						temp.push_back(nums[h]);
						temp.push_back(nums[i]);
						temp.push_back(nums[j]);
						temp.push_back(nums[k]);
						result.push_back(temp);
						for(k--;j<k&&nums[k]==nums[k+1];k--);
						for(j++;j<k&&nums[j]==nums[j-1];j++);
					}
					else if(t>target1)
					{
						for(k--;j<k&&nums[k]==nums[k+1];k--);
					}
					else
					{				
						for(j++;j<k&&nums[j]==nums[j-1];j++);
					}
				}
				for(i++;i<n-2&&nums[i-1]==nums[i];i++);
			}
			for(h++;h<n-3&&nums[h-1]==nums[h];h++);
		}
		return result;
    }
};