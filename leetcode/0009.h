class Solution {
public:
    bool isPalindrome(int x) {
		if(x<0)
		{
			return false;
		}
		int t1=1;
		int t2=1;
		while(x/t1/10)
		{
			t1*=10;
		}
		for(;t2<t1;t1/=10,t2*=10)
		{
			if(x/t1%10 !=x/t2%10)
			{
				return false;
				break;
			}
		}
        return true;
    }
};