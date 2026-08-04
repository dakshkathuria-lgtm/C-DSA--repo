#include <bits/stdc++.h>
using namespace std;

int main() {

  char ch1[100], ch2[100];
  cin >> ch1 >> ch2;
  int freq[256]{};

  // Build the freq array:
  for (int i = 0; ch1[i] != '\0'; i += 1) {
    int ce = ch1[i];
    freq[ce] += 1;
  }

  // Iterate over the second word and subtract the corresponding freq of each
  // character.
  for (int i = 0; ch2[i] != '\0'; i += 1) {
    int ce = ch2[i];
    // Subtract its freq :
    freq[ce] -= 1;
  }

  // Now my freq array should be empty;
  for (int i = 0; i < 256; i += 1) {
    if (freq[i] > 0) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

  return 0;
}