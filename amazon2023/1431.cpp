//
// Created by mayue on 2023/5/24.
//
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();
        vector<bool> result(n, false);
        int max_candies=*max_element(candies.begin(),candies.end());
        for(int i=0;i<n;i++){
            if(candies[i]+extraCandies>=max_candies){
                result[i]= true;
            }
        }
        return result;
    }
};

int main(){
    vector<int> candies={1,2,3,4};
    auto max_candies=max_element(candies.begin(),candies.end());
    cout<<*max_candies<<endl;
}