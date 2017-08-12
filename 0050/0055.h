#include<vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int start=0;
		for(int i=0;i<nums.size()&&i<=start;i++)
		{
			if(i+nums[i]>start)
			{
				start=i+nums[i];
			}
			if(start>=nums.size()-1)
			{
				return true;
			}
		}
		return false;
    }
};