#include<algorithm>
using namespace std;
const long long mod=1e9+7;
class Solution {
public:

	int kInversePairs(int n, int k) 
	{
		static int a[2][500000];
		memset(a,0,sizeof(a));
		int *p1=a[0];
		int *p2=a[1];
		p1[0]=1;
		
		for(int i=2;i<=n;i++)
		{
			int hi=(i*(i-1)/2);
			p2[0]=1;
			for(int j=1;j<=min(k,hi);j++)
			{
				p2[j]=(mod+p2[j-1]+p1[j])%mod;
				if(j>=i)
				{
					p2[j]=(mod+p2[j]-p1[j-i])%mod;
				}
			}
			swap(p1,p2);
		}
		return p1[k];
	}
};