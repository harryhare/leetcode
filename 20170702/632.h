#include<vector>
using namespace std;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int minlen=1e7;
		vector<int> ans;
		ans.push_back(0);
		ans.push_back(0);
		vector<int> i;
		for(int j=0;j<nums.size();j++)
		{
			i.push_back(0);
		}
		while(true)
		{
			int mini=0;
			int s=nums[0][i[0]];
			int e=nums[0][i[0]];
			for(int j=1;j<=nums.size()-1;j++)
			{
				if(nums[j][i[j]]<s)
				{
					mini=j;
					s=nums[j][i[j]];
				}
				if(nums[j][i[j]]>e)
				{
					e=nums[j][i[j]];
				}
			}
			int len=e-s;
			if(len<minlen)
			{
				minlen=len;
				ans[0]=s;
				ans[1]=e;
			}
			i[mini]++;
			if(i[mini]>=nums[mini].size())
			{
				break;
			}
		}
		return ans;
    }
};