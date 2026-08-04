#include <iostream>
using namespace std;
const int N = 1e5; // 1*10^5

int main() {

  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i += 1) {
    cin >> a[i];
  }

  int sum = 0;

  for (int i = 0; i < n; i += 1) {
    sum += a[i];
  }

  cout << sum << endl;
}