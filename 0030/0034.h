#include<vector>
using namespace std;




class Solution {
	int search1(vector<int>& nums,int target)
	{
		int lo=0;
		int hi=nums.size()-1;
		while(lo<hi)
		{
			int mid=(lo+hi)/2;
			if(nums[mid]==target)
			{
				hi=mid;
			}
			else if(nums[mid]<target)
			{
				lo=mid+1;
			}
			else
			{
				hi=mid-1;
			}
		}
		if(nums.size()>0&&nums[lo]==target)
		{
			return lo;
		}
		return -1;
	}
	int search2(vector<int>& nums,int target)
	{
		int lo=0;
		int hi=nums.size()-1;
		while(lo<hi)
		{
			int mid=(lo+hi+1)/2;
			if(nums[mid]==target)
			{
				lo=mid;
			}
			else if(nums[mid]<target)
			{
				lo=mid+1;
			}
			else
			{
				hi=mid-1;
			}
		}
		if(nums.size()>0&&nums[lo]==target)
		{
			return lo;
		}
		return -1;
	}


public:
    vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ans;
		int i1=search1(nums,target);
		int i2=search2(nums,target);
		{
			ans.push_back(i1);
			ans.push_back(i2);
		}
		return ans;
    }
};