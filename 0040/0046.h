#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ans;
		if(nums.size()==1)
		{
			ans.push_back(nums);
			return ans;
		}
		vector<int> t=nums;
		t.pop_back();
		vector<vector<int>> pre=permute(t);
		for(int i=0;i<pre.size();i++)
		{
			vector<int> x=pre[i];
			x.push_back(nums.back());
			ans.push_back(x);
			for(int j=nums.size()-1;j>0;j--)
			{
				swap(x[j],x[j-1]);
				ans.push_back(x);
			}
		}
		return ans;
    }
};