#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
		int *a=new int[nums.size()];
		memset(a,0,sizeof(int)*nums.size());
		int ans=0;
		for(int i=0;i<nums.size();i++)
		{
			int end=nums[i];
			int c=1;
			a[i]=1;
			while(a[end]==0)
			{
				a[end]=1;
				end=nums[end];
				c++;
			}
			if(c>ans)
			{
				ans=c;
			}
		}
		delete[]a;
		return ans;
    }
};