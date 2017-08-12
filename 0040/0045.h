#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
		int n=nums.size();
		int lo=0;
		int hi=0;
		int count=0;
		for(int i=0;i<n;)
		{
			int max=hi;
			if(max>=n-1)
			{
				return count;
			}
			for(;i<=hi;i++)
			{
				if(i+nums[i]>max)
				{
					max=i+nums[i];
				}
			}
			count++;
			hi=max;
		}
		return -1;
    }
};