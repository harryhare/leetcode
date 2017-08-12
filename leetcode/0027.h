#include<vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		int n=nums.size();
		int i=0;
		for(int j=0;j<n;j++)
		{
			if(nums[j]!=val)
			{
				nums[i++]=nums[j];
			}
		}
		return i;
    }
};