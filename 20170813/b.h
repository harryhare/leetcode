#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		int n=arr.size();
        int lo=0;
		int hi=n;
		while(lo<hi)
		{
			int mi=(lo+hi)/2;
			if(arr[mi]>=x)
			{
				hi=mi;
			}
			else
			{
				lo=mi+1;
			}
		}
		int i=lo-1;
		int j=lo;
		while(j-i<=k+2)
		{
			if(j>=n)
			{
				i=n-k-1;
				break;
			}
			if(i<=-1)
			{
				j=k+1;
				break;
			}
			if(arr[i]+arr[j]>=(x<<1))
			{
				i--;
			}
			else
			{
				j++;
			}
		}
		vector<int> ans;
		for(int ii=i+1;ii<j;ii++)
		{
			ans.push_back(arr[ii]);
		}
		return ans;
    }
};