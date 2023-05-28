//
// Created by mayue on 2023/5/25.
//

#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;


bool cmp(const string &s1, const string &s2) {
    int i = 0;
    int j = 0;
    int n1 = s1.size();
    int n2 = s2.size();
    for (; s1[i] != ' '; i++);
    for (; s2[j] != ' '; j++);
    i++;
    j++;
    if(isalpha(s1[i])&& isdigit(s2[j])){
        return true;
    }
    if(isdigit(s1[i])){
        return false;
    }
    int n=min(n1,n2);
    int r= strcmp(s1.c_str()+i,s2.c_str()+j);
    if (r!=0){
        return r<0;
    }
    // if(n1-i!=n2-j){
    //     return n1-i<n2-j;
    // }
    r= strncmp(s1.c_str(),s2.c_str(),i-1);
    if(r!=0){
        return r<0;
    }
    if(i!=j){
        return i<j;
    }
    return false;
}


class Solution {
public:
    vector<string> reorderLogFiles(vector<string> &logs) {
        stable_sort(logs.begin(),logs.end(),cmp);
        return logs;
    }
};