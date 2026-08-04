#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
const int N=1e5 + 3;
int height[N]{};
int n;

int F(int x){

    if(x==n){
        return 0;
    }

    int Op1 = F(x + 1) + abs(height[x] - height[x + 1]);
    // THis ensures you are never going out of bound.
    // Main 2 kadam ka jump leraha hu.
    int Op2 = INT_MAX;
    if (x + 2 <= n) {
      Op2 = F(x + 2) + abs(height[x] - height[x + 2]);
    }

    int ans = min(Op1, Op2); // Current state ka answer is stored in ans.
    return ans;
}

int main(){
cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> height[i];
  }

  // Starting Point :
  int ans = F(1);
  cout << ans << endl;

  // Starting Point:
//   cout << F1(n) << endl;

    return 0;
}