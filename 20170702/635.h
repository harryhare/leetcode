#include<string>
#include<vector>
#include<cassert>
#include<map>
using namespace std;
class LogSystem {
	map<string,int> m;
public:
    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
		m[timestamp]=id;
    }
    
    vector<int> retrieve(string s, string e, string gra) {
		//Year:Month:Day:Hour:Minute:Second,

		
		int i=6;
		int stage=0;
		if(gra=="Minute")
		{
			stage=1;
		}
        else if(gra=="Hour")
		{
			stage=2;
		}
        else if(gra=="Day")
		{
			stage=3;
		}
        else if(gra=="Month")
		{
			stage=4;
		}
        else if(gra=="Year")
		{
			stage=5;
		}
		switch (stage)
		{
		case(5):
		{
			i=6;
			s[i]='0';
			s[i-1]='0';
			e[i]='2';
			e[i-1]='1';
		}
		case(4):
		{
			i=9;
			s[i]='0';
			s[i-1]='0';
			e[i]='1';
			e[i-1]='3';
		}
		case(3):
		{
			i=12;
			s[i]='0';
			s[i-1]='0';
			e[i]='4';
			e[i-1]='2';
		}
		case(2):
		{
			i=15;
			s[i]='0';
			s[i-1]='0';
			e[i]='9';
			e[i-1]='5';
		}
		case (1):
		{
			i=18;
			s[i]='0';
			s[i-1]='0';
			e[i]='9';
			e[i-1]='5';
		}
		default:
			break;
		}

		auto iter=m.lower_bound(s);
		vector<int> ans;
		for(;iter!=m.end()&&iter->first<=e;iter++)
		{
			ans.push_back(iter->second);
		}
		return ans;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */