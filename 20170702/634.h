
class Solution {
	const int mod=1e9+7;
public:
    int findDerangement(int n) {
        if(n==1)
		{
			return 0;
		}
		if(n==2)
		{
			return 1;
		}
		long long t;
		long long a=0;
		long long b=1;
		for(int i=3;i<=n;i++)
		{
			t=(i-1)*((b+a)%mod)%mod;
			a=b;
			b=t;
		}
		return t;
    }
};