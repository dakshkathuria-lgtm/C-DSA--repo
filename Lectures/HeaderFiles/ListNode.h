#include<iostream>
#include<climits>
#include<cstring>
using namespace std;

template<typename T> class ListNode{
    public:
        T val;
        ListNode *next;

        // default constructor
        ListNode(){
            next = nullptr;
        }

        // parametrised constructor
        ListNode(T x){
            val = x;
            next = nullptr;
        }

        // Destructor
        ~ListNode(){}
};