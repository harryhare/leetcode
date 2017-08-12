#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
		int sum=words[0].size();
		int s=0;
		int i=1;
		string ans="";
		vector<string> v;
		while(i<words.size())
		{
			sum+=words[i].size()+1;
			if(sum>maxWidth)
			{
				if(i-s==1)
				{
					ans+=words[s];
					ans+=string(maxWidth-words[s].size(),' ');
					v.push_back(ans);
					ans="";
				}
				else
				{
					sum-=words[i].size()+1;
					int empty=maxWidth-sum;
					int n=i-s-1;
					int leastspace=empty/n;
					int needextra=empty%n;
					ans=words[s];
					for(int j=s+1;j<i;j++)
					{
						ans+=string(leastspace+1+(needextra>0),' ');
						ans+=words[j];
						needextra--;
					}
					v.push_back(ans);
					ans="";
				}
				s=i;
				sum=words[i].size();
			}
			i++;
		}
		ans=words[s];
		for(int j=s+1;j<words.size();j++)
		{
			ans+=' ';
			ans+=words[j];
		}
		ans+=string(maxWidth-ans.size(),' ');
		v.push_back(ans);
		return v;
    }
};