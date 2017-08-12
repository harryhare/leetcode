#include<string>
#include<vector>
#include<sstream>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
		
		const long long mod=1e9+7;
		int n=s.size();
		//vector<vector<int>> dp(s.size()+1,vector<int>(3,0));
		long long a[2][3];
		long long* dp1=a[0];
		long long* dp2=a[1];
		memset(a,0,sizeof(a));
		dp1[0]=1;
		for(int i=1;i<=s.size();i++)
		{
			swap(dp1,dp2);
			memset(dp1,0,sizeof(a[0]));
			if(s[i-1]=='*')
			{
				dp1[0]=(0ll+9ll*dp2[0]+9ll*dp2[1]+6ll*dp2[2])%mod;
				dp1[1]=(0ll+dp2[0])%mod;
				dp1[2]=(0ll+dp2[0])%mod;
				continue;
			}
			if(s[i-1]=='0')
			{
				dp1[0]=(0ll+dp2[1]+dp2[2])%mod;
			}
			else if(s[i-1]=='1')
			{
				dp1[0]=(0ll+dp2[0]+dp2[1]+dp2[2])%mod;
				dp1[1]=(0ll+dp2[0])%mod;
			}
			else if(s[i-1]=='2')
			{
				dp1[0]=(0ll+dp2[0]+dp2[1]+dp2[2])%mod;
				dp1[2]=(0ll+dp2[0])%mod;
			}
			else if(s[i-1]<='6')
			{
				dp1[0]=(0ll+dp2[0]+dp2[1]+dp2[2])%mod;
			}
			else 
			{
				dp1[0]=(0ll+dp2[0]+dp2[1])%mod;
			}
		}
		return dp1[0];
    }
};