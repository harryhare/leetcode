#include<vector>
#include<list>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Excel {
	int *a;
	int h;
	int w;
	unordered_map<int,list<int>> listener;
	unordered_map<int,unordered_set<int>> reversel;
public:
    Excel(int H, char W) {
		 h=H;
		 w=W-'A'+1;
		a=new int[h*w];    
		memset(a,0,h*w*sizeof(int));
    }
    void update(int x,int v)
	{
		auto iter=listener.find(x);
		if(iter!=listener.end())
		{
			list<int>&ll=iter->second;
			for(int l:ll)
			{
				//a[l]+=v-a[x];
				update(l,a[l]+v-a[x]);
			}
		}
		a[x]=v;
	}

	void set(int x,int v)
	{
		//auto iter=listener.find(x);
		//if(iter!=listener.end())
		//{
		//	list<int>&ll=iter->second;
		//	for(int l:ll)
		//	{
		//		a[l]+=v-a[x];
		//	}
		//}
		//a[x]=v;
		update(x,v);
		auto iter1=reversel.find(x);
		if(iter1!=reversel.end())
		{
			auto&rr=iter1->second;
			for(int r:rr)
			{
				listener[r].remove(x);
			}
			//reversel.erase(iter);
			iter1->second.clear();
		}
	}
    void set(int r, char c, int v) 
	{
		int x=trans(r,c);
		set(x,v);
    }
    
    int get(int r, char c) 
	{
        return a[trans(r,c)];
    }
	inline int trans(int r,int c)
	{
	    int i=r-1;
		int j=c-'A';
		return i*w+j;
	}
	inline int trans(const char * str)
	{
		char c=str[0];
		int r=atoi(str+1)	;
		return trans(r,c);
	}
    
    int sum(int r, char c, vector<string> strs) 
	{
		int x=trans(r,c);
		int sum=0;
		for(string str:strs)
		{
			int single=true;
			int rl,rr,cl,cr;
			int i;
			for(i=0;i<str.size();i++)
			{
				if(str[i]==':')
				{
					single=false;
					break;
				}
			}
			cl=str[0]-'A';
			rl=stoi(str.substr(1,i-1))-1;
			rr=rl;
			cr=cl;
			if(single==false)
			{
				cr=str[i+1]-'A';
				rr=stoi(str.substr(i+2))-1;
			}
			for(int r=rl;r<=rr;r++)
			{
				for(int c=cl;c<=cr;c++)
				{
					int xx=r*w+c;
					listener[xx].push_front(x);
					reversel[x].insert(xx);
					sum+=a[xx];
				}
			}
		}
		a[x]=sum;
		return sum;
	}
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel obj = new Excel(H, W);
 * obj.set(r,c,v);
 * int param_2 = obj.get(r,c);
 * int param_3 = obj.sum(r,c,strs);
 */