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

int main(){
    int t;
    cin >> t;

    // Computations = t*1.57*10^6 = 10^5 * 10^6
    while(t--){
        double b, c;
        cin >> b >> c;
        // double mini = LONG_MAX;
        double mini = 1e18; // f(x) ki minimum value in rnage

        // stores x ki value where f(x) is minimum
        // double value = -1; // store value of x where f(x) is minimum

        double step = 1e-6; // 0.000001;


        // LINEAR SEARCH
        for(double x = step;x<=PI/2;x+=step){
            double cfv = F(x, b, c);
            mini = min(cfv, mini);
        }

        //cout mei precision is upto 5 decimal digits
        // cout << mini << endl;
        cout << fixed << setprecision(8) << mini << endl;
    }
    return 0;
}