#include<vector>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int a[30];
		memset(a,0,sizeof(a));
		for(auto t:tasks)
		{
			a[t-'A']++;
		}
		sort(a,a+26);
		int i=0;
		while(a[i]==0)i++;
		int j=25;
		while(a[25]==a[j]&&j>=0)j--;
		int t=(a[25]-1)*(n+1)+(25-j);
		return max((int)tasks.size(),t);

    }
};