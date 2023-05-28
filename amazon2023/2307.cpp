#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

// 试下并查集
struct V {
    V(const string &b, double f) {
        base = b;
        factor = f;
    }

    string base;
    double factor;
};

V *get_v(unordered_map<string, V *> &m, const string &key) {
    auto iter = m.find(key);
    V *v = NULL;
    if (iter == m.end()) {
        v = new V(key, 1);
        m[key] = v;
        return v;
    }
    v = iter->second;
    if (v->base == key) {
        return v;
    }
    V *p = get_v(m, v->base);
    if (v->base != p->base) {
        v->base = p->base;
        v->factor = p->factor * v->factor;
    }
    return v;
}

class Solution {
public:
    bool checkContradictions(vector<vector<string>> &equations, vector<double> &values) {
        int n = equations.size();
        unordered_map<string, V *> m;
        for (int i = 0; i < n; i++) {
            string &x = equations[i][0];
            string &y = equations[i][1];
            double r = values[i];
            V* vx=get_v(m,x);
            V* vy=get_v(m,y);
            if(vx->base==vy->base){
                double r_should = vx->factor / vy->factor;
                if (abs(r_should - r) > 1e-5) {
                    return true;
                }
            } else{
                V * bx=get_v(m,vx->base);
                bx->base=y;
                bx->factor=r/vx->factor;
            }
        }
        return false;
    }
};
int main(){

    vector<vector<string>> equations= {{"a","b"},{"b","c"},{"a","c"}};
    vector<double> values={3,0.5,1.5};
    Solution s;
    cout<<s.checkContradictions(equations,values)<<endl;
    return 0;
}