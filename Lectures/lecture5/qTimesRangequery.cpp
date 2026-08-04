#include <iostream>
using namespace std;
const int N = 1e5; // 1*10^5


//Computations : ~ (q*n)
int main() {

  int n;
  cin >> n;

  int a[n];
  for (int i = 0; i < n; i += 1) {
    cin >> a[i];
  }
  int q;
  cin >> q;

  // Mujhe q times kuch kaam karna hain.
  for (int i = 1; i <= q; i += 1) {
      
    int l, r;
    cin >> l >> r;

    int sum = 0;
    for (int i = l; i <= r; i++) {
      sum += a[i];
    }
    cout << sum << endl;

    
  }
}