#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
		int m=word1.size();
		int n=word2.size();
		vector<vector<int>> dp(n+1,vector<int>(m+1,0));
		for(int i=0;i<=m;i++)
		{
			dp[0][i]=i;
		}
		for(int i=1;i<=n;i++)
		{
			dp[i][0]=i;
			for(int j=1;j<=m;j++)
			{
				dp[i][j]=dp[i-1][j-1]+(word2[i-1]!=word1[j-1]);//replace
				dp[i][j]=min(dp[i][j],dp[i][j-1]+1);//insert
				dp[i][j]=min(dp[i][j],dp[i-1][j]+1);//delete
			}
		}
		return dp[n][m];
    }
};