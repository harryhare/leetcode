#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		int n=nums.size();
		vector<vector<int>> result;
		for(int i=0;i<n-2;i++)
		{
		    if(i>=1 && nums[i-1]==nums[i])
		    {
		        continue;
		    }
			int j=i+1;
			int k=n-1;
			int target=-nums[i];
			while(j<k)
			{
				if(nums[j]+nums[k]==target)
				{
					vector<int> t;
					t.push_back(nums[i]);
					t.push_back(nums[j]);
					t.push_back(nums[k]);
					result.push_back(t);
					for(j++;j<k&&nums[j]==nums[j-1];j++);
					for(k--;j<k&&nums[k]==nums[k+1];j--);
				}
				else if(nums[j]+nums[k]>target)
				{
					for(k--;j<k&&nums[k]==nums[k+1];k--);
				}
				else
				{					
					for(j++;j<k&&nums[j]==nums[j-1];j++);
				}
			}
		}
		return result;
		
    }
};