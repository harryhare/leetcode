#include<string>
using namespace std;
class Solution {
	static void init(int*lookup)
	{
		lookup[0]=0;
		lookup['I']=1;
		lookup['V']=5;
		lookup['X']=10;
		lookup['L']=50;
		lookup['C']=100;
		lookup['D']=500;
		lookup['M']=1000;
	}
public:
	
    int romanToInt(string s) {
		static int lookup[256];
		init(lookup);
		int n=s.length();
		int sum=0;
		int t1=lookup[s[0]];
		for(int i=0;i<n;i++)
		{
			int t2=lookup[s[i+1]];
			if(t1<t2)
			{
				sum-=t1;
			}
			else
			{
				sum+=t1;
			}
			t1=t2;
		}
		return sum;
    }
};