#include<iostream>
#include<cstring>
#include<math.h>
#include<climits>
#include<algorithm>
#include<iomanip>

using namespace std;
#define PI 3.141592

double F(double x, double b, double c){
    double ans = ((x*x)+(b*x)+c)/sin(x);
    return ans;
}

// DERIVATIVE
double F1(double x, double b, double c){
    double ans = (((2*x)+b) * (sin(x))) - ((cos(x)*((x*x)+(b*x)+c)));
    return ans;
}

int main(){
    int t;
    cin >> t;

    
    while(t--){
        double b, c;
        cin >> b >> c;
        
        // using ternary search find valye of x where f(x) is minimun
        // in rnage 0 se pie/2 and withon error 10^-6.
        double s =0, e=PI/2;
        double ans = 0;
        double error = 1e-6;
        while((e-s)>error){
            double m1 = (s+(e-s)/3);
            double m2 = (e-(e-s)/3);
            if(F(m1, b, c)<F(m2,b,c)){
                ans = m1;
                e = m2;
            } else if(F(m1, b, c)>F(m2,b,c)){
                ans = m2;
                s = m1;
            }else{
                s = m1, e=m2;
                ans - m1;
            }

        }
        cout << fixed << setprecision(8) << F(ans, b, c) << endl;
    }
    return 0;
}