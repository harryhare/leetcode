#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> s;
        s.push(-1);
        for (int i = n - 1; i >= 0; i--) {
            int c=temperatures[i];
            while(s.top()!=-1 && temperatures[s.top()]<=c ){
                s.pop();
            }
            if(s.top()!=-1) {
                res[i]=s.top()-i;
            }
            s.push(i);

        }
        return res;
    }
};