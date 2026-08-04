#include<iostream>
using namespace std;
int main(){

    int x{10};
    char ch{'A'}; //65 store hogi that is ASCII values
    cout << ch << endl;

    char ch1;
    cin >> ch1;
    cout << (int)ch1<<endl; // explicit type casting
    return 0;
}