//
// Created by mayue on 2023/5/27.
//

#include <cstdio>
#include <set>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};


class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node *pp=p;
        Node *qq=q;
        while(true) {
            if(pp==qq){
                return pp;
            }
            if (pp->parent) {
                pp = pp->parent;
            } else {
                pp = q;
            }
            if (qq->parent) {
                qq = qq->parent;
            } else {
                qq = p;
            }
        }
        return NULL;

    }
};


//class Solution {
//public:
//    Node* lowestCommonAncestor(Node* p, Node * q) {
//        set<Node *> trace;
//        while(p){
//            trace.insert(p);
//            p=p->parent;
//        }
//        while(q){
//            if(trace.find(q)!=trace.end()){
//                return q;
//            }
//            q=q->parent;
//        }
//        return NULL;
//    }
//};