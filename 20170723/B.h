#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

bool cmp(vector<int> &v1,vector<int>&v2)
{
	return v1[1]<v2[1];
}
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
		sort(pairs.begin(),pairs.end(),cmp);
		int n=pairs.size();
		if(n==0)
		{
			return 0;
		}
		int cur_end=pairs[0][0]-1;
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(pairs[i][0]>cur_end)
			{
				cur_end=pairs[i][1];
				ans++;
			}
		}
		return ans;
    }
};