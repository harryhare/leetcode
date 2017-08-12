/*594*/
#include<map>
#include<vector>
using namespace std;
class Solution {
public:
    int findLHS(vector<int>& nums) {
		map<int,int> record;
		for(auto i=nums.begin();i!=nums.end();i++)
		{
			record[*i]++;
		}

		auto i=record.begin();
		auto pre=i;
		
		int maxlen=0;
		if(i!=record.end())
		{
			for(i++;i!=record.end();i++)
			{
				if(i->first-pre->first==1)
				{
					maxlen=max(maxlen,i->second+pre->second);
				}
				pre=i;
			}
		}
		return maxlen;
    }
};