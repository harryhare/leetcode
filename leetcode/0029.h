#include<iostream>
using namespace std;
class Solution {
	inline long long abs(long long x)
	{
		return x>0?x:-x;
	}
public:
    int divide(int dividend, int divisor) {
		if(divisor==0)
		{
			return INT_MAX;
		}
		//if(divisor==1)
		//{
		//	return dividend;
		//}
		//if(divisor==-1)
		//{
		//	return -dividend;
		//}
		int s1=divisor>0?1:-1;
		int s2=dividend>0?1:-1;
		long long dividend1=abs(dividend);
		long long divisor1=abs(divisor);
		long long r=0;
		long long t=divisor1;
		while(t<=dividend1)
		{
			t=(t<<1);
		}
		for(t>>=1;t>=divisor1;t>>=1)
		{
			r=(r<<1)+(dividend1>=t);
			dividend1-=(dividend1>=t)?t:0;
		}
		r=(s1==s2)?r:-r;
		if(r>INT_MAX || r<INT_MIN)
		{
			return INT_MAX;
		}
		else
		{
			return r;
		}
    }
};