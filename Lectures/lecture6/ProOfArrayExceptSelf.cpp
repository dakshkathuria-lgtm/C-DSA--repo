#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i += 1) {
    cin >> a[i];
  }

  // Approach01 : ~n:
  // int ans = 1;
  // for (int i = 0; i < n; i += 1) {
  //   ans *= a[i];
  // }

  // for (int i = 0; i < n; i += 1) {
  //   cout << (ans / a[i]) << " ";
  // }

  // Approach02: ~n*n
  for (int i = 0; i < n; i += 1) {
    int ans = 1;
    for (int j = 0; j < n; j += 1) {
      if (i != j) {
        ans *= a[j];
      }
    }
    cout << ans << " ";
  }

  cout << endl;

  // Approach 03: ~n
  int pre[n + 1]{};

  pre[0] = 1;
  for (int i = 1; i < n; i += 1) {
    pre[i] = pre[i - 1] * a[i - 1];
  }

  int suffix[n + 1]{};

  suffix[n - 1] = 1;
  for (int i = n - 2; i >= 0; i -= 1) {
    suffix[i] = suffix[i + 1] * a[i + 1];
  }

  for (int i = 0; i < n; i++) {
    cout << pre[i] * suffix[i] << " ";
  }
}