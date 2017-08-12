#include<string>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string,int> pool1;
		for(int i=0;i<list1.size();i++)
		{
			pool1[list1[i]]=i;
		}
		int minsum=list1.size()+list2.size()+1;
		vector<string> ans;
		for(int i=0;i<list2.size();i++)
		{
			auto iter=pool1.find(list2[i]);
			if(iter==pool1.end())
			{
				continue;
			}
			int tempsum=iter->second+i;
			if(tempsum<minsum)
			{
				ans.clear();
				ans.push_back(list2[i]);
				minsum=tempsum;
			}
			else if(tempsum==minsum)
			{
				ans.push_back(list2[i]);
			}
		}
    }
};