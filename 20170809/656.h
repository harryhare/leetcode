#include<vector>
using namespace std;
class Solution {
public:
        vector<int> cheapestJump(vector<int>& A, int B) {
                int n = A.size();
                if (A[0] == -1 ||A.back()==-1)
                {
                        return vector<int>();
                }
                vector<unsigned> mincost(n, (unsigned)-1);
                vector<unsigned> post(n, (unsigned)-1);
                mincost[n-1] = 0;
                post[n-1] = -1;
                for (int i = n-1; i >=0; i--)
                {
                        if (A[i] != -1 && mincost[i] != (unsigned)-1)
                        {
                                mincost[i] += A[i];
                                for (int j = max(0,i-B); j<i; j++)
                                {
                                        if (mincost[i] < mincost[j] || (mincost[i] == mincost[j] && i<post[j]))
                                        {
                                                post[j] = i;
                                                mincost[j] = mincost[i];
                                        }
                                }
                        }
                }
                if (mincost[0] == (unsigned)-1)
                {
                        return vector<int>();
                }
                vector<int> ans;
                int x = 0;
                while (post[x] != (unsigned)-1)
                {
                        ans.push_back(x + 1);
                        x = post[x];
                }
                ans.push_back(n);
                return ans;
        }

};