#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)
        {
            return -1;
        }
        int begin=0;
		int end=nums.size()-1;
		int mid=(begin+end)/2;
		while(begin<=end)
		{
			if(nums[mid]==target)
			{
				return mid;
			}
			if(target>nums[mid])
			{
				if(target<=nums[end]||nums[mid]>nums[end])
				{
					begin=mid+1;
				}
				else
				{
					end=mid-1;
				}
			}
			else
			{
				if(target>=nums[begin]||nums[mid]<nums[begin])
				{
					end=mid-1;
				}
				else
				{
					begin=mid+1;
				}
			}
			mid=(begin+end)/2;
		}
		return -1;
    }
};