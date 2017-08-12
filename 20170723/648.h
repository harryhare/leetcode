#include<vector>
#include<string>
#include<set>
#include<iostream>
#include<algorithm>
using namespace std;

static bool cmp(string &s1,string&s2)
{
	return s1<s2;
}
static bool issubstr(string target,string word)
{
	if(target.length()>word.length())
	{
		return false;
	}
	int i=0;
	int j=0;
	while(word[i]!=0&target[i]==word[j])
	{
		i++;
		j++;
	}
	return (target[i]==0);
}
class Solution {
	
	set<string> shortdict;
	string find(string word)
	{
		auto iter=shortdict.upper_bound(word);
		cout<<(*iter)<<endl;
		if(iter!=shortdict.end()&& issubstr(*iter,word))
		{
			return *iter;
		}
		return word;
	}
public:
    string replaceWords(vector<string>& dict, string sentence) {
		if(dict.size()==0)
		{
			return sentence;
		}
		sort(dict.begin(),dict.end());
		shortdict.insert(dict[0]);
		for(int i=1;i<dict.size();i++)
		{
			string str=dict[i];
			if(!issubstr(dict[i-1],str))
			{
				shortdict.insert(str);
			}
		}
		string ans="";
		int lo=0;
		while(lo<sentence.size())
		{
			while(sentence[lo]==' ')
			{
				lo++;
			}
			int begin=lo;
			while(isalpha(sentence[lo]))
			{
				lo++;
			}
			int end=lo;
			string word=sentence.substr(begin,end-begin);
			if(ans!="")
			{
				ans+=' ';
			}
			ans+=find(word);
		}

		return ans;
    }
};