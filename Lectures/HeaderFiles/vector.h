#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

template <typename T> class Vector{
    // Data Members: 
    public:
        T *a;
        int ts;
        int cs;

        // default constructor
        Vector(){
            ts=1;
            cs=0;
            a = new T[ts];
        }

        // parameterised constructor
        Vector(int size){
            ts = size;
            cs = 0;
            a = new T[ts];
        }

        void push_back(T x){
            // wht if the size of the vector/mera internal dynamic array is full?
            // u double it size
            // aapko ek new dynamic array banana padega and us snew dynamic array mei saara 
            // ka saara purana content copy krna padega

            if(ts==cs){
                T *b = a; // now my both ptrs are pointing to same array
                a = new T [ts*2];

                // copy contnet from b to a
                for(int i =0;i<ts;i++){
                    a[i] = b[i];
                }

                ts = 2*ts;
                delete[] b; // as in to prevent memory leakx
            }   

            a[cs] = x;
            cs++;
            return;
        }

        int size(){
            return cs;
        }

        int capacity(){
            return ts;
        }

        T front(){
            return a[0];
        }

        T back(){
            return a[cs-1];
        }

        // insetad of deleting we remove the access of the user from this box 
        // user ke liye vector mei elements are from 0 to cs matlab user can access from element from 0 to cs 
        // since mai delete nhi karsakta usa ka last access last element remove kar dunga
        void pop_back(){ 
            cs--;
            return;
        }

        // operator overloading for this box as we want value of index this is ritten inside the box
        T operator[](int index){ return a[index];}


};