#include<vector>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int>& nums) {
		int n=nums.size();
		if(n<3)
		{
			return false;
		}
		vector<int> count;
		count.push_back(1);
		for(int i=1;i<n;i++)
		{
			if(nums[i]==nums[i-1])
			{
				count.back()+=1;
			}
			else
			{
				for(int j=nums[i-1]+1;j<nums[i];j++)
				{
					count.push_back(0);
				}
				count.push_back(1);
			}
		}
		count.push_back(0);
		n=count.size();
		queue<int> q;
		for(int i=0;i<n;i++)
		{
			if(count[i]==q.size())
			{
				continue;
			}
			while(q.size()<count[i])
			{
				q.push(i);
			}
			while(q.size()>count[i])
			{
				int x=q.front();
				q.pop();
				if(i-x<3)
				{
					return false;
				}
			}
		}
		return true;
    }
};