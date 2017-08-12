class Solution {
public:
    double myPow(double x, int n) {
		double ans=1;
		if(n<0)
		{
			x=1/x;
			n=-n;
		}
        while(n)
		{
			if(n&1)
			{
				ans*=x;
			}
			x*=x;
			n=(n>>1);
		}
		return ans;
    }
};