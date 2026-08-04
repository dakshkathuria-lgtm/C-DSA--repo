#include <bits/stdc++.h>
using namespace std;

int main() {

  int n;
  cin >> n;

  // int c = 1;
  // int sum = 0;
  // while (c <= n) {
  //   int x;
  //   cin >> x;
  //   sum += x;
  //   cout << x << " ";

  //   c += 1;
  // }

  // cout << endl << sum << endl;
  // int sum = 0;
  // for (int c = 1; c <= n; c += 1) {
  //   char x;
  //   cin >> x;
  //   sum += x;
  //   cout << x << " ";
  // }
  // cout << endl << sum << endl;

  char x;
  while (cin >> x) {  //cin>> x return the stream intself as long as input succesful evaluate to true . When EOF is reached fail and becomes false
    cout << x << " ";
  }

  // cin does not consider/read white spaces : and reads 1 character at a time 
  // 1. spaces
  // 2. Next line.
  // char x;
  // cin.get(x);

//   while (cin.get(x)) {
//     cout << x;
//   }
//   cout << "Mayank";
  return 0;
}