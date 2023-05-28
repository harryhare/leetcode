#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int min_cost = prices[0];
        int max_earn = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++) {
            int p = prices[i];
            if(p<min_cost){
                min_cost=p;
                continue;
            }
            int earn = p - min_cost;
            if(earn>max_earn){
                max_earn=earn;
            }

        }
        return max_earn;
    }
};