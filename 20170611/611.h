#include<vector>
#include<algorithm>
using namespace std;
bool check(int a,int b,int c)
{
	return (a+b<c);
}

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
		int ans=0;
		int n=nums.size();
		sort(nums.begin(),nums.end());
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				int max=nums[i]+nums[j];
				int begin=j+1;
				int end=n;
				while(begin<end)
				{
					int mid=(begin+end)/2;
					if(nums[mid]<max)
					{
						begin=mid+1;
					}
					else
					{
						end=mid;
					}
				}
				ans+=begin-j-1;
			}
		return ans;
    }
};