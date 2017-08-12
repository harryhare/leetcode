#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
		int n=nums.size();
		bool find=false;;
		for(int i=n-2;i>=0 && find==false;i--)
		{
			for(int j=n-1;j>i;j--)
			{
				if(nums[i]<nums[j])
				{
					swap(nums[j],nums[i]);
					//sort(nums.begin()+i+1,nums.end());
					reverse(nums.begin()+i+1,nums.end());
					return;
				}
			}
		}
		reverse(nums.begin(),nums.end());
		return;
    }
};