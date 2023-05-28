#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> counter;
        int n = nums.size();
        long long sum = 0;
        long long max_sum = 0;
        for (int i = 0; i < k; i++) {
            long long in = nums[i];
            sum += in;
            auto iter = counter.find(in);
            if (iter == counter.end()) {
                counter[in] = 1;
            } else {
                iter->second++;
            }
        }
        if(counter.size()==k){
            max_sum=sum;
        }
        for (int j = 0, i = k; i < n; i++, j++) {
            long long in = nums[i];
            long long out = nums[j];
            auto iter = counter.find(in);
            if (iter == counter.end()) {
                counter[in] = 1;
            } else {
                iter->second++;
            }
            iter = counter.find(out);
            iter->second--;
            if(iter->second==0){
                counter.erase(iter);
            }
            sum+=in;
            sum-=out;
            if(counter.size()==k&& sum>max_sum){
                max_sum=sum;
            }
        }
        return max_sum;

    }
};