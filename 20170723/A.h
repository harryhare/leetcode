#include<vector>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
		int n=nums.size();
		int* a=new int[n+1];
		memset(a,0,(n+1)*sizeof(int));
		for(int i=0;i<n;i++)
		{
			a[nums[i]]++;
		}
		vector<int> ans(2,0);
		
		for(int i=1;i<=n;i++)
		{
			if(a[i]==2)
			{
				ans[0]=i;
			}
			else if(a[i]==0)
			{
				ans[1]=i;
			}
		}
		return ans;
    }
};