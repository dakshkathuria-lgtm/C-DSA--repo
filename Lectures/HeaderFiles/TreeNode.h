#include<bits/stdc++.h>
using namespace std;

template<typename T> class TreeNode{
    public:
        T val;
        TreeNode* left; // apne hi jaise ek aur ka adrress sotre kar rhe honge
        TreeNode* right;

        TreeNode(){
            left = nullptr;
            right = nullptr;
        }

        TreeNode(T x){
            val = x;
            left = nullptr;
            right = nullptr;
        }

        ~ListNode(){}
};