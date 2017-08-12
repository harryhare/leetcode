#include<cmath>
class Solution {
public:
    bool judgeSquareSum(int c) {
		int upbound=sqrt(c/2)+1;
		for(int i=0;i<=upbound;i++)
		{
			int y=(sqrt(c-i*i));
			if(y*y==c-i*i||(y+1)*(y+1)==c-i*i)
			{
				return true;
			}
		}
		return false;
    }
};