#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<long long> dp0 = {1};
    vector<long long> dp1 = {0};

    long long get_continue_count(int n) {
        int i = dp0.size();
        if (i > n) {
            return dp0[n] + dp1[n];
        }
        for (; i <=n; i++) {
            dp0.push_back( dp0[i - 1] + dp1[i - 1]);
            dp1.push_back( dp0[i - 1]);
        }
        return dp0[n]+dp1[n];
    }

    long long get_bucket_subset(vector<int> bucket) {
        sort(bucket.begin(), bucket.end());
        long long res = 1;
        int c = 0;
        int n = bucket.size();
        for (int i = 0; i < n; i++) {
            c++;
            if (i == n - 1 || bucket[i + 1] != bucket[i] + 1) {
                res *= get_continue_count(c);
                c = 0;
            }
        }
        return res;
    }

    long long countTheNumOfKFreeSubsets(vector<int> &nums, int k) {
        vector<vector<int>> buckets(k, vector<int>());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int c = nums[i];
            buckets[c % k].push_back(c / k);
        }
        long long res = 1;
        for (int i = 0; i < k; i++) {
            vector<int> &bucket = buckets[i];
            res*=get_bucket_subset(bucket);
        }
        return res;
    }
};

int main(){
   vector<int> number= {5,4,6};
   Solution s;
   cout<<s.countTheNumOfKFreeSubsets(number,1)<<endl;

}