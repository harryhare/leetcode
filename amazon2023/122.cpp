#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int buy = prices[0];
        int profit = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++) {
            int p = prices[i];
            if (p > buy) {
                profit += (p - buy);
            }
            buy = p;
        }
        return profit;
    }
};