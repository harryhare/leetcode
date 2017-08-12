#include<vector>
#include<cassert>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int n=nums.size();
		int maxsum=INT_MIN;
		int pre=0;
		for(int i=0;i<n;i++)
		{
			pre+=nums[i];
			maxsum=max(maxsum,pre);
			if(pre<=0)
			{
				pre=0;
			}
		}
		return maxsum;
    }
};