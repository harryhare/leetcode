#include<string>
using namespace std;
class BigInt
{
public:
	int * nums;
	int l;
	BigInt()
	{
		nums=NULL;
		l=0;
	}
	~BigInt()
	{
		if(nums!=NULL)
		{
			delete[] nums;
		}
	}
	void FromString(const string str)
	{
		nums=new int[str.size()];
		l=0;
		for(int i=str.size()-1;i>=0;i--)
		{
			nums[l++]=str[i]-'0';
		}
	}
	void muliply(const BigInt& b)
	{
		int n=b.l;
		int* r=new int[l+n];
		memset(r,0,sizeof(int)*(l+n));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<l;j++)
			{
				r[i+j]+=b.nums[i]*nums[j];
			}
		}
		int residue=0;
		for(int i=0;i<l+n;i++)
		{
			r[i]+=residue;
			residue=r[i]/10;
			r[i]=r[i]%10;
		}
		delete[]nums;
		nums=r;
		l=l+n;
		while(l>0&&r[l-1]==0)
		{
			l--;
		}
	}
	string ToString()const
	{
		if(l==0)
		{
			return "0";
		}
		string r="";
		for(int i=l-1;i>=0;i--)
		{
			r+=char(nums[i]+'0');
		}
		return r;
	}
};
class Solution {
public:
    string multiply(string num1, string num2) {
		BigInt big1;
		BigInt big2;
		big1.FromString(num1);
		big2.FromString(num2);
		big1.muliply(big2);
		string ans=big1.ToString();
		return ans;
    }
};