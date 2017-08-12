#include<vector>
#include<string>
#include<map>
using namespace std;
class Solution {
	int dp[20][1000];
	int a[51];
public:
    int maxA(int N) {
		int n=N;
		for(int i=0;i<=6;i++)
		{
			a[i]=i;
		}
		a[7]=9;
		//a[8]=12;
		//a[9]=16;
		//a[10]=20;
		for(int i=7;i<=n;i++)
		{
			a[i]=i;
			for(int j=1;j<n;j++)
			{
				a[i]=max(a[i],j*a[i-j]);
			}
		}
		return a[n];
    }
};