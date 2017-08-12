#include<iostream>
#include<cmath>
using namespace std;
class Solution {
public:
    int smallestFactorization(int a) {
		if(a<=9)
		{
			return a;
		}
		for(int i=9;i>2;i--)
		{
			if(a%i==0)
			{
			    long long x=smallestFactorization(a/i);
			    long long t=i+10l*x;
				if(x!=0)
			    {
			        if(t>INT_MAX||t<INT_MIN)
					{
						return 0;
					}
				    return i+10*x;
			    }
			}
		}
		return 0;
    }
};