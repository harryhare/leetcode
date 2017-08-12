#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
class Solution {
	bool cmp(int a,int b)
	{
		return a>b;
	}

	vector<vector<int> > ans;
	void dsp(vector<int>& candidates,int ii,int target,vector<int> pre)
	{
		if(target==0)
		{
			ans.push_back(pre);
			return;
		}
		if(ii==candidates.size())
		{
			return;
		}
		if(candidates[ii]>target)
		{
			return;
		}
		int cur=candidates[ii];
		dsp(candidates,ii+1,target,pre);
		int upbound=target/cur;
		for(int i=0;i<upbound;i++)
		{
			pre.push_back(cur);
			target-=cur;
		    dsp(candidates,ii+1,target,pre);
    	}
	}
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(),candidates.end());
		ans.clear();
		vector<int> pre;
		dsp(candidates,0,target,pre);
		return ans;
    }
};