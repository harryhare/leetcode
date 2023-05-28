//
// Created by mayue on 2023/5/25.
//
#include<string>
using namespace std;

class Solution {
public:
    bool makePalindrome(string s) {
        int n=s.size();
        int counter=0;
        for(int i=0,j=n-1;i<j;i++,j--){
            if(s[i]!=s[j]){
                counter++;
                if(counter>2){
                    return false;
                }
            }
        }
        return  true;
    }
};