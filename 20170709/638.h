#include<vector>
using namespace std;
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
		int n=price.size();
		//int offer=special.size();
		int state=1;
		for(int i=0;i<n;i++)
		{
			state*=(needs[i]+1);
		}
		//unsigned* dp=new unsigned[state];
		//memset(dp,-1,sizeof(int)*(state));
		vector<unsigned> dp(state,-1);
		dp[0]=0;
		for(auto offer:special)
		{
			for(int i=0;i<state;i++)
			{
				if(dp[i]==(-1u))
				{
					continue;
				}
				int s=i;
				bool update=true;
				int news=0;
				int step=state;
				for(int j=0;j<n;j++)
				{
					step/=(needs[j]+1);
					int curnum=i/step%(needs[j]+1);
					if(offer[j]+curnum>needs[j])
					{
						update=false;
						break;
					}
					news=news*(needs[j]+1)+(offer[j]+curnum);
				}
				if(update&&dp[news]>dp[s]+offer[n])
				{
					dp[news]=dp[s]+offer[n];
				}
			}
		}
		int d=1;
		for(int k=n-1;k>=0;k--)
		{
			for(int i=0;i<state;i++)
			{
				if(dp[i]==(-1u))
				{
					continue;
				}
				int curnum=i/d%(needs[k]+1);
				if(curnum<needs[k]&&dp[i+d]>dp[i]+price[k])
				{
					dp[i+d]=dp[i]+price[k];
				}
			}
			d*=(needs[k]+1);
		}
		int tmp=dp[state-1];
		return tmp;
    }
};