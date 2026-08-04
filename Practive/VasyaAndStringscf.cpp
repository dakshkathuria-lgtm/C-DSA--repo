#include<iostream>
#include<climits>
using namespace std;

int n , k;
char ch[10003];

int solve(char x){
    int sp=0, ep=0, cnt = 0; // cnt for undesired ahracter in current window
    int maxi = INT_MIN; // maximum substring of similar charcter in all window

    for(;ep<n;ep++){
        // EXPANSION
        if(ch[ep]==x){
            // x is the undesired charcter jisko change karna hai
            cnt++;
        }

        //SHRINKING
        while(cnt > k && sp<=ep){
            if(ch[sp]==x){
                cnt--;
            }
            sp++;
        }

        //UPDATION
        if(ep-sp+1>maxi) maxi = ep -sp +1;
    }
    return maxi;
}

int main(){
    cin >> n >> k;
    cin >> ch;

    // change from a to b
    int ans1 = solve('a');
    // change from b to a
    int ans2 = solve('b');

    if(ans1>ans2) cout << ans1 << endl;
    else cout << ans2 << endl;
    return 0;
}
