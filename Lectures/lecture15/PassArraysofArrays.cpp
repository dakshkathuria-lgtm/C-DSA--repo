#include<iostream>
using namespace std;


void Solve(int a[][6]){
    
}

int main(){

    // int multidimesional static arrays: sizes are must, atleast last n-1 
    // dimensions ka size dena hi padega
    int a[5][6]{
        {3,2,1,5,6},
        {3,2,1,5},
        {5,3,7,1,8},
    };

    // mutlidimensional arrays ki baat ho: toh aap har baar pass by address hi karoge
    Solve(a);
    cout << a+1 << endl;

    cout << *(a+1) << endl;
    cout << &a[1] << endl;


    return 0;
}