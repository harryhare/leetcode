#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int newInteger(int n) {
		int x=0;
		int i=1;
		while(n!=0)
		{
			x+=n%9*i;
			i*=10;
			n=n/9;
		}
		return x;
    }
};