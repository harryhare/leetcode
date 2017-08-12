#include<vector>
#include<string>
#include<map>
#include<cstring>
using namespace std;
class Solution {
public:
    string predictPartyVictory(string senate) {
        int rbaned=0,dbaned=0;
		int n=senate.size();
		string ans;
		while(1)
		{
			int countr=0;
			int countd=0;
			for(int i=0;i<n;i++)
			{
				if(senate[i]=='R')
				{
					if(rbaned==0)
					{
						dbaned++;
						countr++;
					}
					else
					{
						rbaned--;
						senate[i]='B';
					}
				}
				else if(senate[i]=='D')
				{
					if(dbaned==0)
					{
						countd++;
						rbaned++;
					}
					else
					{
						dbaned--;
						senate[i]='B';
					}
				}
			}
			if(countr==0||countd==0)
			{
				ans=(countr!=0?"Radiant":"Dire");
				break;
			}
		}
		return ans;
		
    }
};