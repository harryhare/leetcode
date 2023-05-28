
#include <vector>

using namespace std;

class Solution {
public:
    int minimumSwaps(vector<int> &nums) {
        int n = nums.size();
        if (n <= 1) {
            return 0;
        }

        int min_index = 0;
        int min_num = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] < min_num) {
                min_index = i;
                min_num = nums[i];
            }
        }
        int max_index = n - 1;
        int max_num = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if(nums[i]>max_num){
                max_index=i;
                max_num=nums[i];
            }
        }
        return min_index+(n-1-max_index)-(min_index>max_index);
    }
};