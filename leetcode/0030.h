#include<string>
#include<vector>
#include<cassert>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> answer;
		if(words.size()==0)
		{
			return answer;
		}
		int n=words.size();
		unordered_map<string,int> wordsmap;
		int *target_count=new int[n];
		int id_count=0;
		for(int i=0;i<n;i++)
		{
			unordered_map<string,int>::iterator iter=wordsmap.find(words[i]);
			if(iter==wordsmap.end())
			{
				wordsmap[words[i]]=id_count;
				target_count[id_count]=1;
				id_count++;
			}
			else
			{
				target_count[iter->second]++;
			}
		}
		int *matchindex=new int[s.size()];
		int *ismatched=new int[n+1];
		int word_len=words[0].size();
		for(int i=0;i+word_len<=s.size();i++)
		{
			unordered_map<string,int>::iterator iter = wordsmap.find(s.substr(i,word_len));
			matchindex[i]=(iter==wordsmap.end())?(-1):(iter->second);
		}
		for(int i=0;i<word_len;i++)
		{
			memset(ismatched,0,sizeof(int)*n);
			int left=i;
			for(int right=left;right+word_len<=s.size();right+=word_len)
			{
				int x=matchindex[right];
				if(x!=-1)
				{
					if(ismatched[x]<target_count[x])//not matched yet
					{
						ismatched[x]++;
						if((right-left+word_len)==words.size()*word_len)
						{
							answer.push_back(left);
							ismatched[matchindex[left]]--;
							left+=word_len;
						}
					}
					else//had already matched
					{
						for(left;matchindex[left]!=x;left+=word_len)
						{
							assert(left<right);
							ismatched[matchindex[left]]--;
						}
						left+=word_len;
					}
				}
				else
				{
					//memset(ismatched,-1,sizeof(int)*n);
					for(left;left<right;left+=word_len)
					{
						ismatched[matchindex[left]]=0;
					}
					left+=word_len;
				}
			}
		}
		delete[]ismatched;
		delete[]matchindex;
		delete[]target_count;
		return answer;
    }
};