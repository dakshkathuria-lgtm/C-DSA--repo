#include<iostream>
#include<algorithm>
#include<climits>
#include<iomanip> // set precision functino can be used
using namespace std;
int main(){ 
    double a =43.45678;
    // storing ke liye set percision use nhi hota
    cout << setprecision(5) << a << endl;
    // decimal point 4 aane chaiye
    cout << fixed << setprecision(4) << a << endl;

    return 0;   
}