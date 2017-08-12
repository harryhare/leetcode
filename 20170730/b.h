#include<vector>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
    int minSteps(int n) {
		int ans=0;
		for(int i=2;i<32&&n!=1;i++)
		{
			while(n%i==0)
			{
				ans+=i;
				n=n/i;
			}
		}
		if(n!=1)
		{
			ans+=n;
		}
		return ans;
    }
};