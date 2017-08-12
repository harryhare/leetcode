class Solution {
public:
    int mySqrt(int x) {
		//return sqrt(x);
		int begin=0;
		int end=x;
		while(begin<end)
		{
			int mid=end-(end-begin)/2;
			long long sqare=(long long)mid*mid;
			if(sqare==x)
			{
				return mid;
			}
			if(sqare<x)
			{
				begin=mid;
			}
			else
			{
				end=mid-1;
			}
		}
		return begin;
    }
};