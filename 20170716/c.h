#include<vector>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
		vector<int> sum(nums.size()+1,0);
		sum[0]=0;
		for(int i=0;i<nums.size();i++)
		{
			sum[i+1]=sum[i]+nums[i];
		}
		int n=nums.size();
		double maxa=(double)sum[k]/k;
		for(int i=0;i+k<=n;i++)
		{
			double cura=(double)(sum[k+i]-sum[i])/k;
			if(cura<maxa)
			{
				continue;
			}
			maxa=max(maxa,cura);
			for(int j=i+k;j<n;j++)
			{
				if(nums[i]>=cura)
				{
					cura=(double)(sum[j+1]-sum[i])/(j+1-i);
					maxa=max(cura,maxa);
				}
				else
				{
					break;
				}
			}
		}
		return maxa;
    }
};