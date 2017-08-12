#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
		int n=nums.size();
		if(n==0)
		{
			return 1;
		}
		for(int i=0;i<n;i++)
		{
			int j=nums[i];
			while(j>0 && j<=n && nums[j-1]!=j )
			{
				swap(j,nums[j-1]);
			}
		}
		for(int i=0;i<n;i++)
		{
			if(nums[i]!=i+1)
			{
				return i+1;
			}
		}
		return n+1;
    }
};