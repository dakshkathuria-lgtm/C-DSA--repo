#include<iostream>
using namespace std;
const int N = 102;

int n , k;
int taste[N]{};
int calorie[N]{};

// F(x,s): max taste by choosing some fruits from x to n-1 where contirbuitn of chosen fruits is s

int F(int x, int s){
    //stopping point
    if(x==n){
        if(s==0){
            return 0; // abtak ka taste isse pehle vaala state ka mere paas 
                      //already hai and am saying that cause of this current 
                      //state aap abtak ke tatse mei 0 add kardo
        } else{
            return -1e9;
        }
    }


    // CURRENT STATE F(x,s)

    int op1 = taste[x] + F(x+1, s+(taste[x] - (k*calorie[x])));


    int op2 = 0 + F(x+1, s);

    int ans = max(op1, op2);
    return ans;

}



int main(){
    cin >> n >> k;

    for(int i =0;i<n;i++){
        cin >> taste[i];
    }

    for(int i =0;i<n;i++){
        cin >> calorie[i];
    }


    // Starting poitn

    int ans = F(0,0);
    if(ans < 0){
        cout << -1 << endl;
    }

    cout << ans << endl;
    return 0;
}