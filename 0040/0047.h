#include<vector>
#include<algorithm>
using namespace std;
class Solution {
	vector<vector<int>> ans;
	void fun(vector<int> &nums,int i)
	{
		int n=nums.size();
		if(i==n-1)
		{
			ans.push_back(nums);
			return;
		}
		fun(nums,i+1);

		for(int j=n-1;j>i;j--)
		{
			if(nums[i]<nums[j])
			{
				swap(nums[i],nums[j]);
				reverse(nums.begin()+i+1,nums.end());
				fun(nums,i+1);
			}
		}
		//reverse(nums.begin()+i,nums.end());
	}

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
		int n=nums.size();
		ans.clear();
		sort(nums.begin(),nums.end());
		fun(nums,0);
		return ans;
    }
};