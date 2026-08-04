#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
#define MAX 1000

template<typename T> class Stack{
    public: 
        T a[MAX];
        int TopOfTheStack;

        // Default constructor
        Stack(){
            TopOfTheStack=-1;
        }

        void push(T x){
            TopOfTheStack++;
            if(TopOfTheStack==MAX){
                cout << "STack OVerflow"<< endl;
                return ;
            } 
            a[TopOfTheStack] = x;
        }

        bool empty(){
            if(TopOfTheStack==-1){
                return true;
            } else{
                return false;
            }
        }

        T top(){
            if(TopOfTheStack==-1){
                return -1;
            }

            return a[TopOfTheStack];
        }

        void pop(){
            TopOfTheStack--;
            
        }
};

