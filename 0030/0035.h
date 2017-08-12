#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo=0;
		int hi=nums.size()-1;
		
		while(lo<hi)
		{
			if(nums[lo]>target)
			{
				return lo;
			}
			if(nums[hi]<target)
			{
				return hi+1;
			}
			int mid=(lo+hi)/2;
			if(nums[mid]==target)
			{
				return mid;
			}
			else if(nums[mid]>target)
			{
				hi=mid-1;
			}
			else
			{
				lo=mid+1;
			}

		}
    }
};