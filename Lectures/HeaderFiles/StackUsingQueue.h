#include<bits/stdc++.h>
using namespace std;

class MyStack{
    public:
        queue<int> q1;
        queue<int> q2;
        MyStack(){}

        void push(int x){
            if(!q1.empty() || q2.empty()){
                q1.push(x);
            } else{
                q2.push(x);
            }
        }

        int pop(){
            queue<int> nonemptyqueue, emptyqueue;
            

            if(q1.empty()==1){
                emptyqueue = q1;
                nonemptyqueue = q2;
            } else{
                emptyqueue = q2;
                nonemptyqueue = q1;
            }

            while(nonemptyqueue.size()>1){
                emptyqueue.push(nonemptyqueue.front());
                nonemptyqueue.pop();
            }

            int element = nonemptyqueue.front();
            nonemptyqueue.pop();
            return element;
        }

        int top(){
            queue<int>& nonemptyqueue = q1.empty() ? q2 : q1;
            queue<int>& emptyqueue = q2.empty() ? q1 : q2;

            while (nonemptyqueue.size() > 1) {
                emptyqueue.push(nonemptyqueue.front());
                nonemptyqueue.pop();
            }

            int element = nonemptyqueue.front();
            emptyqueue.push(element);
            nonemptyqueue.pop();
            return element;
        }

        bool empty(){
            if(q1.empty()&& q2.empty()){
                return true;
            } else{
                return false;
            }
        }


};