#include<vector>
#include<string>
#include<sstream>
#include<cassert>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
		unordered_map<string,vector<string>> book;
		vector<vector<string>> ans;
		for(string path:paths){
			int i=0;
			while(path[i]!=' ')
			{
				i++;
			}
			string d=path.substr(0,i);
			int begin;
			int end;
			while(i<path.size()){
				i++;
				begin=i;
				while(path[i]!='(')
				{
					i++;
				}
				assert(path[i]=='(');
				end=i;
				string filename=path.substr(begin,end-begin);
				begin=i+1;
				while(path[i]!=' '&& i<path.size()){
					i++;
				}
				i--;
				assert(path[i]==')');
				end=i;
				i++;
				string content=path.substr(begin,end-begin);
				auto iter=book.find(content);
				if(iter==book.end())
				{
					vector<string> t;
					t.push_back(d+'/'+filename);
					//vector<string> & ref=ans.back();
					book[content]=t;
				}
				else
				{
					(book[content]).push_back(d+'/'+filename);
				}
			}
		}
		for(auto iter=book.begin();iter!=book.end();iter++)
		{
			if(iter->second.size()>1)
			{
				ans.push_back(iter->second);
			}
		}
		return ans;
    }
};