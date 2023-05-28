#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;


enum LastState {
    Enter,
    Leave,
    None,
};

class Solution {
public:
    vector<int> timeTaken(vector<int> &arrival, vector<int> &state) {
        int n = arrival.size();
        priority_queue<int,vector<int>,std::greater<int>> enter;
        priority_queue<int,vector<int>,std::greater<int>> leave;
        vector<int> res(n, 0);
        int arrived=0;
        int t=0;
        LastState last_state=None;
        while (true){
            while(arrived<n && arrival[arrived]<=t){
                if(state[arrived]==Enter){
                    enter.push(arrived);
                } else{
                    leave.push(arrived);
                }
                arrived++;
            }
            if(arrived==n && enter.empty() && leave.empty()){
                break;
            }
            if(last_state==None||last_state==Leave){
                if(!leave.empty()){
                    int c=leave.top();
                    leave.pop();
                    res[c]= t;
                    t++;
                    last_state=Leave;
                    continue;
                }
                if(!enter.empty()){
                    int c=enter.top();
                    enter.pop();
                    res[c]= t;
                    t++;
                    last_state=Enter;
                    continue;
                }
                last_state=None;
                t++;
                continue;
            }
            if(last_state==Enter){
                if(!enter.empty()){
                    int c=enter.top();
                    enter.pop();
                    res[c]= t;
                    t++;
                    last_state=Enter;
                    continue;
                }
                if(!leave.empty()){
                    int c=leave.top();
                    leave.pop();
                    res[c]= t;
                    t++;
                    last_state=Leave;
                    continue;
                }
                last_state=None;
                t++;
                continue;
            }
        }
        return res;
    }
};

int main(){
    priority_queue<int ,vector<int>,greater<int>> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.top()<<endl;
}
