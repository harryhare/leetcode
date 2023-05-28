#include <cmath>

/*
 * 这道题太无聊了
 */
class Solution {
public:
    int kthFactor(int n, int k) {
        int counter=0;
        int upbound=n;
        for(int i=1;i<upbound;i++){
            if(n%i==0){
                counter++;
                if(counter==k){
                    return i;
                }
            }
        }
        return -1;
    }
};