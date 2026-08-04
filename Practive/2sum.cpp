#include <iostream>
using namespace std;


int main() {
  int n;
  cin >> n;

  int a[n];
  for (int i = 0; i < n; i += 1) {
    cin >> a[i];
  }
  int target;
  cin >> target;

  // APPROACH 1 - PRINT ALL PAIRS
  for (int i = 0; i < n; i += 1) {

    int key = target - a[i];
    for (int j = 0; j < n; j += 1) {
      if (i == j) {
        continue;
      }

      if (a[j] == key) {
        cout << a[i] << " " << a[j] << endl;
      }
    }
  }

  cout << endl << "--------------------------" << endl;

  //APPROACH 2 - remove idx duplicates
  for (int i = 0; i < n - 1; i += 1) {
    
    int key = target - a[i];
    for (int j = i + 1; j < n; j += 1) {

      if (a[j] == key) {
        cout << a[i] << " " << a[j] << endl;
      }
    }
  }

  // APPRACH 3- instead of finding key directly check sum
  for (int i = 0; i < n - 1; i += 1) {
    for (int j = i + 1; j < n; j += 1) {
      if (a[j] + a[i] == target) {
        cout << a[i] << " " << a[j] << endl;
      }
    }
  }

  return 0;
}