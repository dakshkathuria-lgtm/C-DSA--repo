#include <iostream>
using namespace std;

const int y{900};

int main() {

  // y += 1; // Line number 4 vale ki baat horahi hain jo const hain.
  int x{90};
  const int y{89};

  if (true) {
    int y{90};
    y += 10;
  }

  cout << y << endl;

  return 0;
}