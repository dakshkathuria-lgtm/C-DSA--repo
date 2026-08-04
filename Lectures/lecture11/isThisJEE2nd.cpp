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

    
    while(t--){
        double b, c;
        cin >> b >> c;
        
        // using binary search find valye of x where f(x) is minimun
        // in rnage 0 se pie/2 and withon error 10^-6.
        double s =0, e=PI/2;
        int cnt = 0;
        double ans = 0;
        double error = 1e-6;
        while(s<=e){
            double mid = (s+e)/2;
            if(F(mid, b, c)<F(mid+error, b, c)){
                ans = mid;
                e = mid;
            } else{
                ans = mid;
                s = mid;
            }

            cnt+=1;
            if(cnt>60){
                break;
            }
        }
        cout << fixed << setprecision(8) << F(ans, b, c) << endl;
    }
    return 0;
}