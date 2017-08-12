#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> ans;
		map<string,int> lookup;
		int count=0;
		int n=strs.size();
		for(int i=0;i<n;i++)
		{
			map<string,int>::iterator iter;
			string t=strs[i];
			sort(t.begin(),t.end());
			iter=lookup.find(t);
			if(iter==lookup.end())
			{
				lookup[t]=ans.size();
				vector<string> temp;
				temp.push_back(strs[i]);
				ans.push_back(temp);
			}
			else
			{
				ans[iter->second].push_back(strs[i]);
			}
		}
		return ans;
    }
};