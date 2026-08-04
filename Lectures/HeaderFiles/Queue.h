#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
#define MAX 1000

template<typename T> class Queue{
    public:
        T *a;
        int cs, ts;
        int front, back;

        Queue(){
            a = new T[MAX];
            cs = 0;
            ts = MAX;
            front = back=-1;
        }

        Queue(int size){
            a = new T[size];
            cs = 0;
            ts = size;
            front = back=-1;
        }

        void Push(T x){
            if(cs==ts){
                cout << "Queue overflow" << endl;
                return;
            }

            if(cs==0){
                front = 0;
            }

            back++;
            back%=ts;
            a[back] = x;
            cs++;
        }

        void pop(){
            if(cs==0){
                cout<< "Queue is empty"<< endl;
                return ;
            }

            if(cs==1){
                back=front=-1;
            }

            front++;
            front%=ts;
            cs--;
        }

        T front1(){
            return a[front];
        }

        bool empty(){
            if(cs==0){
                return true;
            } elsE{
                return false;
            }
        }
};
