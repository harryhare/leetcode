#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
		int s=0;
		vector<string> dirs;
		while(s<path.size()-1)
		{
			
			int i=path.find('/',s+1);
			if(i==string::npos)
			{
				i=path.size();
			}
			string cur=path.substr(s+1,i-s-1);
			if(cur==".")
			{

			}
			else if(cur=="")
			{
			}
			else if(cur=="..")
			{
				if(dirs.size()>0)
				{
					dirs.pop_back();
				}
			}
			else
			{
				dirs.push_back(cur);
			}
			s=i;
		}

		string ans;
		if(dirs.size()==0)
		{
			return "/";
		}
		for(int i=0;i<dirs.size();i++)
		{
			ans+='/'+dirs[i];
		}
		return ans;
    }
};